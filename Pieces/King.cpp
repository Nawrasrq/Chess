#include "King.h"

move_vector King::get_valid_moves(Piece* board[8][8]) {
    move_vector valid_moves;
    move poss_move;

    int boardspace;
    int move_col, move_row;

    // up right diagnol move
    move_row = is_white ? row + 1 : row - 1;
    move_col = is_white ? col + 1 : col - 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // up move
    boardspace = board[move_row][col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, col };
        valid_moves.push_back(poss_move);
    }

    // right move
    boardspace = board[row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { row, move_col };
        valid_moves.push_back(poss_move);
    }

    // down move
    move_row = is_white ? row - 1 : row + 1;
    boardspace = board[move_row][col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, col };
        valid_moves.push_back(poss_move);
    }

    // down right diagnol move
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // down left diagnol move
    move_col = is_white ? col - 1 : col + 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // up left diagnol move
    move_row = is_white ? row + 1 : row - 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        move poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }
    return valid_moves;

}