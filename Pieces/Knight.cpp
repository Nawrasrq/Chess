#include "Knight.h"

move_vector Knight::get_valid_moves(Piece* board[8][8]) {
    move_vector valid_moves;
    move poss_move;

    int boardspace;
    int move_col, move_row;

    // up right diagnol moves
    move_row = is_white ? row + 1 : row - 1;
    move_col = is_white ? col + 2 : col - 2;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    move_row = is_white ? row + 2 : row - 2;
    move_col = is_white ? col + 1 : col - 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // up left diagnol moves
    move_row = is_white ? row + 1 : row - 1;
    move_col = is_white ? col - 2 : col + 2;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    move_row = is_white ? row + 2 : row - 2;
    move_col = is_white ? col - 1 : col + 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // down right diagnol moves
    move_row = is_white ? row - 1 : row + 1;
    move_col = is_white ? col + 2 : col - 2;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    move_row = is_white ? row - 2 : row + 2;
    move_col = is_white ? col + 1 : col - 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    // down left diagnol moves
    move_row = is_white ? row - 1 : row + 1;
    move_col = is_white ? col - 2 : col + 2;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

    move_row = is_white ? row - 2 : row + 2;
    move_col = is_white ? col - 1 : col + 1;
    boardspace = board[move_row][move_col]->get_num();
    if (((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) || boardspace == 0) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }
    
    return valid_moves;
}