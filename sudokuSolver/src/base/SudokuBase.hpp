

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

/**
 * @brief Count empty entries in the given Block
 * @param b block to check
 * @return amount of empty cells
 */
idx_t countEmpty(Block_t b);

/**
 * @brief Count empty entries in the given Sudoku
 * @param s Sudoku to check
 * @return amount of empty cells
 */
idx_t countEmpty(Sudoku_t s);

/**
 * @brief Internal Sudoku representation
 */
class Sudoku
{
  public:
    /// @brief Generate empty sudoku
    Sudoku();

    /**
     * @brief add a new entry
     * @param row index of row
     * @param col index of column
     * @param value number at this position
     * @return Wheter we could add the variable
     */
    bool addEntry(idx_t row, idx_t col, val_t value);

    /**
     * @brief Check validity
     * @return Wheter the given value will be valid at this position
     * @param row index of row
     * @param col index of col
     * @param value value to check
     */
    bool checkValidity(idx_t row, idx_t col, val_t value);
    /**
     * @brief get value at position
     * @param row index of row
     * @param col index of column
     * @return value at given position, 0 if not set
     */
    val_t get(idx_t row, idx_t col) const;

    /**
     * @brief remove entry at position
     * @param row index of row
     * @param col index of column
     */
    void removeEntry(idx_t row, idx_t col);

    /**
     * @brief check if Sudoku is empty at position
     * @param row index of row
     * @param col index of col
     * @return whether Sudoku is empty there
     */
    bool hasEntry(idx_t row, idx_t col) const;
    /**
     * @brief Get the 3x3 block for a specific entry
     * @param row index of row
     * @param col index of column
     * @return block in which this entry lies
     */
    Block_t getBlockForEntry(idx_t row, idx_t col) const;
    /**
     * @brief Get the 3x3 block using block indices
     * @param row index of row
     * @param col index of column
     * @return block using block-indices
     */
    Block_t getBlockFromIndex(idx_t row, idx_t col) const;

  private:
    /**
     * @brief check if all sudoku constraints hold
     */
    bool check() const;

    /**
     * @brief check if all sudoku constraints hold (for given entry)
     * @return whether check went well
     */
    bool check(idx_t row, idx_t col) const;

    /**
     * @brief check if value is in bounds (1-9)
     * @param value value to check
     * @return whether check went well
     */
    bool checkRange(val_t value) const;

    /**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     * @return whether check went well
     */
    bool checkValueExist(idx_t row, idx_t col) const;

    Sudoku_t _matrix; ///< internal representation of sudoku
};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */