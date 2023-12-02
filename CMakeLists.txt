cmake_minimum_required(VERSION 3.26)
project(Fractalize)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fractalize src/main.cpp)

include_directories(include)
include_directories(lib)

add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-mingw-w64/libglfw3.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/GLFW")
target_link_libraries(Fractalize GLFW Opengl32.lib)