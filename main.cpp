#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board myBoard;
//    myBoard.boardTest();
//    myBoard.printEmptyBoard();
    myBoard.getPiecesFromFEN(FEN_MATE);
//    myBoard.loadFEN(FEN_START);
    myBoard.printBoardTest();
//    myBoard.printSquare(SQUARE::C8);
  return 0;
}
