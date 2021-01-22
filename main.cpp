#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board myBoard;
    myBoard.printEmptyBoard();
    myBoard.getPiecesFromFEN(FEN_START);
    myBoard.printBoardTest();
  return 0;
}
