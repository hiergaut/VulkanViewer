cmake_minimum_required(VERSION 3.5)
#cmake_minimum_required(VERSION 3.5)

#project(VulkanViewer VERSION 1.0 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(VulkanViewer main.cpp)

find_package(Vulkan REQUIRED)
if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Failed to locate Vulkan SDK")
else()
    message(STATUS "Vulkan include dirs : ${Vulkan_INCLUDE_DIRS}")
    message(STATUS "Vulkan lib : ${Vulkan_LIBRARIES}")
endif()
#find_package(glfw REQUIRED)
#find_package(glm REQUIRED)

file(GLOB SOURCES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
#target_link_libraries(${PROJECT_NAME} PRIVATE ${VULKAN_LIB_LIST})
#target_link_libraries(${PROJECT_NAME} PRIVATE vulkan)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES})
