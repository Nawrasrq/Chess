#include "Pawn.h"

move_vector Pawn::get_valid_moves(Piece* board[8][8]){
    move_vector valid_moves;
    move poss_move;

    int boardspace;
    int move_col, move_row;

    // empty space moves
    move_row = is_white ? row + 1 : row - 1;
    boardspace = board[move_row][col]->get_num();

    if (boardspace == 0) {
        poss_move = {move_row, col};
        valid_moves.push_back(poss_move);
    }

    // check if pawn moved
    if ((is_white && row == 1) || (!is_white && row == 6)) {
        move_row = is_white ? row + 2 : row - 2;

        boardspace = board[move_row][col]->get_num();
        if (boardspace == 0) {
            poss_move = { move_row, col };
            valid_moves.push_back(poss_move);
        }
    }

    // attack right
    move_row = is_white ? row + 1 : row - 1;
    move_col = col + 1;
    boardspace = board[move_row][move_col]->get_num();
    if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }
    // attack left
    move_col = col - 1;
    boardspace = board[move_row][move_col]->get_num();
    if ((boardspace < 0 && is_white) || (boardspace > 0 && !is_white)) {
        poss_move = { move_row, move_col };
        valid_moves.push_back(poss_move);
    }

	return valid_moves;
}
