#include "Bishop.h"
#include <cstdlib>

char Bishop::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'B' : 'b';
}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    return (abs(endRow - startRow) == abs(endCol - startCol));
}
