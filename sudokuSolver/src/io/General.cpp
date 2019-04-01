#include "General.hpp"


std::ostream &operator<<(std::ostream &os, const Sudoku::Sudoku rhs)
{
    using idx_t = Sudoku::idx_t;
    os << "-------------------------------" << std::endl;
    for (idx_t i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i > 0)
        {
            os << "-------------------------------" << std::endl;
        }
        os << '|';
        for (idx_t j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j > 0)
            {
                os << '|';
            }
            os << ' ' << rhs(i, j) << ' ';
        }
        os << '|' << std::endl;
    }
    os << "-------------------------------";
    return os;
}