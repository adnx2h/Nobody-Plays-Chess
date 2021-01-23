#ifndef QUEEN_H
#define QUEEN_H
#include "pieces/Piece.h"

class Queen: public Piece {
public:
    Queen(Color c);
    Queen();

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

#endif // Queen_H
