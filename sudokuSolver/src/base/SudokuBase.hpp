

#ifndef SUDOKU_SUDOKU_BASE_HPP
#define SUDOKU_SUDOKU_BASE_HPP

#include <Eigen/Dense>
#include <string>
#include <stdexcept>

/**
 * \brief Contains all Sudoku functions
 */
namespace Sudoku
{

using SudokuMatrix = Eigen::Matrix<short, 9, 9>; ///< internal type
using idx_t = short int;                         ///< index type
using val_t = short int;                         ///< value type

/**
 * @brief Internal Sudoku representation
 */
class Sudoku
{
  public:
    /// @brief Generate empty sudoku
    Sudoku()
    {
        _matrix = SudokuMatrix::Zero();
    }
    /**
     * @brief add a new entry
     * @param row index of row
     * @param col index of column
     * @param value number at this position
     */
    void addEntry(idx_t row, idx_t col, val_t value)
    {
        checkValueExist(row, col);
        checkRange(value);
        _matrix(row, col) = value;
        check();
    }
    /**
     * @brief get value at position
     * @param row index of row
     * @param col index of column
     */
    val_t get(idx_t row, idx_t col) const
    {
        val_t val = _matrix(row, col);
        return val;
    }

    /**
     * @brief remove entry at position
     * @param row index of row
     * @param col index of column
     */
    void removeEntry(idx_t row, idx_t col)
    {
        _matrix(row, col) = 0;
    }

  private:
    /**
     * @brief check if all sudoku constraints hold
     */
    void check() const
    {
        for (idx_t i = 0; i < 9; i++)
        {
            for (idx_t j = 0; j < 9; j++)
            {
                check(i, j);
            }
        }
    }

    /**
     * @brief check if all sudoku constraints hold (for given entry)
     */
    void check(idx_t row, idx_t col) const
    {
        idx_t block_row = row / 3; // we rely on integer division here
        idx_t block_col = col / 3; // still integer division
        val_t value = _matrix(row, col);
        if (value == 0)
            return; // nothing to check because empty cell

        // check row and col
        for (idx_t i = 0; i < 9; i++)
        {
            if (_matrix(row, i) == value && i != col)
            {
                throw std::logic_error("Value already exist in row");
            }
            if (_matrix(i, col) == value && i != row)
            {
                throw std::logic_error("Value already exist in col");
            }
        }

        // check block
        for (idx_t i = block_row * 3; i < block_row * 3 + 3; i++)
        {
            for (idx_t j = block_col * 3; j < block_col * 3 + 3; j++)
            {
                if (i != row && j != col && _matrix(i, j) == value)
                {
                    throw std::logic_error("Value already in block");
                }
            }
        }
    }

    /**
     * @brief check if value is in bounds (1-9)
     * @param value value to check
     */
    void checkRange(val_t value) const
    {
        if (value < 1 || value > 9)
        {
            throw std::out_of_range("Value " + std::to_string(value) + " out of bounds");
        }
    }

    /**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     */
    void checkValueExist(idx_t row, idx_t col) const
    {
        if (_matrix(row, col) != 0)
        {
            throw "Sudoku not empty at " + std::to_string(row) + "/" + std::to_string(col);
        }
    }

    SudokuMatrix _matrix; ///< internal representation of sudoku
};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */