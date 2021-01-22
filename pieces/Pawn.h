#ifndef PAWN_H
#define PAWN_H
#include "pieces/Piece.h"

class Pawn: public Piece {
public:
    Pawn(Color c);
    Pawn();

    void setStatus(Status s);
    void setColor(Color c);
    void setSquare(SquareName s);

    Status getStatus();
    Color getColor();
    SquareName getSquare();
    string getUnicode();

private:
    Status status;
    Color color;
    SquareName square;
    string unicodePiece;
};

#endif // PAWN_H
