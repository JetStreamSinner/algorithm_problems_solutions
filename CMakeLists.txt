project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        combination_sum.h)

add_executable(${PROJECT_NAME} ${src})
