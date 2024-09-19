cmake_minimum_required(VERSION 3.20)

project(stb_image VERSION 0.1 LANGUAGES C CXX)

add_library(stb_image "${CMAKE_CURRENT_SOURCE_DIR}/stb_image.cpp")
target_include_directories(stb_image PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
