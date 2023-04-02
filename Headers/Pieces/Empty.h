#pragma once
#include "Piece.h"

class Empty : public Piece{
	public:
		Empty(int row, int col) {
			set_values(false, row, col);
			this->piece_num = 0;
		}

		move_vector get_valid_moves(Piece* board[8][8]);
};

