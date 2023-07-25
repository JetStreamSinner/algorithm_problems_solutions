project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/longest_substring_without_repeating_characters.h)

add_executable(${PROJECT_NAME} ${src})
