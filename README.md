# Chess

A simple Chess program played inside the terminal using C++ and Object-Oriented Programming. 

## Features

- **Terminal-based Chess Game:** Play chess through a simple, text-based interface.
- **Object-Oriented Design:** Uses classes for each piece (King, Queen, Rook, Bishop, Knight, Pawn) derived from an abstract Piece class.
- **Advanced Moves:**  
  - **Castling:** Supports kingside and queenside castling when conditions (e.g., unmoved pieces and clear path) are met.
  - **Pawn Special Moves:** Includes the two-square initial advance, diagonal capturing, en passant capture, and automatic pawn promotion.
- **Game State Management:**  
  - **Turn Management:** Alternates moves between White and Black.
  - **King Safety:** Detects check conditions and prevents moves that would leave the king in check.
  - **Checkmate Detection:** Implements basic checkmate detection by simulating all possible legal moves.
- **Modern C++ Practices:**  
  - Uses `std::unique_ptr` for automatic memory management.
  - Implements deep copying of board state to simulate and validate moves.

## Project Structure

```
ChessTerminalApp/
├── include/
│   ├── Board.h              # Declaration of the Board class
│   ├── Piece.h              # Declaration of the abstract Piece class and Color enum
│   ├── King.h               # Declaration of the King class
│   ├── Queen.h              # Declaration of the Queen class
│   ├── Rook.h               # Declaration of the Rook class
│   ├── Bishop.h             # Declaration of the Bishop class
│   ├── Knight.h             # Declaration of the Knight class
│   └── Pawn.h               # Declaration of the Pawn class
├── src/
│   ├── Board.cpp            # Board class implementation
│   ├── King.cpp             # King class implementation
│   ├── Queen.cpp            # Queen class implementation
│   ├── Rook.cpp             # Rook class implementation
│   ├── Bishop.cpp           # Bishop class implementation
│   ├── Knight.cpp           # Knight class implementation
│   └── Pawn.cpp             # Pawn class implementation
├── main.cpp                 # Entry point for the chess application
└── README.md                # Project documentation
```