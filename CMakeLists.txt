cmake_minimum_required(VERSION 3.16)

project(sdl)
set(VERBOSE 1)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SDL_MAIN 
    source/main.c)

add_executable(sdl_learn ${SDL_MAIN})

target_include_directories(sdl_learn PUBLIC
    "$(PROJECT_BINARY_DIR)"
    "source"
    "/usr/include/SDL2")


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(source)

target_link_libraries(sdl_learn ${SDL2_LIBRARIES})
