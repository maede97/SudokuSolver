#include <sudokuSolver/base.hpp>
#include <sudokuSolver/io.hpp>
#include <sudokuSolver/solver.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    Sudoku::Sudoku s = Sudoku::IO::generateFromFile("../test/examples/sudoku1.txt");
    Sudoku::Solver::BruteForce solver(s);
    solver.solve();
    std::cout << solver.getSudoku() << std::endl;
    return 0;
}
