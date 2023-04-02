#pragma once
#include<vector>


typedef struct move {
	int to_row;
	int to_col;
}move;

typedef std::vector<move> move_vector;

class Piece{
	protected:
		int row,col;
		bool is_white;
		int piece_num;

	    virtual move_vector get_valid_moves(Piece* board[8][8]) = 0;

	public:
		void set_values(bool is_white, int row, int col);

		int get_num();
		Piece* get();
		Piece* perform_move(Piece* board[8][8], move move);
		bool validate_move(Piece* board[8][8], move move);
};

