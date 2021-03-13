message("----------------------------------------------------------")

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#project(VulkanViewer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#enable_testing()

#------------------ GLFW
#set(CMAKE_OSX_ARCHITECTURES arm64 x86_64)
#message("${CMAKE_OSX_ARCHITECTURES}")
set (M_SRC_DIR ${PROJECT_SOURCE_DIR}/src/)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(module/glfw)
add_subdirectory(module/glm)
#add_subdirectory(module/Vulkan-Hpp)
#add_subdirectory(module/Vulkan-Headers)

#include_directories(external/)
#include_directories(include/)


add_subdirectory(src)
add_subdirectory(app)
#add_subdirectory(test)
