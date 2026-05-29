cmake_minimum_required(VERSION 3.16)

project(CrossPlatformRenderer)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(ext/glfw)

add_library(glad ext/glad/glad.c)
target_include_directories(glad PUBLIC ext/glad/)

add_executable(GLFWTest src/main.cpp)
target_include_directories(GLFWTest PRIVATE ext/glad/)
target_link_libraries(GLFWTest PRIVATE glfw glad)