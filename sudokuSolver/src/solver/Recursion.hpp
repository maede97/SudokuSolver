#ifndef SUDOKU_SOLVER_RECURSION_HPP
#define SUDOKU_SOLVER_RECURSION_HPP

#include "BaseSolver.hpp"
#include "../base/SudokuBase.hpp"

namespace Sudoku
{

namespace Solver
{

/**
 * @brief %Recursion approach
 * 
 * Solve Sudoku recursively, this might be slow for Sudokus with few given entries.
 */
class RecursionSolver : protected BaseSolver
{
public:
  /**
 * @brief Initialize with given Sudoku
 */
  RecursionSolver(Sudoku s);
  Sudoku solve();

private:
  /**
   * @brief Solve Sudoku recursively
   */
  bool SolveRecursively();

  /**
   * @brief Find a location with no value
   */
  bool FindUnassignedLocation(idx_t &row, idx_t &col);
}; /* class RecursionSolver */

} /* namespace Solver */

} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_RECURSION_HPP */