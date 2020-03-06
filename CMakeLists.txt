# - Main CMake buildscript for mpags-cipher
#comments in a CMake script are lines beginning with '#'

# - set cmake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.0.1)

# require c++ 14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE ON)

# dont allow C++ compiler vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# use our compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - add the MPAGSCipher subdirectory to the build
add_subdirectory(MPAGSCipher)

# - Add the Documentation subdirectory to the build
add_subdirectory(Documentation)

# - enable testing and add testing subdirectory
enable_testing()
add_subdirectory(Testing)

# - declare the build of mpags-cipher main program
add_executable(mpags-cipher.exe
 	mpags-cipher.cpp
	)
target_link_libraries(mpags-cipher.exe
	PRIVATE MPAGSCipher
	)
