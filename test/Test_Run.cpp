#include <sudokuSolver/io.hpp>
#include <sudokuSolver/solver.hpp>
#include <string>

#include <iostream>

int main(int argc, char *argv[])
{
    Sudoku::Sudoku s = Sudoku::IO::readFile(argv[1]);
    Sudoku::Solver::RecursionSolver solver(s);
    std::cout << solver.solve() << std::endl;
    return 0;
}
