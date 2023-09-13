project(main)
SET(CXX_STANDARD 17)
CMAKE_MINIMUM_REQUIRED(VERSION 3.19)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS} Textures SpecularMaps NormalMaps HeightMaps)
link_directories(${/usr/include/SOIL} Textures SpecularMaps NormalMaps HeightMaps)

link_libraries(${GLEW_LIBRARIES})

add_executable(main main.cpp Shader.cpp Texture.cpp Material.cpp 
               Mesh.cpp Primitive.cpp Quad.cpp Cube.cpp RectCuboid.cpp Plane.cpp 
               Camera.cpp Model.cpp Game.cpp)
target_link_libraries(main OpenGL glfw GLEW SOIL)

