

#ifndef SUDOKU_SUDOKU_BASE_HPP
#define SUDOKU_SUDOKU_BASE_HPP

#include <Eigen/Dense>

/**
 * \brief Contains all Sudoku functions
 */
namespace Sudoku {

using SudokuMatrix = Eigen::Matrix<short, 9, 9>; ///< internal type
using idx_t = short; ///< index type
using val_t = short; ///< value type

/**
 * @brief Internal Sudoku representation
 */
class Sudoku {
public:
    /// @brief Generate empty sudoku
    Sudoku() {
        _matrix = SudokuMatrix::Zero();
    }
    /**
     * @brief add a new entry
     * @param row index of row
     * @param col index of column
     * @param value number at this position
     */
    void addEntry(idx_t row, idx_t col, val_t value) {
        checkValueExist(row, col);
        checkRange(value);
        _matrix(row, col) = value;
        check();
    }

    /**
     * @brief remove entry at position
     * @param row index of row
     * @param col index of column
     */ 
    void removeEntry(idx_t row, idx_t col) {
        _matrix(row, col) = 0;
    }

private:
    /**
     * @brief check if all sudoku constraints hold
     */
    void check() {

    }

    /**
     * @brief check if value is in bounds (1-9)
     * @param value value to check
     */
    void checkRange(val_t value) {
        if(value < 1 || value > 9) {
            throw "Value " + std::to_string(value) + " out of bounds";
        }
    }

    /**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     */
    void checkValueExist(idx_t row, idx_t col) {
        if(_matrix(row, col)!= 0) {
            throw "Sudoku not empty at " + std::to_string(row) + "/" + std::to_string(col);
        }
    }

    SudokuMatrix _matrix; ///< internal representation of sudoku

};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */