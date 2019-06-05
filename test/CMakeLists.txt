cmake_minimum_required(VERSION 3.10)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
)

link_directories(
  ${PROJECT_BINARY_DIR}/sudokuSolver
)

set(TESTS
    SudokuBaseTest
    SudokuReadFileTest
    SudokuRecursionTest
    SudokuEmptyTest
    Run
  )

foreach(TEST_NAME ${TESTS})
    add_executable(${TEST_NAME} Test_${TEST_NAME}.cpp)
    add_test(${TEST_NAME} ${TEST_NAME})
    target_link_libraries(${TEST_NAME} Sudoku)
  endforeach()