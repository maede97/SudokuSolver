#include <sudokuSolver/solver.hpp>
#include <sudokuSolver/io.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    Sudoku::Sudoku s;
    
    Sudoku::Solver::RecursionSolver solver(s);
    std::cout << solver.solve() << std::endl;
    return 0;
}