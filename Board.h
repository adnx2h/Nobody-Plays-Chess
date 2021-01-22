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
    void incrementSquare(int &squareCounter);
    void setEmptySquare(int i, int &squareCounter);
    void addPiece(Piece *theNewPiece, int &squareCounter);

    vector<string> _ranks;
    SquareState _board[64]; //delete
    Square squares[64];
    vector<Piece*> thePieces;

public:
    Board();
    void printEmptyBoard(void);
    void printSquare(SquareName sq);
    void printSquareObj(SquareName sq);
    void loadFEN(string fen);
    void getPiecesFromFEN(string fen);
    string getBoardFen();
    void printFEN();
    void move();
    void printBoardTest();
};

#endif // BOARD_H
