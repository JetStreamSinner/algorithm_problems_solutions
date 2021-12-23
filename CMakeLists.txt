project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/find_numbers_with_even_numbers_of_digits.h)

add_executable(${PROJECT_NAME} ${src})
