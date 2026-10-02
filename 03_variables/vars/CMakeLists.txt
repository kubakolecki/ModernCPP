cmake_minimum_required(VERSION 4.1.0)
project(variables VERSION 1.0.0)

add_executable(variables_intro
01_variables_intro.cpp)

add_executable(pointers
02_pointers_and_references.cpp)

add_executable(auto
03_auto_variables.cpp)

add_executable(structures
04_structures.cpp)

add_executable(limits
05_limits.cpp)

target_compile_options(variables_intro PRIVATE -Wall -Wextra -Wfloat-conversion)
target_compile_options(pointers PRIVATE -Wall -Wextra -Wfloat-conversion)
target_compile_options(auto PRIVATE -Wall -Wextra -Wfloat-conversion)
target_compile_options(structures PRIVATE -Wall -Wextra -Wfloat-conversion)
target_compile_options(limits PRIVATE -Wall -Wextra -Wfloat-conversion)

set_property(TARGET variables_intro PROPERTY CXX_STANDARD 23)
set_property(TARGET pointers PROPERTY CXX_STANDARD 23)
set_property(TARGET auto PROPERTY CXX_STANDARD 23)
set_property(TARGET structures PROPERTY CXX_STANDARD 23)
set_property(TARGET limits PROPERTY CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
