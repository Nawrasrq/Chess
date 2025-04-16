#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <cstdlib>

/** @brief Represents a Knight chess piece. */
class Knight : public Piece {
public:
    /**
     * @brief Initializes a Bishop of specified color.
     * @param c Bishop's Color.
     */
    Knight(Color c) : Piece(c) {}

    /**
     * @brief Retrieves the Knight's symbol.
     * @return 'N' for white, 'n' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the Bishop.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The Knight moves in an "L" shape: two squares in one direction and then one square perpendicular.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Clones the Knight piece.
     * @return Unique pointer to a new Knight object.
     */
    std::unique_ptr<Piece> Knight::clone() const {
        return std::make_unique<Knight>(*this);
    }

};

#endif // KNIGHT_H
