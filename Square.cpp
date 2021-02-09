#include "Square.h"

Square::Square()
{
}

void Square::setPiece(Piece *p)
{
    this->piece = p;
}

Piece *Square::getPiece()
{
    return this->piece;
}

void Square::setSquareName(SquareName c)
{
    this->squareName = c;
}

SquareName Square::getSquareName()
{
    return this->squareName;
}

void Square::clear()
{
    this->piece = nullptr;
}
