cmake_minimum_required(VERSION 3.28)
project(cmake_demo VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE HEADERS "src/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release")
add_executable(cmake_demo "${HEADERS}" "${SOURCES}")

target_compile_options(cmake_demo PRIVATE
    -Wall -Wextra -pedantic
    $<$<CONFIG:DEBUG>:-g>
    $<$<CONFIG:RELEASE>:-O3>
    $<$<CONFIG:RELWITHDEBINFO>:-O2 -g>
    $<$<CONFIG:MINSIZEREL>:-Os>
)

add_compile_definitions(FLAG_MACRO)
add_compile_definitions(VALUE_MACRO=123)
add_compile_definitions(STRING_MACRO="123")

add_compile_definitions(RES_PATH="${CMAKE_SOURCE_DIR}/res")
add_compile_definitions(LOGS_PATH="${CMAKE_SOURCE_DIR}/logs")

find_package(Boost REQUIRED COMPONENTS date_time)
include_directories("${Boost_INCLUDE_DIRS}")
target_link_libraries(cmake_demo "${Boost_LIBRARIES}")