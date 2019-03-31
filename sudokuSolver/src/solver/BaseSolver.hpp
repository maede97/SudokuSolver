#ifndef SUDOKU_SOLVER_BASE_HPP
#define SUDOKU_SOLVER_BASE_HPP

#include "../base/SudokuBase.hpp"

namespace Sudoku
{

/**
 * \brief Contains all Solver routines
 */
namespace Solver
{

/**
 * \brief Abstract Base class for all solvers
 */
class BaseSolver
{
  public:
    BaseSolver() = default;
    /**
     * Initialise using a Sudoku
     */
    BaseSolver(Sudoku s) : _sudoku(s) {}
    ~BaseSolver() = default;
    /**
     * Solve the given Sudoku
     */
    virtual Sudoku solve() = 0;
    /**
     * Returns the solved Sudoku
     */
    Sudoku getSudoku() const { return _sudoku; }

  protected:
    Sudoku _sudoku;
};

} /* namespace Solver */
} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_BASE_HPP */