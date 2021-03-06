#ifndef SUDOKU_SOLVER_RECURSION_HPP
#define SUDOKU_SOLVER_RECURSION_HPP

#include "BaseSolver.hpp"

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
   * @return Internal need
   */
  bool SolveRecursively();

  /**
   * @brief Find a location with no value
   * @param row index of row
   * @param col index of col
   * @return Whether it has found an empty location, and this position in the input parameters
   */
  bool FindUnassignedLocation(idx_t &row, idx_t &col);
}; /* class RecursionSolver */

} /* namespace Solver */

} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_RECURSION_HPP */