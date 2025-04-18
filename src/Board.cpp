#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Board::Board() {
    board.resize(8);
    for (auto &row : board) {
        row.resize(8);
    }
    setupBoard();
}

void Board::display() const {
    for (int i = 0; i < 8; i++) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            std::cout << (board[i][j] ? board[i][j]->getSymbol() : '.') << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  a b c d e f g h" << std::endl;
}

bool Board::convertCoordinate(const std::string& coord, int &row, int &col) const {
    if (coord.length() != 2)
        return false;
    char file = coord[0];
    char rank = coord[1];
    if (file < 'a' || file > 'h' || rank < '1' || rank > '8')
        return false;
    col = file - 'a';
    row = 8 - (rank - '0');
    return true;
}

bool Board::isPathClear(int startRow, int startCol, int endRow, int endCol) const {
    int dRow = endRow - startRow;
    int dCol = endCol - startCol;

    // Determine the direction of movement.
    int stepRow = (dRow == 0) ? 0 : (dRow > 0 ? 1 : -1);
    int stepCol = (dCol == 0) ? 0 : (dCol > 0 ? 1 : -1);

    int currentRow = startRow + stepRow;
    int currentCol = startCol + stepCol;

    // Traverse until reaching (but not including) the destination.
    while (currentRow != endRow || currentCol != endCol) {
        if (board[currentRow][currentCol]) {
            return false;
        }
        currentRow += stepRow;
        currentCol += stepCol;
    }

    return true;
}

void Board::setupBoard() {
    // Black pieces
    board[0][0] = std::make_unique<Rook>(Color::BLACK);
    board[0][1] = std::make_unique<Knight>(Color::BLACK);
    board[0][2] = std::make_unique<Bishop>(Color::BLACK);
    board[0][3] = std::make_unique<Queen>(Color::BLACK);
    board[0][4] = std::make_unique<King>(Color::BLACK);
    board[0][5] = std::make_unique<Bishop>(Color::BLACK);
    board[0][6] = std::make_unique<Knight>(Color::BLACK);
    board[0][7] = std::make_unique<Rook>(Color::BLACK);
    for (int j = 0; j < 8; j++) {
        board[1][j] = std::make_unique<Pawn>(Color::BLACK);
    }
    // White pieces
    board[7][0] = std::make_unique<Rook>(Color::WHITE);
    board[7][1] = std::make_unique<Knight>(Color::WHITE);
    board[7][2] = std::make_unique<Bishop>(Color::WHITE);
    board[7][3] = std::make_unique<Queen>(Color::WHITE);
    board[7][4] = std::make_unique<King>(Color::WHITE);
    board[7][5] = std::make_unique<Bishop>(Color::WHITE);
    board[7][6] = std::make_unique<Knight>(Color::WHITE);
    board[7][7] = std::make_unique<Rook>(Color::WHITE);
    for (int j = 0; j < 8; j++) {
        board[6][j] = std::make_unique<Pawn>(Color::WHITE);
    }
    
}

// Deep copy of the board by cloning each piece.
std::vector<std::vector<std::unique_ptr<Piece>>> Board::cloneBoard() const {
    std::vector<std::vector<std::unique_ptr<Piece>>> copy;
    copy.resize(8);
    for (auto &row : copy) {
        row.resize(8);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]) {
                copy[i][j] = board[i][j]->clone();
            }
        }
    }
    return copy;
}

// Returns true if the king of the given color is currently in check.
bool Board::isInCheck(Color color) const {
    int kingRow = -1, kingCol = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] && board[i][j]->getColor() == color) {
                char symbol = board[i][j]->getSymbol();
                if ((color == Color::WHITE && symbol == 'K') ||
                    (color == Color::BLACK && symbol == 'k')) {
                    kingRow = i;
                    kingCol = j;
                    break;
                }
            }
        }
    }
    if (kingRow == -1)
        return true; // No king found—treat as in check.

    // For every enemy piece, check if it can attack the king.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] && board[i][j]->getColor() != color) {
                if (board[i][j]->isValidMove(i, j, kingRow, kingCol)) {
                    // For long-range pieces, ensure the path is clear.
                    if (dynamic_cast<Queen*>(board[i][j].get()) ||
                        dynamic_cast<Rook*>(board[i][j].get()) ||
                        dynamic_cast<Bishop*>(board[i][j].get())) {
                        if (isPathClear(i, j, kingRow, kingCol))
                            return true;
                    } else {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Simulate the move on a cloned board and check if it would leave the moving side in check.
bool Board::wouldBeInCheckAfterMove(int startRow, int startCol, int endRow, int endCol) {
    Color movingColor = board[startRow][startCol]->getColor();
    auto savedBoard = cloneBoard();
    // Simulate move on the saved board:
    savedBoard[endRow][endCol] = std::move(savedBoard[startRow][startCol]);
    savedBoard[startRow][startCol].reset();
    // Create a temporary Board object with the simulated state.
    Board temp;
    temp.board = std::move(savedBoard);
    return temp.isInCheck(movingColor);
}

// If no legal move prevents check, it's checkmate.
bool Board::isCheckmate(Color color) {
    // Iterate over all pieces of the given color.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] && board[i][j]->getColor() == color) {
                // Try every destination square.
                for (int r = 0; r < 8; r++) {
                    for (int c = 0; c < 8; c++) {
                        if (i == r && j == c)
                            continue;
                        // For long-range moves, check path clearance.
                        if (board[i][j]->isValidMove(i, j, r, c)) {
                            if (dynamic_cast<Queen*>(board[i][j].get()) ||
                                dynamic_cast<Rook*>(board[i][j].get()) ||
                                dynamic_cast<Bishop*>(board[i][j].get())) {
                                if (!isPathClear(i, j, r, c))
                                    continue;
                            }
                            // Simulate the move—if the king is safe, then it's not checkmate.
                            if (!wouldBeInCheckAfterMove(i, j, r, c))
                                return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::movePiece(const std::string& from, const std::string& to) {
    int startRow, startCol, endRow, endCol;
    if (!convertCoordinate(from, startRow, startCol) || !convertCoordinate(to, endRow, endCol)) {
        std::cout << "Invalid coordinate format." << std::endl;
        return false;
    }
    if (!board[startRow][startCol]) {
        std::cout << "No piece at source coordinate." << std::endl;
        return false;
    }

    // Turn management: only allow moves for the current turn.
    if (board[startRow][startCol]->getColor() != currentTurn) {
        std::cout << "It's not your turn." << std::endl;
        return false;
    }

    if (board[endRow][endCol] &&
        board[endRow][endCol]->getColor() == board[startRow][startCol]->getColor()) {
        std::cout << "Cannot capture your own piece." << std::endl;
        return false;
    }

    // For long-range pieces, verify the path is clear.
    if (dynamic_cast<Queen*>(board[startRow][startCol].get()) ||
        dynamic_cast<Rook*>(board[startRow][startCol].get()) ||
        dynamic_cast<Bishop*>(board[startRow][startCol].get())) {
        if (!isPathClear(startRow, startCol, endRow, endCol)) {
            std::cout << "Path is not clear." << std::endl;
            return false;
        }
    }

    // Handle en passant capture for pawn
    Pawn* pawn = dynamic_cast<Pawn*>(board[startRow][startCol].get());
    if (pawn && abs(endCol - startCol) == 1 &&
        ((pawn->getColor() == Color::WHITE && (startRow - endRow == 1)) ||
         (pawn->getColor() == Color::BLACK && (endRow - startRow == 1))) &&
        !board[endRow][endCol])
    {
        if (enPassantAvailable && endRow == enPassantTarget.first && endCol == enPassantTarget.second) {
            int capturedRow = (pawn->getColor() == Color::WHITE) ? endRow + 1 : endRow - 1;
            board[capturedRow][endCol].reset();
        } else {
            std::cout << "Invalid diagonal move for pawn, no piece to capture." << std::endl;
            return false;
        }
    }

    // Handle promotion for pawn
    if (pawn) {
        pawn->setMoved(true);
        if ((pawn->getColor() == Color::WHITE && endRow == 0) ||
            (pawn->getColor() == Color::BLACK && endRow == 7)) {
            Color c = pawn->getColor();
            board[endRow][endCol] = std::make_unique<Queen>(c);
        }
    }

    // Handle castling for king and rook
    King* king = dynamic_cast<King*>(board[startRow][startCol].get());
    if (king && std::abs(endCol - startCol) == 2 && !king->getMoved()) {
        if (endCol > startCol) {  // Kingside castling
            Rook* rook = dynamic_cast<Rook*>(board[startRow][7].get());
            if (rook && !rook->getMoved()) {
                for (int j = startCol + 1; j < 7; ++j) {
                    if (board[startRow][j]) {
                        std::cout << "Path not clear for kingside castling." << std::endl;
                        return false;
                    }
                }
                board[startRow][6] = std::move(board[startRow][startCol]);
                board[startRow][5] = std::move(board[startRow][7]);
                king->setMoved(true);
                rook->setMoved(true);
                enPassantAvailable = false;
                return true;
            } else {
                std::cout << "Kingside rook is not available for castling." << std::endl;
                return false;
            }
        } else {  // Queenside castling
            Rook* rook = dynamic_cast<Rook*>(board[startRow][0].get());
            if (rook && !rook->getMoved()) {
                for (int j = 1; j < startCol; ++j) {
                    if (board[startRow][j]) {
                        std::cout << "Path not clear for queenside castling." << std::endl;
                        return false;
                    }
                }
                board[startRow][2] = std::move(board[startRow][startCol]);
                board[startRow][3] = std::move(board[startRow][0]);
                king->setMoved(true);
                rook->setMoved(true);
                enPassantAvailable = false;
                return true;
            } else {
                std::cout << "Queenside rook is not available for castling." << std::endl;
                return false;
            }
        }
    }
    
    // Validate the move by the piece’s own rules.
    if (!board[startRow][startCol]->isValidMove(startRow, startCol, endRow, endCol)) {
        std::cout << "Invalid move for this piece." << std::endl;
        return false;
    }

    // Simulate the move to ensure it does not leave the king in check.
    if (wouldBeInCheckAfterMove(startRow, startCol, endRow, endCol)) {
        std::cout << "Illegal move: king would be in check." << std::endl;
        return false;
    }
        
    // Perform the move.
    board[endRow][endCol] = std::move(board[startRow][startCol]);

    // Clear the source square.
    if (King* movingKing = dynamic_cast<King*>(board[endRow][endCol].get()))
        movingKing->setMoved(true);
    if (Rook* movingRook = dynamic_cast<Rook*>(board[endRow][endCol].get()))
        movingRook->setMoved(true);

    // Toggle the turn.
    currentTurn = (currentTurn == Color::WHITE) ? Color::BLACK : Color::WHITE;

    // Post-move: check if the opponent is in check or checkmate.
    if (isInCheck(currentTurn)) {
        std::cout << ((currentTurn == Color::WHITE) ? "White" : "Black") << " king is in check." << std::endl;
        if (isCheckmate(currentTurn)) {
            std::cout << "Checkmate! " << ((currentTurn == Color::WHITE) ? "Black" : "White") << " wins!" << std::endl;
        }
    }

    return true;
}


