#pragma once
#include "Piece.h"

class Bishop : public Piece {
	public:
		Bishop(bool is_white, int row, int col) {
			set_values(is_white, row, col);
			this->is_white ? this->piece_num = 2 : this->piece_num = -1;
		}

		Piece* get() {
			return this;
		}

	move_vector get_valid_moves(Piece* board[8][8]);
};

