#ifndef PIECE_H
#define PIECE_H
#include <memory>

/** @brief Abstract base class for all chess pieces. */
enum class Color { WHITE, BLACK };

class Piece {
public:
    /**
     * @brief Initializes a piece of specified color.
     * @param c Piece's Color.
     */
    Piece(Color c) : color(c) {}
    
    /** @brief Destroys the Piece.*/
    virtual ~Piece() {}

    /** @brief Gets the Piece Color.
     * @return Piece's color.
    */
    Color getColor() const { return color; }

    /**
     * @brief Get's the char representation of the piece.
     * @return Character symbol (uppercase for white, lowercase for black).
     */
    virtual char getSymbol() const = 0;

    /**
     * @brief Checks if a move is valid for the piece.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if valid; otherwise false.
     */
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) const = 0;

    /**
     * @brief Creates and returns a copy of this piece.
     * @return A unique_ptr to the cloned piece.
     */
    virtual std::unique_ptr<Piece> clone() const = 0;

protected:
    Color color;
};

#endif // PIECE_H
