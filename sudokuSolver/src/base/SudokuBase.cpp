#include "SudokuBase.hpp"

namespace Sudoku
{

Sudoku::Sudoku(const Sudoku &other)
{
    _matrix = new val_t[81];
    for (idx_t i = 0; i < 9; i++)
    {
        for (idx_t j = 0; j < 9; j++)
        {
            _matrix[i * 9 + j] = other._matrix[i * 9 + j];
        }
    }
}

val_t Sudoku::operator()(idx_t row, idx_t col) const
{
    return _matrix[row * 9 + col];
}

val_t Sudoku::get(idx_t row, idx_t col) const
{
    return _matrix[row * 9 + col];
}

idx_t Sudoku::countEmpty() const
{
    idx_t count = 0;
    for (idx_t i = 0; i < 9; i++)
    {
        for (idx_t j = 0; j < 9; j++)
        {
            if (_matrix[i * 9 + j] == 0)
                count++;
        }
    }
    return count;
}

Sudoku::Sudoku()
{
    _matrix = new val_t[81];
    for (idx_t i = 0; i < 81; i++)
    {
        _matrix[i] = 0;
    }
}

Sudoku::~Sudoku()
{
    delete[] _matrix;
}

bool Sudoku::addEntry(idx_t row, idx_t col, val_t value)
{
    if (checkValueExist(row, col))
    {
        return false; // check if already a value there
    }
    if (!checkRange(value))
    {
        return false; // value in [1,9]
    }
    _matrix[row * 9 + col] = value; // set value
    if (!check(row, col))
    {
        _matrix[row * 9 + col] = 0; // remove value
        return false;
    }
    return true;
}

bool Sudoku::checkValidity(idx_t row, idx_t col, val_t value)
{
    if (checkValueExist(row, col))
        return false; // check if already a value there
    if (!checkRange(value))
        return false;               // value in [1,9]
    _matrix[row * 9 + col] = value; // set value
    if (!check(row, col))
    {
        _matrix[row * 9 + col] = 0; // remove value
        return false;
    }
    _matrix[row * 9 + col] = 0; // reset
    return true;
}

void Sudoku::removeEntry(idx_t row, idx_t col)
{
    _matrix[row * 9 + col] = 0;
}

bool Sudoku::hasEntry(idx_t row, idx_t col) const
{
    return _matrix[row * 9 + col];
}

bool Sudoku::check() const
{
    for (idx_t i = 0; i < 9; i++)
    {
        for (idx_t j = 0; j < 9; j++)
        {
            if (check(i, j) == false)
                return false;
        }
    }
    return true;
}

bool Sudoku::check(idx_t row, idx_t col) const
{
    idx_t block_row = row / 3; // we rely on integer division here
    idx_t block_col = col / 3; // still integer division
    val_t value = _matrix[row * 9 + col];
    if (value == 0)
        return true; // nothing to check because empty cell

    // check row and col
    for (idx_t i = 0; i < 9; i++)
    {
        if (_matrix[row * 9 + i] == value && i != col)
        {
            return false;
        }
        if (_matrix[i * 9 + col] == value && i != row)
        {
            return false;
        }
    }

    // check block
    for (idx_t i = block_row * 3; i < block_row * 3 + 3; i++)
    {
        for (idx_t j = block_col * 3; j < block_col * 3 + 3; j++)
        {
            if (i != row && j != col && _matrix[i * 9 + j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

inline bool Sudoku::checkRange(val_t value) const
{
    return (value >= 1 && value <= 9);
}

inline bool Sudoku::checkValueExist(idx_t row, idx_t col) const
{
    return (_matrix[row * 9 + col] != 0);
}
} /* namespace Sudoku */