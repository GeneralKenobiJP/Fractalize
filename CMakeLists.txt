cmake_minimum_required(VERSION 3.26)
project(Fractalize)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fractalize src/main.cpp
        src/Renderer.cpp
        src/Renderer.h
        src/VertexBuffer.cpp
        src/VertexBuffer.h
        src/IndexBuffer.cpp
        src/IndexBuffer.h
        src/VertexArray.cpp
        src/VertexArray.h
        src/BufferLayout.cpp
        src/BufferLayout.h
        src/Shader.cpp
        src/Shader.h)

include_directories(include)
include_directories(lib)

add_compile_definitions(GLEW_STATIC)

add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/lib-mingw-w64/libglfw3.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/GLFW")
add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/glew-2.1.0/glew32s.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/GL")

target_link_libraries(Fractalize glew GLFW Opengl32.lib User32.lib Gdi32.lib Shell32.lib)