#ifndef SUDOKU_SOLVER_BRUTEFORCE_HPP
#define SUDOKU_SOLVER_BRUTEFORCE_HPP

#include "BaseSolver.hpp"
#include "../base/SudokuBase.hpp"
#include <iostream>

namespace Sudoku
{

namespace Solver
{

/**
 * \brief %BruteForce approach
 */
class BruteForce : public BaseSolver
{
  public:
    BruteForce() : BaseSolver()
    {
    }

    BruteForce(Sudoku s) : BaseSolver(s)
    {
    }

    void solve()
    {
    }
};

} /* namespace Solver */

} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_BRUTEFORCE_HPP */