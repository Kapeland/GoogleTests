#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <algorithm>
#include <cstring>

class MyString {
  friend std::istream &operator>>(std::istream &in, MyString &s);
  friend bool operator==(const MyString &, const MyString &);
  friend bool operator!=(const MyString &, const MyString &);
  friend bool operator<(const MyString &, const MyString &);
  friend bool operator>=(const MyString &, const MyString &);
  friend bool operator>(const MyString &, const MyString &);
  friend bool operator<=(const MyString &, const MyString &);

  char *str_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
  static const size_t npos = -1;

  void assign(const MyString &);
  void insertError(size_t) const;

 public:
  inline size_t size() const { return size_; }
  inline size_t length() const { return size_; }
  inline size_t capacity() const { return capacity_; }
  inline bool empty() const { return size_ == 0; }
  inline char *data() const { return str_; }
  const char *c_str() const;
  void clear();
  void shrink_to_fit();

  MyString &insert(size_t, unsigned int, char); // insert count of char in index position
  MyString &insert(size_t, const char *); // insert null-terminated char string at index position
  MyString &insert(size_t, const char *, unsigned int); // insert count of null-terminated char string at index position
  MyString &insert(size_t, const std::string &); // insert std::string at index position
  MyString &insert(size_t, const std::string &, unsigned int); // insert count of std::string at index position

  MyString &erase(size_t, unsigned int); // erase count of char at index position

  MyString &append(unsigned int, char); // append count of char
  MyString &append(const char *,
                   size_t = npos,
                   unsigned int = -1); // append a count of null-terminated char string by index position
  MyString &append(const std::string &,
                   size_t = npos,
                   unsigned int = -1); // append a count of std:: string by index position



  // replace a count of char at index by “string”
  template<class str>
  MyString &replace(size_t, unsigned int, str);

  MyString substr(size_t idx) const; // return a substring starts with index position
  MyString substr(size_t idx, unsigned int cnt) const; // return a count of substring’s char starts with index position

  // if founded return the index of substring
  template<class str>
  size_t find(str s, size_t = 0) const;

  inline char &operator[](size_t index) { return str_[index]; }
  inline char operator[](size_t index) const { return str_[index]; }

  MyString &operator=(const MyString &);
  MyString &operator=(const char *);
  MyString &operator=(const std::string &);
  MyString &operator=(const char &);

  MyString &operator+=(const MyString &);
  MyString &operator+=(const std::string &);
  MyString &operator+=(const char &);
  MyString &operator+=(const char *);

  MyString() = default; // Default constructor.
  MyString(const MyString &s); // Copy constructor.
  MyString(const char *s, size_t size) : str_(new char[size]), size_(size), capacity_(size) {
    ::memcpy(str_, s, size);
  } // Init class with count characters of “char string”.
  MyString(const char *str) : MyString(str, ::strlen(str)) {} // Constructor from a char array.
  MyString(const ::std::string &str) : MyString(str.c_str(), str.length()) {} // std::string constructor.
  MyString(size_t size, const char ch) : str_(new char[size]), size_(size), capacity_(size) {
    ::memset(str_, ch, size_);
  } // Init class with count of characters.
  MyString(const std::initializer_list<char> &lst)
      : str_(new char[lst.size()]), size_(lst.size()), capacity_(lst.size()) {
    std::copy(lst.begin(), lst.end(), str_);
  } // Initializer list constructor.

  inline ~MyString() { delete[]str_; } // Destructor.
};

std::ostream &operator<<(std::ostream &, const MyString &);
std::istream &operator>>(std::istream &, MyString &);
MyString operator+(const MyString &, const MyString &);
bool operator==(const MyString &, const MyString &);
bool operator!=(const MyString &, const MyString &);
bool operator<(const MyString &, const MyString &);
bool operator>=(const MyString &, const MyString &);
bool operator>(const MyString &, const MyString &);
bool operator<=(const MyString &, const MyString &);

#endif //_MYSTRING_H
