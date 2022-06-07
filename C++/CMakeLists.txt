project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/consturct_binary_tree_from_inorder_and_postorder_traversal.h)

add_executable(${PROJECT_NAME} ${src})
