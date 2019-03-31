

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

using idx_t = short int;                     ///< index type
using val_t = short int;                     ///< value type
using Sudoku_t = Eigen::Matrix<val_t, 9, 9>; ///< internal type
using Block_t = Eigen::Matrix<val_t, 3, 3>;
using Row_t = Eigen::Matrix<val_t, 9, 1>;


idx_t countEmpty(Block_t b) {
    idx_t count = 0;
    for(idx_t i = 0; i < 3; i++) {
        for(idx_t j = 0; j < 3; j++) {
            if(b(i,j) == 0) count++;
        }
    }
    return count;
}

idx_t countEmpty(Sudoku_t s) {
    idx_t count = 0;
    for(idx_t i = 0; i < 3; i++) {
        for(idx_t j = 0; j < 3; j++) {
            Block_t b = s.block(i * 3, j*3, 3, 3);
            count += countEmpty(b);
        }
    }
    return count;
}

/**
 * @brief Internal Sudoku representation
 */
class Sudoku
{
  public:
    /// @brief Generate empty sudoku
    Sudoku()
    {
        _matrix = Sudoku_t::Zero();
    }
    /**
     * @brief add a new entry
     * @param row index of row
     * @param col index of column
     * @param value number at this position
     */
    bool addEntry(idx_t row, idx_t col, val_t value)
    {
        if(!checkValueExist(row, col)) return false; // check if already a value there
        if(!checkRange(value)) return false; // value in [1,9]
        _matrix(row, col) = value; // set value
        if(!check(row, col)) {
            _matrix(row, col) = 0; // remove value
            return false;
        }
        return true;
    }

    bool checkValidity(idx_t row, idx_t col, val_t value) {
        if(!checkValueExist(row, col)) return false; // check if already a value there
        if(!checkRange(value)) return false; // value in [1,9]
        _matrix(row, col) = value; // set value
        if(!check(row, col)) {
            _matrix(row, col) = 0; // remove value
            return false;
        }
        _matrix(row, col) = 0; // reset 
        return true;
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

    bool hasEntry(idx_t row, idx_t col) {
        return !(_matrix(row, col) == 0);
    }
    /**
     * @brief Get the 3x3 block for a specific entry
     * @param row index of row
     * @param col index of column
     */
    Block_t getBlockForEntry(idx_t row, idx_t col)
    {
        idx_t block_row = row / 3;
        idx_t block_col = col / 3;
        return _matrix.block(block_row * 3, block_col * 3, 3, 3);
    }
    /**
     * @brief Get the 3x3 block using block indices
     * @param row index of row
     * @param col index of column
     */
    Block_t getBlockFromIndex(idx_t row, idx_t col) const
    {
        return _matrix.block(row * 3, col * 3, 3, 3);
    }

    Sudoku_t getData() const {
        return _matrix;
    }

    void setData(Sudoku_t data) {
        _matrix = data;
    }

  private:
    /**
     * @brief check if all sudoku constraints hold
     */
    bool check() const
    {
        for (idx_t i = 0; i < 9; i++)
        {
            for (idx_t j = 0; j < 9; j++)
            {
                if(check(i, j) == false) return false;
            }
        }
        return true;
    }

    /**
     * @brief check if all sudoku constraints hold (for given entry)
     */
    bool check(idx_t row, idx_t col) const
    {
        idx_t block_row = row / 3; // we rely on integer division here
        idx_t block_col = col / 3; // still integer division
        val_t value = _matrix(row, col);
        if (value == 0)
            return true; // nothing to check because empty cell

        // check row and col
        for (idx_t i = 0; i < 9; i++)
        {
            if (_matrix(row, i) == value && i != col)
            {
                return false;
            }
            if (_matrix(i, col) == value && i != row)
            {
                return false;
            }
        }

        // check block
        for (idx_t i = block_row * 3; i < block_row * 3 + 3; i++)
        {
            for (idx_t j = block_col * 3; j < block_col * 3 + 3; j++)
            {
                if (i != row && j != col && _matrix(i, j) == value)
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @brief check if value is in bounds (1-9)
     * @param value value to check
     */
    bool checkRange(val_t value) const
    {
        if (value < 1 || value > 9)
        {
            return false;
        }
        return true;
    }

    /**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     */
    bool checkValueExist(idx_t row, idx_t col) const
    {
        if (_matrix(row, col) != 0)
        {
            return false;
        }
        return true;
    }

    Sudoku_t _matrix; ///< internal representation of sudoku
};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */