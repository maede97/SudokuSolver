#include <sudokuSolver/io.hpp>
#include <sudokuSolver/solver.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    Sudoku::Sudoku s = Sudoku::IO::readFile("../test/examples/sudoku4.txt");
    Sudoku::Solver::RecursionSolver solver(s);
    std::cout << solver.solve() << std::endl;
    return 0;
}
