#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board myBoard;
    myBoard.printBoard();
    myBoard.getFENPieces(FEN_MATE);
    cout<<endl;
    myBoard.printBoard();
  return 0;
}
