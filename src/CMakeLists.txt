project(src)

set(HEADER_FILES
    MyString.h
    )

set(SOURCE_FILES
    MyString.cpp
    )

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
