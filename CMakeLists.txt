cmake_minimum_required(VERSION 3.24)
project(t7tp1)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)
add_executable(t7tp1_run ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)
target_link_libraries(t7tp1_run t7tp1_src)

add_subdirectory(test)
