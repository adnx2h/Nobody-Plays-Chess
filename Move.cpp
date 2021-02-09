#include "Move.h"
#include "sstream"
#include "iostream"
using namespace std;

Move::Move()
{
    this->fileDst.empty();
    this->rankDst = 0;
}

Move::Move(Color player, string newMove)
{}

//int Move::getRank()
//{
//    return this->rank;
//}

//string Move::getFile()
//{
//    return this->file;
//}

void Move::move(Color player, string newMove)
{
    string f;
    stringstream ss;
    int r;
    if(player == WHITE){
        if(newMove.length()==2){
            //Obtain file
            this->fileDst = newMove[0];
            //Obtain rank;
            ss<<newMove[1];
            ss>>r;
            this->rankDst =  r;
        }
    }else{

    }
}
