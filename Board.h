#ifndef BOARD_H
#define BOARD_H
#include "string"
#include <iostream>
#include "vector"
#include "chessTypes.h"
#include "pieces/Piece.h"
#include "Square.h"

using namespace std;

class Board {
private:
    void tokenizeRanks(string fen);
    void addPiece(Piece *theNewPiece, int &squareCounter);

    vector<string> _ranks;
    Square squares[64];
    vector<Piece*> thePieces;

public:
    Board();
    void getFENPieces(string fen);
    void printBoard();
    void move();
};

#endif // BOARD_H
