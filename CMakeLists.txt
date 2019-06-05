cmake_minimum_required(VERSION 3.9)

project(SudokuSolver)
set(CXX_STANDARD 11)

# Check that this is not an in-source build:
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif()

# Option whether the tests should be built or not. default ON
option(ENABLE_TESTING "The tests will be built" ON)
if(ENABLE_TESTING) 
  # Enable testing
  enable_testing()
  add_subdirectory(test)
endif()

# Documentation build by default ON
option(BUILD_DOC "Build documentation" ON)
if(BUILD_DOC)
  # Run doxygen
  add_subdirectory(doc)
endif()

# set release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(sudokuSolver)