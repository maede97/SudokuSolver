cmake_minimum_required(VERSION 3.10)

add_subdirectory(base)
add_subdirectory(io)
add_subdirectory(solver)

add_library(Sudoku STATIC ../io.hpp ../solver.hpp ../base.hpp)

target_link_libraries(Sudoku SudokuSolver SudokuIO SudokuBase)
