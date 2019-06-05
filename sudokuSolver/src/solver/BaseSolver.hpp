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
   /**
     * @brief Initialise using a Sudoku
     * @param s The Sudoku to solve
     */
   BaseSolver(Sudoku s);

   /**
   * @brief using default destructor
   */
   ~BaseSolver() = default;

   /**
     * @brief Solve Sudoku
     * @return Solved Sudoku
     */
   virtual Sudoku solve() = 0;

   /**
     * @brief get the Sudoku back
     * @return Sudoku
     */
   Sudoku getSudoku() const;

 protected:
   Sudoku _sudoku;
};

} /* namespace Solver */
} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_BASE_HPP */