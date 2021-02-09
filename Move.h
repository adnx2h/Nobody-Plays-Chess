#ifndef MOVE_H
#define MOVE_H
#include "string"
#include "chessTypes.h"

using namespace std;

class Move
{
public:
    Move();
    Move(Color player, string newMove);
//    int getRank();
//    string getFile();
    void move(Color player, string newMove);

private:
    string fileDst;
    int rankDst;
};

#endif // MOVE_H
