
cmake_minimum_required(VERSION 3.10.2)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

set(GLAD_H ${PROJECT_SOURCE_DIR}/include/)

include_directories(${GLAD_H})

# 添加目标链接
if(APPLE)
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/lib/mac/libglfw.dylib)
else()
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/lib/ubuntu/libglfw.so)
endif()

link_libraries(${OPENGL} ${GLFW_LINK})

# 执行编译命令
# 这个glad.c在第2步中说过要拉到项目中，注意路径
# set(GLAD_SOURCE ${PROJECT_SOURCE_DIR}/src/glad.c )
file(GLOB_RECURSE C_SOURCE ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.cpp)

set(SOURCE_FILES ${C_SOURCE})
add_executable(OpenGL ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

# mac下这步很重要
if(APPLE)
    target_link_libraries(OpenGL "-framework OpenGL")
    target_link_libraries(OpenGL "-framework GLUT")
endif(APPLE)
