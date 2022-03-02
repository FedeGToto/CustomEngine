cmake_minimum_required(VERSION 3.7)

project(CustomEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}/CustomEngine/")
set(PROJECT_SRC "${PROJECT_ROOT}/src")
set(PROJECT_INCLUDE "${PROJECT_ROOT}/include")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(Chipmunk REQUIRED)
include_directories(${CHIPMUNK_INCLUDE_DIR})

include_directories(${PROJECT_INCLUDE})
file(GLOB CustomEngineSRC
	"${PROJECT_INCLUDE}/*.h"
	"${PROJECT_SRC}/*.cpp*"
)

add_library(CustomEngine ${CustomEngineSRC})
target_link_libraries(CustomEngine ${SDL2_LIBRARIES})
target_link_libraries(CustomEngine ${CHIPMUNK_LIBRARIES})

project(TestGame)

set(TEST_ROOT "${PROJECT_SOURCE_DIR}/TestGame/")
set(TEST_SRC "${TEST_ROOT}/src")
set(TEST_INCLUDE "${TEST_ROOT}/include")

include_directories(${TEST_INCLUDE})
file(GLOB TestGameSRC
	"${TEST_INCLUDE}/*.h"
	"${TEST_SRC}/*.cpp*"
)

include_directories(${TEST_INCLUDE})
add_executable(TestGame ${TestGameSRC})
target_link_libraries(TestGame CustomEngine) 