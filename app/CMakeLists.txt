#cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#cmake_minimum_required(VERSION 3.7)

project(app VERSION 1.0 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SOURCES *.cpp *.h *.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} src)
