#include "Bishop.h"

move_vector Bishop::get_valid_moves(Piece* board[8][8]) {
    move_vector valid_moves;
    move poss_move;

    bool loop = true;
    int boardspace;
    int move_col, move_row;

    // up right diagnol moves
    for (int i = 1; loop; i++) {
        move_row = is_white ? row + i : row - i;
        move_col = col + i;
        boardspace = board[move_row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }

        // empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // up left diagnol moves
    for (int i = 1; loop; i++) {
        move_col = col - i;
        move_row = is_white ? row + i : row - i;
        boardspace = board[move_row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // down right diagnol moves
    for (int i = 1; loop; i++) {
        move_col = col;
        move_row = is_white ? row - i : row + i;
        boardspace = board[move_row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // down left diagnol moves
    for (int i = 1; loop; i++) {
        move_col = col - i;
        move_row = is_white ? row - i : row + i;
        boardspace = board[move_row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        //empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;
    return valid_moves;
}