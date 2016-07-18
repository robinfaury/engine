CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(EXE_NAME "engine")

PROJECT(${EXE_NAME})

ADD_EXECUTABLE(${EXE_NAME} src/main.cpp)

INCLUDE_DIRECTORIES("C:/lib/glm")

INCLUDE_DIRECTORIES("C:/lib/glfw/include")
TARGET_LINK_LIBRARIES(${EXE_NAME} C:/lib/glfw/lib/Release/glfw3.lib)

INCLUDE_DIRECTORIES("C:/lib/glew/include")
TARGET_LINK_LIBRARIES(${EXE_NAME} C:/lib/glew/lib/glew32.lib)

INCLUDE_DIRECTORIES("C:/lib/assimp/include")
TARGET_LINK_LIBRARIES(${EXE_NAME} C:/lib/assimp/lib/Release/assimp-vc140-mt.lib)

add_subdirectory(src/gpu)
INCLUDE_DIRECTORIES("./src/gpu/include")
TARGET_LINK_LIBRARIES(${EXE_NAME} gpu)

add_subdirectory(src/loader)
INCLUDE_DIRECTORIES("./src/loader/include")
TARGET_LINK_LIBRARIES(${EXE_NAME} loader)

FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
	TARGET_LINK_LIBRARIES(${EXE_NAME} ${OPENGL_LIBRARIES})
endif()