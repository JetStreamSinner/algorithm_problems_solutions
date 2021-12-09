project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        convert_1d_array_into_2d_array.h)

add_executable(${PROJECT_NAME} ${src})
