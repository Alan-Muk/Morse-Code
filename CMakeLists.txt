cmake_minimum_required(VERSION 3.16)
project(MorseProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/input-handler.cpp
    src/morse-decoder.cpp
    src/output-display.cpp
)

# Executable
add_executable(morse_app ${SOURCES})

# Include headers
target_include_directories(morse_app PRIVATE src)