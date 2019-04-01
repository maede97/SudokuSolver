#include "ReadFromFile.hpp"

namespace Sudoku
{
/**
 * \brief Contains all IO routines
 */
namespace IO
{
/// @brief Generate Sudoku from given stream
Sudoku readStream(std::istream &stream)
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
Sudoku readFile(const char *filename)
{
    std::fstream stream(filename);
    if (!stream.good())
    {
        throw std::invalid_argument("File does not exist");
    }
    return readStream(stream);
}

} // namespace IO
} /* namespace Sudoku */