#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <cstdlib>

/** @brief Represents a Queen chess piece. */
class Queen : public Piece {
public:
    /**
     * @brief Initializes a Queen of specified color.
     * @param c Queen's Color.
     */
    Queen(Color c) : Piece(c) {}

    /**
     * @brief Retrieves the Queen's symbol.
     * @return 'Q' for white, 'q' for black.
     */
    virtual char getSymbol() const override;

    /**
     * @brief Checks if a move is valid for the Queen.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     * @note The Queen can move any number of squares along a row, column, or diagonal.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const override;

    /**
     * @brief Clones the Queen piece.
     * @return Unique pointer to a new Queen object.
     */
    std::unique_ptr<Piece> Queen::clone() const {
        return std::make_unique<Queen>(*this);
    }

};

#endif // QUEEN_H
