project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/populating_next_right_pointers_in_each_node.h)

add_executable(${PROJECT_NAME} ${src})
