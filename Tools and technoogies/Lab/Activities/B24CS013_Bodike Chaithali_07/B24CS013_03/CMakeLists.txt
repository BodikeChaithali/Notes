cmake_minimum_required(VERSION 3.10)

project(pallindrome_check C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        main.c
        pallindrome.c
)
add_executable(pallindrome_check ${SOURCES})

target_include_directories(pallindrome_check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

