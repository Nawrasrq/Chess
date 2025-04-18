cmake_minimum_required(VERSION 3.10)
project(ChessTerminalApp)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Gather source files
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# Build executable
add_executable(ChessApp ${SOURCES})
