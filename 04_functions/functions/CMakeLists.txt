cmake_minimum_required(VERSION 4.1.0)
project(functions VERSION 1.0.0)

add_executable(functions_intro
01_functions_intro.cpp)

add_executable(expected_demo
02_expected.cpp)

add_executable(tri
03_cli_example.cpp)

add_executable(area_demo
04_functors.cpp)

add_executable(planets
05_library.cpp
planet_models.cpp)

add_executable(planets_new
06_namespaces.cpp
planet.cpp)

add_executable(factorial
07_factorial.cpp)

add_executable(contracts_demo
08_contracts.cpp)
target_link_libraries(contracts_demo PRIVATE stdc++exp)

target_compile_options(functions_intro PRIVATE -Wall -Wextra -Wfloat-conversion)
target_compile_options(contracts_demo PRIVATE -fcontracts)
#enforce, ignore, observe, quick_enforce
target_compile_options(contracts_demo PRIVATE -fcontract-evaluation-semantic=observe)
set_property(TARGET functions_intro PROPERTY CXX_STANDARD 23)
set_property(TARGET expected_demo PROPERTY CXX_STANDARD 23)
set_property(TARGET tri PROPERTY CXX_STANDARD 23)
set_property(TARGET area_demo PROPERTY CXX_STANDARD 23)
set_property(TARGET planets PROPERTY CXX_STANDARD 23)
set_property(TARGET factorial PROPERTY CXX_STANDARD 23)
set_property(TARGET contracts_demo PROPERTY CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

