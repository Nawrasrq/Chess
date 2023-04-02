#include "Rook.h"

move_vector Rook::get_valid_moves(Piece* board[8][8]){
    /*
            // castling move check rows and cols are correct?
            if(white_castle && is_white){
                if(board[4][7] == 10 && board[5][7] == 0 && board[6][7] == 0 && board[7][7] == 5){
                        if(!check(board[4][7]) && !check(board[5][7]) && !check(board[6][7]) && !check(board[7][7]))
                            move poss_move(6, 7);
                            valid_moves.push_back(poss_move);
                }
            }
            if(black_castle && !is_white){
                if(board[0][0] == 0 && board[1][0] == 0 && board[2][0] == 10 && board[3][0] == 5){
                        if(!check(board[0][0]) && !check(board[1][7]) && !check(board[2][7]) && !check(board[3][7]))
                            move poss_move(6, 7);
                            valid_moves.push_back(poss_move);
                }
            }
            */
    move_vector valid_moves;
    move poss_move;

    short int boardspace;
    int move_col, move_row;
    bool loop = true;

    // up moves
    for (int i = 1; loop; i++) {
        move_row = is_white ? row + i : row - i;
        boardspace = board[move_row][col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = {move_row, col};
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = {move_row, col};
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // down moves
    for (int i = 1; loop; i++) {
        move_row = is_white ? row - i : row + i;
        boardspace = board[move_row][col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = {move_row, col};
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = {move_row, col};
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // right moves
    for (int i = 1; loop; i++) {
        move_col = is_white ? col + 1 : col - 1;
        boardspace = board[row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = {row, move_col};
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = {row, move_col};
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;

    // left moves
    for (int i = 1; loop; i++) {
        move_col = is_white ? col - 1 : col + 1;
        boardspace = board[row][move_col]->get_num();

        // attack moves
        if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
            poss_move = {row, move_col};
            valid_moves.push_back(poss_move);
            loop = false;
        }
        // empty space moves
        if (boardspace == 0) {
            poss_move = {row, move_col};
            valid_moves.push_back(poss_move);
        }
        else
            loop = false;
    }
    loop = true;
    return valid_moves;
}