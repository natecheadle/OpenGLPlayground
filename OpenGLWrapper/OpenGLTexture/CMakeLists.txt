cmake_minimum_required(VERSION 3.19)
project(OpenGLTexture)

add_library(${PROJECT_NAME} STATIC
        "src/Texture.cpp"
        "src/stb_implementation.cpp" 
        "src/ImageFile.cpp")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_path(STB_INCLUDE_DIRS "stb.h")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${PROJECT_NAME} PUBLIC ${STB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES} glad::glad glfw)