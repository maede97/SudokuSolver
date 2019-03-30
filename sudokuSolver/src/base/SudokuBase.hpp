

#ifndef SUDOKU_SUDOKU_BASE_HPP
#define SUDOKU_SUDOKU_BASE_HPP

#include <Eigen/Dense>

/**
 * \brief Contains all Sudoku functions
 */
namespace Sudoku {

using SudokuMatrix = Eigen::Matrix<short, 9, 9>;
using idx_t = short;
using val_t = short;

/**
 * @brief Internal Sudoku representation
 */
class Sudoku {
public:
    /// @brief Generate empty sudoku
    Sudoku() {
        _matrix = SudokuMatrix::Zero();
    }

private:
    SudokuMatrix _matrix;
};

} /* namespace Sudoku */

#endif /* SUDOKU_SUDOKU_BASE_HPP */