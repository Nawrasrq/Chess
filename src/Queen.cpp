#include "Queen.h"
#include <cstdlib>

char Queen::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'Q' : 'q';
}

bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    int rowDiff = abs(endRow - startRow);
    int colDiff = abs(endCol - startCol);

    // Valid move if moving in a straight line.
    if (startRow == endRow || startCol == endCol)
        return true;

    // Valid move if moving diagonally.
    if (rowDiff == colDiff)
        return true;

    return false;
}
