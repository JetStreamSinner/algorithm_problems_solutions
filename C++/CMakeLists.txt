project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/find_all_numbers_disappeared_in_array.h)

add_executable(${PROJECT_NAME} ${src})
