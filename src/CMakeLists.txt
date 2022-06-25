set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

cmake_minimum_required(VERSION 3.10)

project(ConwayLifeGame) #project name

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART True)

set(SOURCE_EXE main.cpp) #src list for exe

include_directories(World) #headers for project
add_subdirectory(World) #subproject adding
add_executable(ConwayLifeGame ${SOURCE_EXE}) # exe creation with "ConwayLifeGame" name
target_link_libraries(ConwayLifeGame World_field) # linking "ConwayLifeGame" & "World_field"

