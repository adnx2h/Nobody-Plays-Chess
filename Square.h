#ifndef SQUARE_H
#define SQUARE_H
#include "pieces/Piece.h"

class Square
{
public:
    Square();

    void setPiece(Piece *p);
    Piece* getPiece();
    void setSquareName(SquareName c);
    SquareName getSquareName();

private:
    Piece *piece;
    SquareName squareName;
};

#endif // SQUARE_H
