#include "King.h"
King::King(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE){
        this->FENchar = "K";
        this->unicodePiece = W_KING;
    }
    else{
        this->FENchar = "k";
        this->unicodePiece = B_KING;
    }
}

King::King(){
}

void King::setStatus(Status s)
{
    this->status=s;
}

void King::setColor(Color c){
    this->color=c;
}

void King::setSquare(SquareName s)
{
    this->square = s;
}

Color King::getColor()
{
    return this->color;
}

SquareName King::getSquare()
{
    return this->square;
}

string King::getUnicode()
{
    return this->unicodePiece;
}

string King::getFENchar()
{
    return this->FENchar;
}

Status King::getStatus()
{
    return this->status;
}
