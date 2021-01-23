#include "Knight.h"
Knight::Knight(Color c)
{
    this->color = c;
    this->status=ACTIVE;
    if(c == WHITE){
        this->FENchar = "N";
        this->unicodePiece = W_KNIGHT;
    }
    else
    {
        this->FENchar = "n";
        this->unicodePiece = B_KNIGHT;
    }
}

Knight::Knight(){
}

void Knight::setStatus(Status s)
{
    this->status=s;
}

void Knight::setColor(Color c){
    this->color=c;
}

void Knight::setSquare(SquareName s)
{
    this->square = s;
}

Color Knight::getColor()
{
    return this->color;
}

SquareName Knight::getSquare()
{
    return this->square;
}

string Knight::getUnicode()
{
    return this->unicodePiece;
}

string Knight::getFENchar()
{
    return this->FENchar;
}

Status Knight::getStatus()
{
    return this->status;
}
