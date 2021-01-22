#ifndef ROOK_H
#define ROOK_H
#include "pieces/Piece.h"

class Rook: public Piece {
public:
    Rook(Color c);
    Rook();

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

#endif // Rook_H
