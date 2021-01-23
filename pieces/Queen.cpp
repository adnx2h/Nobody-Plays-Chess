#include "Queen.h"
Queen::Queen(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE){
        this->FENchar = "Q";
        this->unicodePiece = W_QUEEN;
    }
    else{
        this->FENchar = "q";
        this->unicodePiece = B_QUEEN;
    }
}

Queen::Queen(){
}

void Queen::setStatus(Status s)
{
    this->status=s;
}

void Queen::setColor(Color c){
    this->color=c;
}

void Queen::setSquare(SquareName s)
{
    this->square = s;
}

Color Queen::getColor()
{
    return this->color;
}

SquareName Queen::getSquare()
{
    return this->square;
}

string Queen::getUnicode()
{
    return this->unicodePiece;
}

string Queen::getFENchar()
{
    return this->FENchar;
}

Status Queen::getStatus()
{
    return this->status;
}
