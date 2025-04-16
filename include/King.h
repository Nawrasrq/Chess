#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <cstdlib>

/** @brief Represents a King chess piece. */
class King : public Piece {
public:
    /**
     * @brief Initializes a King of specified color.
     * @param c King's Color.
     */
    King(Color c) : Piece(c), moved(false) {}

    /**
     * @brief Retrieves the King's symbol.
     * @return 'K' for white, 'k' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the King.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The King can move one square in any direction.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Gets the moved status of the king.
     * @return true if king has moved; otherwise false.
     */
    bool getMoved() const { return moved; }

    /**
     * @brief Sets the moved status of the king.
     * @param m New moved status.
     */
    void setMoved(bool m) { moved = m; }

    /**
     * @brief Clones the King piece.
     * @return Unique pointer to a new King object.
     */
    std::unique_ptr<Piece> King::clone() const {
        return std::make_unique<King>(*this);
    }

private:
    bool moved;
};

#endif // KING_H
