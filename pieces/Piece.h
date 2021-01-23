#ifndef PIECE_H
#define PIECE_H
#include "chessTypes.h"

class Piece
{
public:
    Piece();
    virtual void setStatus(Status a) = 0;
    virtual void setColor(Color c) = 0;
    virtual void setSquare(SquareName s) = 0;


    virtual Status getStatus() = 0;
    virtual Color getColor() = 0;
    virtual SquareName getSquare() = 0;
    virtual string getUnicode() = 0;
    virtual string getFENchar()= 0;

    static Piece* createNewPiece(ChessPiece p, Color c);
};

#endif // PIECE_H
