#ifndef KING_H
#define KING_H
#include "pieces/Piece.h"

class King: public Piece {
public:
    King(Color c);
    King();

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

#endif // King_H
