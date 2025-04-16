#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <memory>
#include "Piece.h"

using namespace std;

/** @brief Manages the chess board and game state. */
class Board {
public:
    /** @brief Constructs a Board with pieces in their initial positions. */
    Board();

    /** @brief Destroys the Board. */
    ~Board() = default;

    /** @brief Displays the current board state in the terminal. */
    void display() const;

    /**
     * @brief Moves a piece from one coordinate to another.
     * @param from Source coordinate in algebraic notation (e.g., "e2").
     * @param to Destination coordinate in algebraic notation (e.g., "e4").
     * @return true if successful; otherwise false.
     */
    bool movePiece(const std::string& from, const std::string& to);

private:
    std::vector<std::vector<std::unique_ptr<Piece>>> board;

    /** @brief Initializes the board with the default chess starting positions. */
    void setupBoard();

    /**
     * @brief Converts an algebraic coordinate into board indices.
     * @param coord The coordinate string (e.g., "e2").
     * @param row Output parameter for the row index.
     * @param col Output parameter for the column index.
     * @return true if successful; otherwise false.
     */
    bool convertCoordinate(const std::string& coord, int &row, int &col) const;

    /**
     * @brief Checks if the path between two squares is clear.
     * @param startRow Starting row index.
     * @param startCol Starting column index.
     * @param endRow Ending row index.
     * @param endCol Ending column index.
     * @return true if the path is clear; otherwise false.
     */
    bool isPathClear(int startRow, int startCol, int endRow, int endCol) const;

    // Turn management: tracks whose turn it is (White starts).
    Color currentTurn = Color::WHITE;

    // King safety and check/checkmate detection.
    bool isInCheck(Color color) const;
    bool wouldBeInCheckAfterMove(int startRow, int startCol, int endRow, int endCol);
    bool isCheckmate(Color color);

    // Returns a deep copy of the board for simulation.
    std::vector<std::vector<std::unique_ptr<Piece>>> cloneBoard() const;

    // For en passant capture.
    std::pair<int, int> enPassantTarget; 
    bool enPassantAvailable = false;    
};

#endif // BOARD_H
