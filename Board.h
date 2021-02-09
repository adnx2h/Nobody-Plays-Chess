#ifndef BOARD_H
#define BOARD_H
#include "string"
#include <iostream>
#include "vector"
#include "chessTypes.h"
#include "pieces/Piece.h"
#include "Square.h"
#include "Bitboard.h"
#include "Move.h"

using namespace std;

class Board /*:public Move*/{
private:
    vector<string> theRanks;
    Square theSquares[64];
    vector<Piece*> thePieces;
    void fromTo(Square sq1, Square sq2);
    SquareName bitToSquare(u_int64_t pieceBitboard);

    struct Movement{
        string  fileFrom;
        string fileTo;
        int rankFrom;
        int rankTo;
        SquareName squareFrom;
        SquareName squareTo;
        ChessPiece piece;
        Color player;
    } myMove;

    void tokenizeRanks(string fen);
    void addPiece(Piece *theNewPiece, int &squareCounter);
    void pawnPush(Color player, string movement);
    void parseMove(Color player, string newMove);
    void moveToBitboard();
    void bitToBoard();


public:
    Board();
    void setFEN(string fen);
    string getFen();
    void printBoard();
    void printBitboard(uint64_t bb);
    void movement(Color player, string movement);
    void move(Color player, string movement);


//    Bitboard *bitboardWhite;
//    Bitboard *bitboardBlack;
//    Bitboard *bitboard_p;
//    Bitboard *bitboard_P;
//    Bitboard *bitboard_Empty;

    uint64_t bitboardWhite;
    uint64_t bitboardBlack;
    uint64_t bitboard_p;
    uint64_t bitboard_P;
    uint64_t bitboard_Empty;

};

#endif // BOARD_H
