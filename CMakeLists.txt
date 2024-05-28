cmake_minimum_required(VERSION 3.20)

project(snake)

enable_testing()

include(FetchContent)
include(${CMAKE_SOURCE_DIR}/cmake/AddCatch2.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/raylib.cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

add_executable(snake main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE deque)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_subdirectory(test)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()
