project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/replace_elements_with_greatest_element_on_right_side.h)

add_executable(${PROJECT_NAME} ${src})
