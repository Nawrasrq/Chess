#include "King.h"

char King::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'K' : 'k';
}

bool King::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    int rowDiff = abs(endRow - startRow);
    int colDiff = abs(endCol - startCol);
    return (rowDiff <= 1 && colDiff <= 1);
}
