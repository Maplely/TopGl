
# cmake_minimum_required(VERSION 3.12)
# project(OpenGL)
 
# set(CMAKE_CXX_STANDARD 14)
 
# set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.8/include/GLFW/)
# set(HEADER ./include/)

# include_directories(${GLFW_H} ${HEADER})
 
# # 添加目标链接
# set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib)
# link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})
 
# # 执行编译命令
# # 这个glad.c在第2步中说过要拉到项目中，注意路径
# set(SOURCE_FILES "src/gl.c" "src/main.cpp")
# add_executable(OpenGL ${SOURCE_FILES})

cmake_minimum_required(VERSION 3.12)
project(OpenGL)
 
set(CMAKE_CXX_STANDARD 14)
 
set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include/GL/)
set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.8/include/GLFW/)
set(GLAD_H ./include/)

include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${KHR_H})
 
# 添加目标链接
set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})
 
# 执行编译命令
# 这个glad.c在第2步中说过要拉到项目中，注意路径
set(SOURCE_FILES "src/glad.c" "src/main.cpp")
add_executable(OpenGL ${SOURCE_FILES})

 
# mac下这步很重要
if (APPLE)
    target_link_libraries(OpenGL "-framework OpenGL")
    target_link_libraries(OpenGL "-framework GLUT")
endif(APPLE)
