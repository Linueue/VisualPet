cmake_minimum_required(VERSION 3.20)

project(glad VERSION 0.1 LANGUAGES CXX C)

add_library(glad "src/glad.c")

target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
