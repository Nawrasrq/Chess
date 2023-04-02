#pragma once
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include "Piece.h"

typedef std::string str;
typedef std::map<std::string, int> dict;

class Chess {
private:
    bool game = true;
    bool is_white = true;
    bool white_castle = true;
    bool black_castle = true;

    dict pieces = {
        { "pawn", 1 },
        { "bishop", 2 },
        { "knight", 3 },
        { "rook", 5 },
        { "queen", 6 },
        { "king", 10 },
    };

    std::vector<Piece*> white_grave;
    std::vector<Piece*> black_grave;

    Piece* board[8][8];

    // double distance(int x1, int y1, int x2, int y2);
    void create_board();
    void print_board();
    str get_turn();

    bool move_piece(str from, str to);

public:
    void start_game();
};
