#include "SudokuBase.hpp"

namespace Sudoku
{

idx_t countEmpty(Block_t b)
{
    idx_t count = 0;
    for (idx_t i = 0; i < 3; i++)
    {
        for (idx_t j = 0; j < 3; j++)
        {
            if (b(i, j) == 0)
                count++;
        }
    }
    return count;
}

idx_t countEmpty(Sudoku_t s)
{
    idx_t count = 0;
    for (idx_t i = 0; i < 3; i++)
    {
        for (idx_t j = 0; j < 3; j++)
        {
            Block_t b = s.block(i * 3, j * 3, 3, 3);
            count += countEmpty(b);
        }
    }
    return count;
}

Sudoku::Sudoku()
{
    _matrix = Sudoku_t::Zero();
}

bool Sudoku::addEntry(idx_t row, idx_t col, val_t value)
{

    if (!checkValueExist(row, col))
        return false; // check if already a value there
    if (!checkRange(value))
        return false;          // value in [1,9]
    _matrix(row, col) = value; // set value
    if (!check(row, col))
    {
        _matrix(row, col) = 0; // remove value
        return false;
    }
    return true;
}

bool Sudoku::checkValidity(idx_t row, idx_t col, val_t value)
{
    if (!checkValueExist(row, col))
        return false; // check if already a value there
    if (!checkRange(value))
        return false;          // value in [1,9]
    _matrix(row, col) = value; // set value
    if (!check(row, col))
    {
        _matrix(row, col) = 0; // remove value
        return false;
    }
    _matrix(row, col) = 0; // reset
    return true;
}

val_t Sudoku::get(idx_t row, idx_t col) const
{
    val_t val = _matrix(row, col);
    return val;
}

void Sudoku::removeEntry(idx_t row, idx_t col)
{
    _matrix(row, col) = 0;
}

bool Sudoku::hasEntry(idx_t row, idx_t col) const
{
    return !(_matrix(row, col) == 0);
}
Block_t Sudoku::getBlockForEntry(idx_t row, idx_t col) const
{
    idx_t block_row = row / 3;
    idx_t block_col = col / 3;
    return _matrix.block(block_row * 3, block_col * 3, 3, 3);
}

Block_t Sudoku::getBlockFromIndex(idx_t row, idx_t col) const
{
    return _matrix.block(row * 3, col * 3, 3, 3);
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
    val_t value = _matrix(row, col);
    if (value == 0)
        return true; // nothing to check because empty cell

    // check row and col
    for (idx_t i = 0; i < 9; i++)
    {
        if (_matrix(row, i) == value && i != col)
        {
            return false;
        }
        if (_matrix(i, col) == value && i != row)
        {
            return false;
        }
    }

    // check block
    for (idx_t i = block_row * 3; i < block_row * 3 + 3; i++)
    {
        for (idx_t j = block_col * 3; j < block_col * 3 + 3; j++)
        {
            if (i != row && j != col && _matrix(i, j) == value)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::checkRange(val_t value) const
{
    if (value < 1 || value > 9)
    {
        return false;
    }
    return true;
}

/**
     * @brief check if position is empty
     * @param row index of row
     * @param col index of column
     * @return whether check went well
     */
bool Sudoku::checkValueExist(idx_t row, idx_t col) const
{
    if (_matrix(row, col) != 0)
    {
        return false;
    }
    return true;
}
} /* namespace Sudoku */