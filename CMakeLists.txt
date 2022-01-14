project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        codewars/split_strings.h)

add_executable(${PROJECT_NAME} ${src})
