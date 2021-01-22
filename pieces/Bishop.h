#ifndef BISHOP_H
#define BISHOP_H
#include "pieces/Piece.h"

class Bishop: public Piece {
public:
    Bishop(Color c);
    Bishop();

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

#endif // Bishop_H
