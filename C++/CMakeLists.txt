project(Tasks)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp
        utils/pretty_print.h
        custom/knapsack.h)

add_executable(${PROJECT_NAME} ${src})
