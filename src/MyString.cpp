#include "MyString.h"

void MyString::assign(const MyString &s){
  if (capacity_ < s.size_){ // make sure that quantity of memory is not enough.
	delete[] str_;
	str_ = new char[s.size_];
	capacity_ = s.size_;
  }
  size_ = s.size_;

  for (size_t i = 0; i < size_; ++i){
	str_[i] = s.str_[i];
  }
}

void MyString::clear(){
  for (size_t i = 0; i < size_; ++i){
	str_[i] = '\0';
  }
  size_ = 0;
}

void MyString::insertError(const size_t index) const{
  if (index > capacity_){
	std::cerr << "Please insert correct index. Insert function." << std::endl;
	::exit(EXIT_FAILURE);
  }
}

const char *MyString::c_str() const{
  auto tmp_str = new char[size_ + 1];

  for (int i = 0; i < size_; ++i){
	tmp_str[i] = str_[i];
  }
  tmp_str[size_] = '\0';
  return const_cast<const char *>(tmp_str);
}

MyString::MyString(const MyString &s) : str_(new char[s.capacity_]), size_(s.size_), capacity_(s.capacity_){
  ::memset(str_, 0, capacity_);
  ::memcpy(str_, s.str_, s.size_);
}

MyString &MyString::operator=(const MyString &s){
  this->assign(s);
  return *this;
}

MyString &MyString::operator=(const char *arr){
  MyString new_s(arr);
  this->assign(new_s);
  return *this;
}

MyString &MyString::operator=(const std::string &s){
  MyString new_s(s);
  this->assign(new_s);
  return *this;
}

MyString &MyString::operator=(const char &ch){
  MyString new_s(1, ch);
  this->assign(new_s);
  return *this;
}

MyString &MyString::operator+=(const MyString &s){
  if (capacity_ < size_ + s.size_){
	MyString prev_s = *this;
	delete[] str_;
	capacity_ = size_ + s.size_;
	str_ = new char[capacity_];
	::memcpy(str_, prev_s.str_, prev_s.size_);
  }
  ::memcpy(str_ + size_, s.c_str(), s.size_);
  size_ += s.size_;
  return *this;
}

MyString &MyString::operator+=(const std::string &s){
  MyString parameter_s(s);
  *this += parameter_s;
  return *this;
}

MyString &MyString::operator+=(const char &ch){
  MyString parameter_s(1, ch);
  *this += parameter_s;
  return *this;
}

MyString &MyString::operator+=(const char *arr){
  MyString parameter_s(arr);
  *this += parameter_s;
  return *this;
}

MyString operator+(const MyString &s1, const MyString &s2){
  MyString tmp_s = s1;
  tmp_s += s2;
  return tmp_s;
}

std::ostream &operator<<(std::ostream &out, const MyString &s){
  size_t tmp_s_size = s.size();
  for (size_t i = 0; i < tmp_s_size; ++i){
	out << s[i];
  }
  return out;
}

std::istream &operator>>(std::istream &in, MyString &s){
  s.size_ = 0;
  char ch = 0;
  while (true){
	::scanf("%c", &ch);
	if (ch == '\0' || ch == '\n'){
	  break;
	}
	s += ch;
  }
  return in;
}

bool operator==(const MyString &s1, const MyString &s2){
  if (&s1 == &s2){
	return true;
  }
  if (s1.size_ != s2.size_){
	return false;
  }
  for (int i = 0; i < s1.size_; ++i){
	if (s1[i] != s2[i]){
	  return false;
	}
  }
  return true;
}

bool operator!=(const MyString &s1, const MyString &s2){
  return !(s1 == s2);
}

bool operator<(const MyString &s1, const MyString &s2){
  if (s1 == s2){
	return false;
  }
  size_t stop_cond = std::min(s1.size_, s2.size_);
  for (size_t i = 0; i < stop_cond; ++i){
	if (s1[i] == s2[i]){
	  continue;
	}
	if (s1[i] < s2[i]){
	  return true;
	}else{
	  return false;
	}
  }
  if (s1.size_ < s2.size_){
	return true;
  }else{
	return false;
  }
}

bool operator>=(const MyString &s1, const MyString &s2){
  return !(s1 < s2);
}

bool operator>(const MyString &s1, const MyString &s2){
  return s1 >= s2 && s1 != s2;
}

bool operator<=(const MyString &s1, const MyString &s2){

  return !(s1 > s2);
}

MyString &MyString::insert(const size_t index, const unsigned int count, const char ch){
  insertError(index);

  MyString tmp_s;
  tmp_s += MyString(str_, index);
  tmp_s += MyString(count, ch);
  tmp_s += MyString(str_ + index);

  *this = tmp_s;
  return *this;
}

MyString &MyString::insert(const size_t index, const char *arr, const unsigned int count){
  insertError(index);

  MyString tmp_s;
  tmp_s += MyString(str_, index);
  tmp_s += MyString(arr, count);
  tmp_s += MyString(str_ + index);

  *this = tmp_s;
  return *this;
}

MyString &MyString::insert(const size_t index, const char *arr){
  return insert(index, arr, ::strlen(arr));
}

MyString &MyString::insert(const size_t index, const std::string &str, const unsigned int count){
  return insert(index, str.c_str(), count);
}

MyString &MyString::insert(const size_t index, const std::string &str){
  return insert(index, str, str.length());
}

MyString &MyString::erase(size_t index, unsigned int count){
  if (size_ == 0){
	std::cerr << "Length is already zero." << std::endl;
	::exit(EXIT_FAILURE);
  }
  if (count > size_){
	std::cerr << "Please input correct number of characters." << std::endl;
	::exit(EXIT_FAILURE);
  }
  if (index >= size_){
	std::cerr << "Please input correct index." << std::endl;
	::exit(EXIT_FAILURE);
  }
  if (index < size_ && index + count >= size_){
	::memset(str_ + index, '\0', size_ - index);
	size_ -= (size_ - index);
  }else{
	::memcpy(str_ + index, str_ + index + count, size_ - index - count);
	size_ -= count;
	::memset(str_ + size_, '\0', count);
  }
  return *this;
}

void MyString::shrink_to_fit(){
  auto *tmp_str = new char[size_];
  ::memcpy(tmp_str, str_, size_);
  delete[]str_;
  str_ = new char[size_];
  capacity_ = size_;
  ::memcpy(str_, tmp_str, size_);
}

MyString &MyString::append(const unsigned int count, const char ch){
  *this += MyString(count, ch);
  return *this;
}

MyString &MyString::append(const char *arr, size_t index, unsigned int count){
  if (count == (unsigned int)(-1) && index != npos){
	std::cerr << "Please enter 1 or 3 parameters. Append function." << std::endl;
	::exit(EXIT_FAILURE);
  }
  if (index == npos){
	index = 0;
  }

  if (index >= ::strlen(arr)){
	std::cerr << "Index out of range. Append function." << std::endl;
	::exit(EXIT_FAILURE);
  }

  if (count > ::strlen(arr) - index){
	count = ::strlen(arr) - index;
  }
  if (count == (unsigned int)(-1)){
	count = ::strlen(arr);
  }

  *this += MyString(arr + index, count);
  return *this;
}

MyString &MyString::append(const std::string &s, size_t index, unsigned int count){
  return append(s.c_str(), index, count);
}

template <class str>
MyString &MyString::replace(const size_t index, const unsigned int count, str s){
  erase(index, count);

  MyString tmp_s(s);
  MyString tmp_this_l(str_ + index, size_ - index);
  MyString tmp_this_f(str_, index);

  *this = tmp_this_f;
  *this += tmp_s;
  *this += tmp_this_l;

  return *this;
}

template MyString &MyString::replace<std::string>(const size_t, const unsigned int, std::string);

template MyString &MyString::replace<const char *>(const size_t, const unsigned int, const char *);

MyString MyString::substr(const size_t index) const{
  MyString tmp_s(str_ + index, size_ - index);
  return tmp_s;
}

MyString MyString::substr(const size_t index, const unsigned int count) const{
  MyString tmp_s(MyString(str_ + index, size_ - index).str_, count);

  return tmp_s;
}

template <class str>
size_t MyString::find(str s, size_t index) const{
  MyString tmp_s(s);
  for (size_t i = index; i < size_; ++i){
	if (substr(i, tmp_s.size_) == tmp_s){
	  return i;
	}
  }
  return npos;
}

template size_t MyString::find<std::string>(std::string, const size_t) const;

template size_t MyString::find<const char *>(const char *, const size_t) const;
