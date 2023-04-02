#include <iostream>
#include "Piece.h"
#include "Empty.h"

void Piece::set_values(bool is_white, int row, int col)
{
    this->row = row;
    this->col = col;
    this->is_white = is_white;
}

int Piece::get_num() {
    return this->piece_num;
}

Piece* Piece::get() {
    return this;
}

bool Piece::validate_move(Piece* board[8][8], move move) {
    // validate row and columns
    if (move.to_row < 0 || move.to_row > 7) return false;
    if (move.to_col < 0 || move.to_col > 7) return false;

    // validate piece
    if ((board[row][col]->piece_num < 0 && is_white) || (board[row][col]->piece_num > 0 && !is_white)
        || (board[row][col] == 0)) return false;


    // validate move
    move_vector valid_moves = get_valid_moves(board);

    std::cout << "User's Move\n";
    std::cout << row + 1;
    std::cout << " ";
    std::cout << col + 1;
    std::cout << " ";
    std::cout << board[row][col];
    std::cout << "\n";

    std::cout << move.to_row + 1;
    std::cout << " ";
    std::cout << move.to_col + 1;
    std::cout << " ";
    std::cout << board[move.to_row][move.to_col];
    std::cout << " ";
    std::cout << piece_num;
    std::cout << "\n\n";

    std::cout << "valid Moves for loop\n";
    for (int i = 0; i < valid_moves.size(); i++) {
        std::cout << valid_moves[i].to_row + 1;
        std::cout << " ";
        std::cout << valid_moves[i].to_col + 1;
        std::cout << " ";
        std::cout << board[valid_moves[i].to_row][valid_moves[i].to_col];
        std::cout << "\n";

        if (move.to_row == valid_moves[i].to_row && move.to_col == valid_moves[i].to_col) {
            return true;
        }
    }
    return false;
}

Piece* Piece::perform_move(Piece* board[8][8], move move) {
    Piece* dead_piece;
    //if its a castle then we move two pieces
    if(false){}
    // regular move
    else {
        dead_piece = board[move.to_row][move.to_col];
        board[move.to_row][move.to_col] = this;
        Empty empty(row,col);
        board[row][col] = empty.get();
    }
    return dead_piece;
}
