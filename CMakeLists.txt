cmake_minimum_required(VERSION 3.20)

project(snake)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

add_executable(snake main.cpp)
target_link_libraries(snake PRIVATE deque)

add_subdirectory(test)
