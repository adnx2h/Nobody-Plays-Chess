#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board myBoard;

    myBoard.setFEN(FEN_START);
    cout<<endl;
    myBoard.printBoard();
    cout <<myBoard.getFen();
  return 0;
}
