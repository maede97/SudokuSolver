#ifndef SUDOKU_IO_READ_FILE_HPP
#define SUDOKU_IO_READ_FILE_HPP

#include "../base/SudokuBase.hpp"
#include <fstream>

namespace Sudoku
{
/**
 * \brief Contains all IO routines
 */
namespace IO
{

/**
 * @brief Contains all functions for reading files
 */

/// @brief Generate Sudoku from given stream
Sudoku readStream(std::istream &stream);

/// @brief Generate Sudoku from File
Sudoku readFile(const char *filename);

} // namespace IO
} /* namespace Sudoku */

#endif /* SUDOKU_IO_READ_FILE_HPP */