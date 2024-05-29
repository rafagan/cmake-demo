cmake_minimum_required(VERSION 3.28)  # Latest today is 3.29.3
project(cmake_demo VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_BUILD_TYPE Release)

add_executable(cmake_demo main.cpp)

## Compilation flags
target_compile_options(cmake_demo PRIVATE # (PRIVATE, PUBLIC, INTERFACE)
    -Wall -Wextra -pedantic
    $<$<CONFIG:DEBUG>:-g>
    $<$<CONFIG:RELEASE>:-O3>
    $<$<CONFIG:RELWITHDEBINFO>:-O2 -g>
    $<$<CONFIG:MINSIZEREL>:-Os>
)

# Similar to target_compile_options but default is PUBLIC
add_compile_definitions(FLAG_MACRO)
add_compile_definitions(VALUE_MACRO=123)
add_compile_definitions(STRING_MACRO="123")