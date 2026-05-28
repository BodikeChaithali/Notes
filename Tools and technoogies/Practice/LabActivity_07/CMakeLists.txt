cmake_minimum_required(VERSION 3.22.1)
project(My_project C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -I.}")
include_directories(${CMAKE_SOURCE_DIR})
add_executable(pallindrome_checks
	pallindrome.h
	pallindrome.c
	main.c
	)
