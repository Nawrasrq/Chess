#include "Knight.h"
#include <cstdlib>

char Knight::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'N' : 'n';
}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    int rowDiff = abs(endRow - startRow);
    int colDiff = abs(endCol - startCol);
    return ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2));
}
