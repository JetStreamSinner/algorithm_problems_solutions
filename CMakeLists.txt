project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(src main.cpp  balance_parentheses.h find_first_and_last_position.h generate_parentheses.h)

add_executable(${PROJECT_NAME} ${src})
