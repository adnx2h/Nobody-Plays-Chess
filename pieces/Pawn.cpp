#include "Pawn.h"

Pawn::Pawn(Color c)
{
    this->color = c;
    this->status=ACTIVE;

    if(c == WHITE){
        this->FENchar = "P";
        this->unicodePiece = W_PAWN;
    }
    else{
        this->unicodePiece = B_PAWN;
        this->FENchar = "p";
    }
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

string Pawn::getFENchar()
{
    return this->FENchar;
}

Status Pawn::getStatus()
{
    return this->status;
}
