#include "Rook.h"

Rook::Rook(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE)
        this->unicodePiece = W_ROOK;
    else
        this->unicodePiece = B_ROOK;
}

Rook::Rook(){
}

void Rook::setStatus(Status s)
{
    this->status=s;
}

void Rook::setColor(Color c){
    this->color=c;
}

void Rook::setSquare(SquareName s)
{
    this->square = s;
}

Color Rook::getColor()
{
    return this->color;
}

SquareName Rook::getSquare()
{
    return this->square;
}

string Rook::getUnicode()
{
    return this->unicodePiece;
}

Status Rook::getStatus()
{
    return this->status;
}
