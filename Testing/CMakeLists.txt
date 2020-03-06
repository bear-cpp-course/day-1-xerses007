# - build sub-script for MPAGSCipher library unit tests

# first catch-based test
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test-catch COMMAND testCatch)

