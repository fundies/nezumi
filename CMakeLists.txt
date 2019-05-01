# Setup CMake
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.2)

# Setup Project
PROJECT (nezumi)

# Setup Compiler
SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Files
INCLUDE ("cmake/config.cmake")
INCLUDE ("cmake/macros.cmake")

# Add Project Directories
ADD_SUBDIRECTORY ("source/runtime")
ADD_SUBDIRECTORY ("source/compiler")
ADD_SUBDIRECTORY ("source/sample")