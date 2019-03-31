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
class BruteForce : protected BaseSolver
{
public:
  BruteForce() : BaseSolver()
  {
  }

  BruteForce(Sudoku s) : BaseSolver(s)
  {
  }

  Sudoku solve()
  {
    fillTrivial();
    return _sudoku;
  }

private:
  void fillTrivial()
  {
    for (idx_t row = 0; row < 9; row++)
    {
      for (idx_t col = 0; col < 9; col++)
      {
        Block_t block = _sudoku.getBlockForEntry(row, col);
        idx_t empty = countEmpty(_sudoku.getData());
        switch (empty)
        {
        case 0:
          break;
        case 1:
        {
          // only one to fill
          break;
        }
        default:
          break;
        }
      }
    }
  }
};

} /* namespace Solver */

} /* namespace Sudoku */

#endif /* SUDOKU_SOLVER_BRUTEFORCE_HPP */