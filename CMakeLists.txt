cmake_minimum_required(VERSION 3.12)
project(GraphAlgos)

# Add the include directory to the search path for header files
include_directories(include)

# Gather all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(out ${SOURCES})

# Add the -g flag for debugging information
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")