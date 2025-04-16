#include <iostream>
#include <string>
#include "Board.h"

/**
 * @brief Main function for the terminal-based chess application.
 * @return int Exit status code.
 */
int main() {
    Board board;
    std::string from, to;
    
    while (true) {
        board.display();
        std::cout << "Enter move (e.g., e2 e4) or 'quit' to exit: ";
        std::cin >> from;
        if (from == "quit")
            break;
        std::cin >> to;
        if (!board.movePiece(from, to)) {
            std::cout << "Move failed. Try again." << std::endl;
        }
    }
    
    return 0;
}
