#include <sudokuSolver/base.hpp>
#include <sudokuSolver/io.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    Sudoku::Sudoku s = Sudoku::IO::generateFromFile("../test/examples/sudoku1.txt");
    std::cout << s << std::endl;
    return 0;
}
