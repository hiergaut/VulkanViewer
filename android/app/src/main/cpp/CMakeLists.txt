# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("myapplication")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DVK_USE_PLATFORM_ANDROID_KHR -DVK_NO_PROTOTYPES")

set(CMAKE_DIR "../../../../..")
set(SRC_DIR ${CMAKE_DIR}/src)
file(GLOB EXAMPLE_SRC "${SRC_DIR}/*.cpp")
#file(GLOB LIB_VULKAN "${CMAKE_DIR}/usr/lib/libvulkan.so.1.2.135")
#message(STATUS ${LIB_VULKAN})
#message(FATAL_ERROR ${EXAMPLE_SRC})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(native-lib SHARED ${EXAMPLE_SRC})
#add_library( # Sets the name of the library.
#             native-lib
#             # Sets the library as a shared library.
#             SHARED
#             # Provides a relative path to your source file(s).
#             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#find_package(Vulkan REQUIRED)
#IF (NOT Vulkan_FOUND)
#    message(FATAL_ERROR "Could not find Vulkan library!")
#ELSE()
#    message(STATUS "Vulkan_INCLUDE_DIRS : ${Vulkan_INCLUDE_DIRS}")
#    message(STATUS "Vulkan_LIBRARIES : ${Vulkan_LIBRARIES}")
#ENDIF()


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                        #android
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
#                        ${Vulkan_LIBRARIES}
                        vulkan

        )