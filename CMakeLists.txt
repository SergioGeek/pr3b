cmake_minimum_required(VERSION 3.8)


set(PROJECT_NAME "pr3b")

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES pr3b.cpp cgvScene3D.h cgvScene3D.cpp cgvPoint3D.h cgvPoint3D.cpp cgvInterface.h cgvInterface.cpp cgvCamera.h cgvCamera.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})