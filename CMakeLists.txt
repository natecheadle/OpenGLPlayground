cmake_minimum_required(VERSION 3.19)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(PROJECT_SHADER_ROOT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Shaders/")
add_compile_definitions(PROJECT_TEXTURES_ROOT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Textures/")

add_subdirectory(OpenGLWrapper)

add_executable(${PROJECT_NAME} "main.cpp")
find_package(glm CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGLShader OpenGLTexture glm::glm)
