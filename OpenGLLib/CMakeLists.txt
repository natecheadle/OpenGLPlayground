cmake_minimum_required(VERSION 3.19)
project(OpenGLLib)

add_library(${PROJECT_NAME} STATIC
        "src/Shader.cpp"
        "src/FragmentShader.cpp"
        "src/VertexShader.cpp"
        "src/ShaderProgram.cpp")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES} glad::glad glfw)