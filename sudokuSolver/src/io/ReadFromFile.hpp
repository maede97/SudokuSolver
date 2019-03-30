#ifndef SUDOKU_IO_READ_FILE_HPP
#define SUDOKU_IO_READ_FILE_HPP

#include "../base/SudokuBase.hpp"
#include <fstream>
#include <stdexcept>

namespace Sudoku
{
/**
 * \brief Contains all IO routines
 */
namespace IO
{
/// @brief Generate Sudoku from given stream
Sudoku generateFromStream(std::istream &stream)
{
    Sudoku s;
    val_t value;
    for (idx_t i = 0; i < 9; i++)
    {
        for (idx_t j = 0; j < 9; j++)
        {
            stream >> value;
            if (value != 0)
            {
                s.addEntry(i, j, value);
            }
        }
    }
    return s;
}

/// @brief Generate Sudoku from File
Sudoku generateFromFile(const char *filename)
{
    std::fstream stream(filename);
    if (!stream.good())
    {
        throw std::invalid_argument("File does not exist");
    }
    return generateFromStream(stream);
}

} // namespace IO
} /* namespace Sudoku */

#endif /* SUDOKU_IO_READ_FILE_HPP */