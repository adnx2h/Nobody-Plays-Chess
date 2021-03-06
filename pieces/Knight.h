#ifndef KNIGHT_H
#define KNIGHT_H
#include "pieces/Piece.h"

class Knight: public Piece {
public:
    Knight(Color c);
    Knight();

    void setStatus(Status s);
    void setColor(Color c);
    void setSquare(SquareName s);

    Status getStatus();
    Color getColor();
    SquareName getSquare();
    string getUnicode();
    string getFENchar();

private:
    Status status;
    Color color;
    SquareName square;
    string unicodePiece;
    string FENchar;
};

#endif // Knight_H
