cmake_minimum_required(VERSION 3.15)
project(string C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c Product.c Product.h Product_List.c Product_List.h Request_String.c Request_String.h)
