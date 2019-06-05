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
 * @brief Generate Sudoku from given stream
 * @param stream The stream to read from
 * @return Sudoku
 */
Sudoku readStream(std::istream &stream);

/**
 * @brief Generate Sudoku from given filename
 * @param filename The filename to read from
 * @return Sudoku
 */Sudoku readFile(const char *filename);

} // namespace IO
} /* namespace Sudoku */

#endif /* SUDOKU_IO_READ_FILE_HPP */