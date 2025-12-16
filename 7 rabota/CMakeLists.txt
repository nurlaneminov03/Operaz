cmake_minimum_required(VERSION 3.10)

project(pr7 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_executable(pr7
    src/main.c
    src/users.c
    src/processes.c
    src/help.c
)
