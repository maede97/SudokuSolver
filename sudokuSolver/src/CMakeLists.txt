cmake_minimum_required(VERSION 3.10)

add_subdirectory(base)
add_subdirectory(io)
add_subdirectory(solver)

add_library(Sudoku STATIC ../base.hpp ../io.hpp ../solver.hpp)

target_link_libraries(Sudoku SudokuIO SudokuSolver SudokuBase)