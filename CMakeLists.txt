cmake_minimum_required(VERSION 3.7)

project(CustomEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
set(PROJECT_SRC "${PROJECT_ROOT}/src")
set(PROJECT_INCLUDE "${PROJECT_ROOT}/include")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(${PROJECT_INCLUDE})
file(GLOB CustomEngineSRC
	"${PROJECT_INCLUDE}/*.h"
	"${PROJECT_SRC}/*.cpp*"
)

add_executable(CustomEngine ${CustomEngineSRC})
target_link_libraries(CustomEngine ${SDL2_LIBRARIES})