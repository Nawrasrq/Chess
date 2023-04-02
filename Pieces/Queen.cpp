#include "Queen.h"

move_vector Queen::get_valid_moves(Piece* board[8][8]) {
    move_vector valid_moves;
    move poss_move;

    int boardspace;
    int move_col, move_row;
    bool loop = true;

    // up moves
    for (int i = 1; loop; i++) {
        move_row = is_white ? row + i : row - i;
        boardspace = board[move_row][col]->get_num();;

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // down moves
    for (int i = 1; loop; i++) {
        move_row = is_white ? row - i : row + i;
        boardspace = board[move_row][col]->get_num();;

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { move_row, col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { move_row, col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // right moves
    for (int i = 1; loop; i++) {
        move_col = is_white ? col + 1 : col - 1;
        boardspace = board[row][move_col]->get_num();;

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // left moves
    for (int i = 1; loop; i++) {
        move_col = is_white ? col - 1 : col + 1;
        boardspace = board[row][move_col]->get_num();;

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = { row, move_col };
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = { row, move_col };
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // up right diagnol moves
    for (int i = 1; loop; i++) {
        move_col = is_white ? col + 1 : col - 1;
        move_row = is_white ? row + 1 : row - 1;
        boardspace = board[move_row][move_col]->get_num();;

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
        move_col = is_white ? col - 1 : col + 1;
        move_row = is_white ? row + 1 : row - 1;
        boardspace = board[move_row][move_col]->get_num();;

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
        move_col = is_white ? col + 1 : col - 1;
        move_row = is_white ? row - 1 : row + 1;
        boardspace = board[move_row][move_col]->get_num();;

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
        move_col = is_white ? col - 1 : col + 1;
        move_row = is_white ? row - 1 : row + 1;
        boardspace = board[move_row][move_col]->get_num();;

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
    return valid_moves;
}