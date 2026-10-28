cmake_minimum_required(VERSION 3.20)

project(ModularDesignTDD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(modular_design STATIC src/Greeter.cpp)
target_include_directories(modular_design PUBLIC src)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE modular_design)

enable_testing()
add_subdirectory(tests)
