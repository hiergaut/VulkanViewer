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
#        find_package(Vulkan REQUIRED)
#endif()

IF(UNIX AND NOT APPLE)
        #for Linux, BSD, Solaris, Minix
        set(LINUX TRUE)
ENDIF()

#message("CMAKE_CL_64: '${CMAKE_CL_64}'")
#unset(Vulkan_INCLUDE_DIRS)
#unset(Vulkan_LIBRARIES)
#unset(Vulkan_FOUND)
#unset(Vulkan_LIBRARY CACHE)

#message(STATUS "Vulkan_INCLUDE_DIRS : ${Vulkan_INCLUDE_DIRS}")
#message(STATUS "Vulkan_LIBRARIES : ${Vulkan_LIBRARIES}")
#message(STATUS "Vulkan_LIBRARY : ${Vulkan_LIBRARY}")

find_package(Vulkan)

if(NOT Vulkan_FOUND)
#if(NOT TRUE)
    message(STATUS "Could not find Vulkan library on system!")

    IF(WIN32)
    #if(MSVC OR MSYS OR MINGW) #Windows compilers
            IF (NOT Vulkan_FOUND)
                    if (CMAKE_CL_64)
                            find_library(Vulkan_LIBRARIES NAMES vulkan-1.2.154.1 vulkan PATHS ${CMAKE_SOURCE_DIR}/usr/lib/)
                    else()
                            find_library(Vulkan_LIBRARIES NAMES vulkan-1.2.154.1 vulkan PATHS ${CMAKE_SOURCE_DIR}/usr/lib32/)
                    endif()

                    IF (Vulkan_LIBRARIES)
                            set(Vulkan_FOUND TRUE)
                            set(Vulkan_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/module/Vulkan-Headers/include/")
							MESSAGE(STATUS "Using bundled Vulkan library version")
                    ENDIF()
            ENDIF()
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
    ELSEIF(LINUX)
			message(FATAL_ERROR "Please install vulkan on your system !")
            IF (NOT Vulkan_FOUND)
    #	    message("$ENV{VULKAN_SDK}")
    #                find_library(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/libs/vulkan" REQUIRED)
#                    find_library(Vulkan_LIBRARIES NAMES vulkan HINTS "${CMAKE_SOURCE_DIR}/lib/" REQUIRED NO_DEFAULT_PATH REQUIRED)
                    find_library(Vulkan_LIBRARIES NAMES vulkan HINTS "${CMAKE_SOURCE_DIR}/usr/lib/" REQUIRED NO_DEFAULT_PATH)
                    #message(${Vulkan_LIBRARY})

                    IF (Vulkan_LIBRARIES)
                            set(Vulkan_FOUND TRUE)
                            set(Vulkan_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/module/Vulkan-Headers/include/")
							MESSAGE(STATUS "Using bundled Vulkan library version")
                    ENDIF()
            ENDIF()
    #	find_package(Threads REQUIRED)
    ELSEIF(APPLE)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_MACOS_MVK -DVK_EXAMPLE_XCODE_GENERATED")
    ENDIF()
endif()


IF (NOT Vulkan_FOUND)
        message(FATAL_ERROR "Could not find Vulkan library!")
ELSE()
        message(STATUS "Vulkan_INCLUDE_DIRS : ${Vulkan_INCLUDE_DIRS}")
        message(STATUS "Vulkan_LIBRARIES : ${Vulkan_LIBRARIES}")
#        message(STATUS "Vulkan_LIBRARY : ${Vulkan_LIBRARY}")
#        message(STATUS "Vulkan:Vulkan : ${Vulkan}")
#        message(STATUS ${Vulkan_LIBRARY})
ENDIF()



#find_package(glfw REQUIRED)
#find_package(glm REQUIRED)
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)

file(GLOB SOURCES *.cpp *.h *.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
#target_link_libraries(${PROJECT_NAME} PRIVATE ${VULKAN_LIB_LIST})
#target_link_libraries(${PROJECT_NAME} PRIVATE vulkan)
#target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Headers)
#target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
#target_link_libraries(${PROJECT_NAME} PRIVATE dl)

