cmake_minimum_required(VERSION 3.28)  # Latest today is 3.29.3
project(cmake_demo VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(cmake_demo main.cpp)

## Compilation flags

# -Wall -Wextra: extra warning infos
# -pedantic: warn best C++ development patterns
# PRIVATE: Apply only to cmake_demo
target_compile_options(cmake_demo PRIVATE -Wall -Wextra -pedantic)

# $<...>: Conditional generator expression. $<xxx:-g> will apply -g if xxx is true, else empty string
# $<CONFIG:DEBUG>: 1 if CONFIG is DEBUG else 0
# -g: Adds additional info into compiled code for debugging purposes
target_compile_options(cmake_demo PRIVATE $<$<CONFIG:DEBUG>:-g>)

# Example flags for code optimization: -00, -01, -02, -03, -0s, -0z, -0fast
target_compile_options(cmake_demo PRIVATE $<$<CONFIG:RELEASE>:-O3>)

# Build flag for RelWithDebInfo (Release With Debug Info) compilations
target_compile_options(cmake_demo PRIVATE $<$<CONFIG:RELWITHDEBINFO>:-O2 -g>)

# Build flag for MinSizeRel (Minimum Size Release) compilations
target_compile_options(cmake_demo PRIVATE $<$<CONFIG:MINSIZEREL>:-Os>)

# Possible truth values: 1. ON, YES, TRUE
if(NO)
    message("TRUE")
else()
    message("FALSE")
endif()