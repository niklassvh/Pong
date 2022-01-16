cmake_minimum_required(VERSION 3.20)
project(PongMetodik)

set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.20)
# set the projectX name to the name of your project

set(SFML_ROOT "C:\\Users\\nikla\\Desktop\\PongMetodik\\SFML32")
set(SFML_DIR "C:\\Users\\nikla\\Desktop\\PongMetodik\\SFML32\\lib\\cmake\\SFML")
find_package(SFML 2.5.1 COMPONENTS network audio graphics window system REQUIRED)
link_directories("C:\\Users\\nikla\\Desktop\\PongMetodik\\SFML32")
add_executable(PongMetodik src/main.cpp src/Engine.cpp src/Engine.h src/Paddle.cpp src/Paddle.h src/Ball.cpp src/Ball.h)
target_link_libraries(PongMetodik sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
