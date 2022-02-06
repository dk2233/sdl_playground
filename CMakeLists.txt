project(SDL_SCHOOL C)
cmake_minimum_required(VERSION 3.16)
IF (COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
ENDIF (COMMAND cmake_policy)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(VERBOSE ON)

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_image REQUIRED)
#FIND_PACKAGE(OpenAL REQUIRED)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS ON)

#set sources 
set(SOURCES 
    source/sdl_functions.c
    source/main.c
    source/game_assets.c
    source/game_events.c
    source/game_loop_renderer.c
    source/game_config.c
    source/game_loop_software.c
    )


# Replace default configurations (Debug/Release/RelWithDebInfo/MinSizeRel) with custom ones.
# - Debug: maximum debugging
# - Release: maximum performance for the computer it's compiled on
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)


SET(CMAKE_C_FLAGS_DEBUG "-g")

SET(CMAKE_C_FLAGS_RELEASE "-g -O3 ")

add_executable(sdl_learn ${SOURCES})

target_include_directories(sdl_learn PUBLIC
    "$(PROJECT_BINARY_DIR)"
    "source"
    "/usr/include/SDL2")


include_directories(${SDL2_INCLUDE_DIRS})
include_directories(source)

target_link_libraries(sdl_learn ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES}) 
