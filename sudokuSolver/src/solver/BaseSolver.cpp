#include "BaseSolver.hpp"

namespace Sudoku
{

namespace Solver
{

BaseSolver::BaseSolver(Sudoku s) : _sudoku(s) {}

Sudoku BaseSolver::getSudoku() const { return _sudoku; }

} /* namespace Solver */
} /* namespace Sudoku */
