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


# declare the build of mpags-cipher main program
add_executable(mpags-cipher.exe
 	mpags-cipher.cpp
 	MPAGSCipher/TransformChar.cpp
	MPAGSCipher/CaesarCipher.cpp
	MPAGSCipher/ProcessCommandLine.cpp
	MPAGSCipher/CipherMode.hpp
	)
target_include_directories(mpags-cipher.exe
	PRIVATE MPAGSCipher
	)
