#include "Recursion.hpp"

namespace Sudoku
{

namespace Solver
{

RecursionSolver::RecursionSolver(Sudoku s) : BaseSolver(s)
{
}
Sudoku RecursionSolver::solve()
{
    SolveRecursively();
    return _sudoku;
}

bool RecursionSolver::SolveRecursively()
{
    idx_t row = 0;
    idx_t col = 0;
    if (!FindUnassignedLocation(row, col))
    {
        return true;
    }
    for (idx_t num = 1; num <= 9; num++)
    {
        if (_sudoku.checkValidity(row, col, num))
        {
            _sudoku.addEntry(row, col, num);
            if (SolveRecursively())
                return true;
            _sudoku.removeEntry(row, col);
        }
    }
    return false;
}

bool RecursionSolver::FindUnassignedLocation(idx_t &row, idx_t &col)
{
    // find empty location, set to row and col
    // return true if location found, else false
    for (idx_t i = 0; i < 9; i++)
    {
        for (idx_t j = 0; j < 9; j++)
        {
            if (!_sudoku.hasEntry(i, j))
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

} /* namespace Solver */

} /* namespace Sudoku */
