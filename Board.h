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
    void printEmptyBoard(void);
    void loadFEN(string fen);
    void getPiecesFromFEN(string fen);
    void move();
    void printBoardTest();
};

#endif // BOARD_H
