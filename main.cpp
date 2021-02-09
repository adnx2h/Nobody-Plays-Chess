#include "Board.h"
#include <iostream>
//#include "Move.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board *myBoard = new Board();

    myBoard->setFEN(FEN_START);
//    cout<<std::hex<<myBoard.bitBoard_Black<<endl;
//    cout<<std::hex<<myBoard.bitBoard_White<<endl;
    //    cout<<endl;
        myBoard->printBoard();
        myBoard->move(WHITE,"e3");
        myBoard->printBoard();
        myBoard->move(WHITE,"e4");
        myBoard->printBoard();
        myBoard->move(WHITE,"e5");
        myBoard->printBoard();
//        cout<<myBoard.getFen()<<endl;
//        cout<<myBoard->getFile()<<endl;
//        cout<<myBoard->getRank()<<endl;


//        myBoard.move(WHITE,"e4");

//        myBoard.move(BLACK,"e5");
//        myBoard.move(WHITE,"fxg5");
//        myBoard.printBoard();
//        myBoard.move(WHITE,"e4");
//        myBoard.printBoard();
    //    cout<<myBoard.getFen()<<endl;
    return 0;
}
