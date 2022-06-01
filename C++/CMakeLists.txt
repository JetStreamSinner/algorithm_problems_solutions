project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        leetcode/check_if_n_and_its_double_exist.h)

add_executable(${PROJECT_NAME} ${src})
