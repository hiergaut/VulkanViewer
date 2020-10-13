#cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#cmake_minimum_required(VERSION 3.5)

#project(VulkanViewer VERSION 1.0 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(VulkanViewer main.cpp)

# ----------------------- VULKAN
#references: https://github.com/SaschaWillems/Vulkan/blob/master/CMakeLists.txt
#Use FindVulkan module added with CMAKE 3.7
#set(CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY False)
#if (NOT CMAKE_VERSION VERSION_LESS 3.7.0)
#        message(STATUS "Using module to find Vulkan")
#        find_package(Vulkan REQUIRED NO_CMAKE_PACKAGE_REGISTRY )
##        find_package(Vulkan REQUIRED)
#endif()

IF(UNIX AND NOT APPLE)
        set(LINUX TRUE)
ENDIF()

IF(WIN32)
        IF (NOT Vulkan_FOUND)
                find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/libs/vulkan)
                IF (Vulkan_LIBRARY)
                        set(Vulkan_FOUND ON)
                        MESSAGE("Using bundled Vulkan library version")
                ENDIF()
        ENDIF()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
ELSEIF(LINUX)
        IF (NOT Vulkan_FOUND)
#	    message("$ENV{VULKAN_SDK}")
#                find_library(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/libs/vulkan" REQUIRED)
                find_library(Vulkan_LIBRARY NAMES vulkan HINTS "${CMAKE_SOURCE_DIR}/lib/" REQUIRED NO_DEFAULT_PATH)
                message(${Vulkan_LIBRARY})
                IF (Vulkan_LIBRARY)
                        set(Vulkan_FOUND ON)
                        MESSAGE("Using bundled Vulkan library version")
                ENDIF()
        ENDIF()
#	find_package(Threads REQUIRED)
ELSEIF(APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_MACOS_MVK -DVK_EXAMPLE_XCODE_GENERATED")
ENDIF(WIN32)


IF (NOT Vulkan_FOUND)
        message(FATAL_ERROR "Could not find Vulkan library!")
ELSE()
        message(STATUS "Vulkan include dirs : ${Vulkan_INCLUDE_DIRS}")
        message(STATUS "Vulkan lib : ${Vulkan_LIBRARIES}")
#        message(STATUS ${Vulkan_LIBRARY})
ENDIF()



#find_package(glfw REQUIRED)
#find_package(glm REQUIRED)
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)

file(GLOB SOURCES *.cpp *.h *.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})

#target_include_directories(${PROJECT_NAME} PUBLIC
#    ${FUCK}
#    )
#include_directories(${FUCK})
#target_include_directories(${PROJECT_NAME} ${FUCK})


target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
#target_link_libraries(${PROJECT_NAME} PRIVATE ${VULKAN_LIB_LIST})
#target_link_libraries(${PROJECT_NAME} PRIVATE vulkan)
#target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARY})
#target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Headers)
#target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
