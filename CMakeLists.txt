cmake_minimum_required(VERSION 3.20)

project(VisualPet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/stb_image)

file(GLOB_RECURSE SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(VisualPet ${SOURCES_CPP})

add_custom_target(assets COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/assets.cmake)
add_dependencies(VisualPet assets)

if(CMAKE_BUILD_TYPE STREQUAL "Release" AND WIN32)
    target_link_options(VisualPet PRIVATE "LINKER:/SUBSYSTEM:WINDOWS,/ENTRY:mainCRTStartup")
endif()

target_include_directories(VisualPet PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glm"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stb_image"
)
target_link_libraries(VisualPet PRIVATE glfw glad glm stb_image)
