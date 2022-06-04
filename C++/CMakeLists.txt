project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/binary_tree_level_order_traversal.h)

add_executable(${PROJECT_NAME} ${src})
