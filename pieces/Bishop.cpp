#include "Bishop.h"
Bishop::Bishop(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE){
        this->FENchar = "B";
        this->unicodePiece = W_BISHOP;
    }
    else{
        this->FENchar = "b";
        this->unicodePiece = B_BISHOP;
    }
}

Bishop::Bishop(){
}

void Bishop::setStatus(Status s)
{
    this->status=s;
}

void Bishop::setColor(Color c){
    this->color=c;
}

void Bishop::setSquare(SquareName s)
{
    this->square = s;
}

Color Bishop::getColor()
{
    return this->color;
}

SquareName Bishop::getSquare()
{
    return this->square;
}

string Bishop::getUnicode()
{
    return this->unicodePiece;
}

string Bishop::getFENchar()
{
    return this->FENchar;
}

Status Bishop::getStatus()
{
    return this->status;
}
