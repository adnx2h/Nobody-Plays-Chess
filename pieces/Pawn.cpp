#include "Pawn.h"

Pawn::Pawn(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE)
        this->unicodePiece = W_PAWN;
    else
        this->unicodePiece = B_PAWN;
}

Pawn::Pawn(){
}

void Pawn::setStatus(Status s)
{
    this->status=s;
}

void Pawn::setColor(Color c){
    this->color=c;
}

void Pawn::setSquare(SquareName s)
{
    this->square = s;
}

Color Pawn::getColor()
{
    return this->color;
}

SquareName Pawn::getSquare()
{
    return this->square;
}

string Pawn::getUnicode()
{
    return this->unicodePiece;
}

Status Pawn::getStatus()
{
    return this->status;
}
