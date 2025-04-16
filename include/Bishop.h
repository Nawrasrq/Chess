#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <cstdlib>

/** @brief Represents a Bishop chess piece. */
class Bishop : public Piece {
public:
    /**
     * @brief Initializes a Bishop of specified color.
     * @param c Bishop's Color.
     */
    Bishop(Color c) : Piece(c) {}

    /**
     * @brief Retrieves the Bishop's symbol.
     * @return 'B' for white, 'b' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the Bishop.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The Bishop can move diagonally any number of squares.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Clones the Bishop piece.
     * @return Unique pointer to a new Bishop object.
     */
    std::unique_ptr<Piece> Bishop::clone() const {
        return std::make_unique<Bishop>(*this);
    }

};

#endif // BISHOP_H
