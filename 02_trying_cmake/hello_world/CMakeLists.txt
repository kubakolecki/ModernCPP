cmake_minimum_required(VERSION 4.1.0)
project(hello_world VERSION 1.0.0)

add_executable(hello_world
hello_world.cpp)

target_link_libraries(hello_world PRIVATE stdc++exp)

set_property(TARGET hello_world PROPERTY CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
