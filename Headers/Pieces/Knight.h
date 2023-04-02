#pragma once
#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(bool is_white, int row, int col) {
			set_values(is_white, row, col);
			this->is_white ? this->piece_num = 1 : this->piece_num = -1;
		}

		move_vector get_valid_moves(Piece* board[8][8]);
};

