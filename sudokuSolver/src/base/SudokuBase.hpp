#ifndef SUDOKU_SUDOKU_BASE_HPP
#define SUDOKU_SUDOKU_BASE_HPP

#include <string>
#include <stdexcept>

/**
 * \brief Contains all Sudoku functions
 */
namespace Sudoku
{

using idx_t = short int;  ///< index type
using val_t = short int;  ///< value type
using Sudoku_t = val_t *; ///< internal type

/**
 * @brief Internal Sudoku representation
 */
class Sudoku
{
public:

  Sudoku(const Sudoku& other);

  /// @brief Generate empty sudoku
  Sudoku();

  ~Sudoku();

  /**
    * @brief Count empty entries in the Sudoku
    * @return amount of empty cells
    */
  idx_t countEmpty() const;

  /**
    * @brief Get value at position
    * @param row index of row
    * @param col index of col
    * @return value at position
    */
  val_t operator()(idx_t row, idx_t col) const;

  /**
    * @brief Get value at position
    * @param row index of row
    * @param col index of col
    * @return value at position
    */
  val_t get(idx_t row, idx_t col) const;

  /**
    * @brief Count empty entries in the given Block
    * @param row row index of block
    * @param col col index of block
    * @return amount of empty cells
    */
  idx_t countEmpty(idx_t row, idx_t col) const;

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
  inline bool checkRange(val_t value) const;

  /**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     * @return whether check went well
     */
  inline bool checkValueExist(idx_t row, idx_t col) const;

  Sudoku_t _matrix; ///< internal representation of sudoku
};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */