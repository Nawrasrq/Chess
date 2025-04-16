#include "Pawn.h"
#include <cstdlib>

char Pawn::getSymbol() const {
    return (getColor() == Color::WHITE) ? 'P' : 'p';
}

bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;
    if (getColor() == Color::WHITE) {
        // Straight forward moves
        if (startCol == endCol) {
            if (rowDiff == -1) return true;
            else if (!getMoved() && rowDiff == -2) return true;
        }
        // Diagonal move (capture or en passant)
        else if (abs(colDiff) == 1 && rowDiff == -1) {
            return true;
        }
    } else { // Color::BLACK
        if (startCol == endCol) {
            if (rowDiff == 1) return true;
            else if (!getMoved() && rowDiff == 2) return true;
        } else if (abs(colDiff) == 1 && rowDiff == 1) {
            return true;
        }
    }
    return false;
}
