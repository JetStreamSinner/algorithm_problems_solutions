project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        codewars/the_vowel_code.h)

add_executable(${PROJECT_NAME} ${src})
