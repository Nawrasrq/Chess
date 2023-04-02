#pragma once
#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(bool is_white, int row, int col) {
			set_values(is_white, row, col);
			this->is_white ? this->piece_num = 5 : this->piece_num = -5;
		}

		move_vector get_valid_moves(Piece* board[8][8]);
};

