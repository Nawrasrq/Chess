#include "Rook.h"

char Rook::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'R' : 'r';
}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    return (startRow == endRow || startCol == endCol);
}
