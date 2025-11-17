cmake_minimum_required(VERSION 3.10)

project(MinimalCpp VERSION 1.0.0 LANGUAGES CXX)

# Nastavení C++ standardu
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(MSVC)
    add_compile_options(/W4)
endif()

# Debug/Release konfigurace
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

# Hlavní executable
add_executable(MinimalCpp main.cpp)

# Instalace (volitelné)
install(TARGETS MinimalCpp DESTINATION bin)

