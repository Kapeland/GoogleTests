include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../src/)

add_executable(runSomeTests basic_test.cpp StringFixture.cpp)

target_link_libraries(runSomeTests gtest gtest_main gmock gmock_main src)

