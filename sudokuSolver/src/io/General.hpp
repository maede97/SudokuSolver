#ifndef SUDOKU_IO_GENERAL_HPP
#define SUDOKU_IO_GENERAL_HPP

#include <iostream>
#include "../base/SudokuBase.hpp"

/**
 * @brief pretty print Sudoku
 * @param os the stream to be written to
 * @param rhs the Sudoku to print
 * @return the stream
 */
std::ostream &operator<<(std::ostream &os, const Sudoku::Sudoku rhs);

#endif /* SUDOKU_IO_GENERAL_HPP */
