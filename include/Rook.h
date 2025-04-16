#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <cstdlib>

/** @brief Represents a Rook chess piece. */
class Rook : public Piece {
public:
    /**
     * @brief Initializes a Rook of specified color.
     * @param c Rook's Color.
     */
    Rook(Color c) : Piece(c), moved(false) {}

    /**
     * @brief Retrieves the Rook's symbol.
     * @return 'R' for white, 'r' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the Rook.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The Rook can move any number of squares along a row or column.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Gets the moved status of the rook.
     * @return true if the rook has moved; otherwise false.
     */
    bool getMoved() const { return moved; }

    /**
     * @brief Sets the moved status of the rook.
     * @param m The new moved status.
     */
    void setMoved(bool m) { moved = m; }

    /**
     * @brief Clones the Rook piece.
     * @return Unique pointer to a new Rook object.
     */
    std::unique_ptr<Piece> Rook::clone() const {
        return std::make_unique<Rook>(*this);
    }

private:
    bool moved;
};

#endif // ROOK_H
