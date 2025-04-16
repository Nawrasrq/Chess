#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

/** @brief Represents a Pawn chess piece. */
class Pawn : public Piece {
public:
    /**
     * @brief Initializes a Bishop of specified color.
     * @param c Pawn's Color.
     */
    Pawn(Color c) : Piece(c), moved(false) {}

    /**
     * @brief Retrieves the Pawn's symbol.
     * @return 'P' for white, 'p' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the Pawn.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The Pawn moves forward one square, or two squares from its starting position. It captures diagonally.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Gets the moved status of the pawn.
     * @return true if moved; otherwise false.
     */
    bool getMoved() const { return moved; }

    /**
     * @brief Sets the moved status of the pawn.
     * @param m The new moved status.
     */
    void setMoved(bool m) { moved = m; }

    /**
     * @brief Clones the Pawn piece.
     * @return Unique pointer to a new Pawn object.
     */
    std::unique_ptr<Piece> Pawn::clone() const {
        return std::make_unique<Pawn>(*this);
    }

private:
    bool moved;
};

#endif // PAWN_H
