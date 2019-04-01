#include <sudokuSolver/base.hpp>
#include <sudokuSolver/io.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    Sudoku::Sudoku s;
    s.addEntry(0, 0, 3);
    s.addEntry(1, 5, 3);
    s.addEntry(2, 1, 4);

    std::cout << s << std::endl;

    return 0;
}
