cmake_minimum_required(VERSION 3.28)  # Latest today is 3.29.3
project(cmake_demo VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE HEADERS "src/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release")
add_executable(cmake_demo "${HEADERS}" "${SOURCES}")

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

add_compile_definitions(RES_PATH="${CMAKE_SOURCE_DIR}/res")
add_compile_definitions(LOGS_PATH="${CMAKE_SOURCE_DIR}/logs")