cmake_minimum_required(VERSION 3.16)

project(sdl)
set(VERBOSE 1)
set(CMAKE_C_STANDARD 99)


add_executable(sdl_learn main.c)
target_include_directories(sdl_learn PUBLIC
    "$(PROJECT_BINARY_DIR)"
    "/usr/include/SDL2")


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(sdl_learn ${SDL2_LIBRARIES})
