#include<iostream>
#include "Chess.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h"
#include "Piece.h"

void Chess::create_board() {
    int i = 0;
    int j = 7;
    
    // add pawns
    for (; i < 8;) {
        Pawn wp(true, 1, i);
        Pawn bp(false, 6, j);
        board[1][i] = wp.get();
        board[6][j] = bp.get();

        i++;
        j--;
    }

    // add empty spaces
    for (i = 2; i < 7; i++) {
        for (j = 2; j < 7; j++) {
            Empty e(i, j);
            board[i][j] = e.get();
            
        }
    }

    // place rooks
    Rook wr1(true, 0, 0);
    Rook wr2(true, 0, 7);
    Rook br1(false, 7, 0);
    Rook br2(false, 7, 7);
    board[0][0] = wr1.get();
    board[0][7] = wr2.get();
    board[7][0] = br1.get();
    board[7][7] = br2.get();

    // place knights
    Knight wk1(true, 0, 1);
    Knight wk2(true, 0, 6);
    Knight bk1(false, 7, 1);
    Knight bk2(false, 7, 6);
    board[0][1] = wk1.get();
    board[0][6] = wk2.get();
    board[7][1] = bk1.get();
    board[7][6] = bk2.get();
    
    // place bishops
    Bishop wb1(true, 0, 2);
    Bishop wb2(true, 0, 5);
    Bishop bb1(false, 7, 2);
    Bishop bb2(false, 7, 5);
    board[0][2] = wb1.get();
    board[0][5] = wb2.get();
    board[7][2] = bb1.get();
    board[7][5] = bb2.get();

    // place queens
    Queen wq1(true, 0, 3);
    Queen bq2(false, 7, 4);
    board[0][2] = wq1.get();
    board[7][5] = bq2.get();

    // place kings
    King wc1(true, 0, 4);
    King bc2(false, 7, 3);
    board[0][2] = wq1.get();
    board[7][5] = bq2.get();

}

void Chess::print_board(){
    for (int i = 0; i < 8; i++) {
        std::cout << (i + 1);
        std::cout << "| ";
        for (int j = 0; j < 8; j++) {
            //empty space
            if (board[i][j]->get_num() == 0)
                std::cout << ". ";

            //white pieces
            else if (board[i][j]->get_num() == pieces["pawn"])
                std::cout << "P ";
            else if (board[i][j]->get_num() == pieces["bishop"])
                std::cout << "B ";
            else if (board[i][j]->get_num() == pieces["knight"])
                std::cout << "K ";
            else if (board[i][j]->get_num() == pieces["rook"])
                std::cout << "R ";
            else if (board[i][j]->get_num() == pieces["queen"])
                std::cout << "Q ";
            else if (board[i][j]->get_num() == pieces["king"])
                std::cout << "C ";

            //black pieces
            else if (board[i][j]->get_num() == pieces["pawn"] * -1)
                std::cout << "p ";
            else if (board[i][j]->get_num() == pieces["bishop"] * -1)
                std::cout << "b ";
            else if (board[i][j]->get_num() == pieces["knight"] * -1)
                std::cout << "k ";
            else if (board[i][j]->get_num() == pieces["rook"] * -1)
                std::cout << "r ";
            else if (board[i][j]->get_num() == pieces["queen"] * -1)
                std::cout << "q ";
            else if (board[i][j]->get_num() == pieces["king"] * -1)
                std::cout << "c ";
            // error
            else
                std::cout << "E ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ________________\n";
    std::cout << "   a b c d e f g h";
    std::cout << "\n";

}

str Chess::get_turn() {
    if (is_white)
        return "White";
    else return "Black";
}

bool Chess::move_piece(str from, str to) {
    // store current move
    int from_col = from[0] - 97;
    int from_row = from[1] - 49;
    Piece* piece = board[from_row][from_col];

    struct move move = {to[1] - 49, to[0] - 97};

    // check if legal move
    if (piece->validate_move(board, move) == false) {
        std::cout << "Not a legal move\n";
        is_white = !is_white;
        print_board();
        return true;
    }

    // perform the move
    Piece* dead_piece = piece->perform_move(board, move);

    // if the move was an attack, push the dead piece to the correct grave
    // and if it was the king, end the game
    if (dead_piece->get_num() < 0) {
        black_grave.push_back(dead_piece);
        if (dead_piece->get_num() == -10) {
            std::cout << "White wins\n";
            return false;
        }
    }
    else if (dead_piece->get_num() > 0) {
        white_grave.push_back(dead_piece);
        if (dead_piece->get_num() == 10) {
            std::cout << "black wins\n";
            return false;
        }
    }

    // print the board
    print_board();
    return true;
}

void Chess::start_game() {
    // store player moves
    str from;
    str to;

    // place the pieces
    create_board();

    // print starting board
    print_board();

    // start the game
    while (game) {

        // get move from player
        std::cout << get_turn() + "'s turn, choose a piece, from where and to where\n";
        std::cin >> from;
        std::cin >> to;
        game = move_piece(from, to);

        //swap turn
        is_white = !is_white;
    }

    // print winning board
    print_board();
}

int main() {
    Chess new_game;
    new_game.start_game();
}