#include "Board.h"
#include "iostream"
#include "sstream"

using namespace std;

Board::Board() {
    for(int i=0; i<=63;i++){
        squares[i].setPiece(nullptr);
        squares[i].setSquareName(static_cast<SquareName>(i));
    }
}

void Board::printBoardTest(){
    //Assign pieces to square
    for(auto p : thePieces){
        int i = p->getSquare();
        squares[i].setPiece(p);
    }
    //Print Board squares with pieces and empty
    for(int i=0; i<=63;i++){
        if(squares[i].getPiece()){
            auto p = squares[i].getPiece();
            cout <<p->getUnicode()<<" ";
        }else{
            cout<<"* ";
        }
        if(i==7 || i==15 || i==23 || i==31 || i==39 || i==47 || i==55)
            cout<<endl;
    }
}

void Board::printEmptyBoard(void){
    for(int rank = 9; rank >=1; rank--){
        if(rank >= 2){
            cout<<rank-1<<" ";
            for(int file =1 ;  file<=8;   file++)
                cout<<". ";
        }
        else{
            cout<<"  A B C D E F G H";
        }
        cout<<endl;
    }
}

void Board::getPiecesFromFEN(string fen){
    int squareCounter=0;
    Piece *newPiece = nullptr;
    tokenizeRanks(fen);
    for(string rank : _ranks){
        for(char c : rank){
            switch (c) {
            case 'P':
                newPiece = Piece::createNewPiece(PAWNN, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'R':
                newPiece = Piece::createNewPiece(ROOK, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'N':
                newPiece = Piece::createNewPiece(KNIGHT, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'B':
                newPiece = Piece::createNewPiece(BISHOP, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'Q':
                newPiece = Piece::createNewPiece(QUEEN, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'K':
                newPiece = Piece::createNewPiece(KING, WHITE);
                addPiece(newPiece, squareCounter);
                break;
            case 'p':
                newPiece = Piece::createNewPiece(PAWNN, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case 'r':
                newPiece = Piece::createNewPiece(ROOK, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case 'n':
                newPiece = Piece::createNewPiece(KNIGHT, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case 'b':
                newPiece = Piece::createNewPiece(BISHOP, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case 'q':
                newPiece = Piece::createNewPiece(QUEEN, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case 'k':
                newPiece = Piece::createNewPiece(KING, BLACK);
                addPiece(newPiece, squareCounter);
                break;
            case '1':
                squareCounter+=1; break;
            case '2':
                squareCounter+=2; break;
            case '3':
                squareCounter+=3; break;
            case '4':
                squareCounter+=4; break;
            case '5':
                squareCounter+=5; break;
            case '6':
                squareCounter+=6; break;
            case '7':
                squareCounter+=7; break;
            case '8':
                squareCounter+=8; break;
            }
        }
    }
}
void Board::addPiece(Piece *theNewPiece, int &squareCounter){
    theNewPiece->setSquare((SquareName)squareCounter);
    squareCounter++;
    thePieces.push_back(theNewPiece);
}

void Board::tokenizeRanks(string fen){
    istringstream iss(fen);
    string rank, rank8;
    int i=0;
    while(std::getline(iss, rank, '/')) {
        if(_ranks.size() == 7){
            do{        //Get rank 8, stops in first space.
                if (rank[i] != ' '){
                    rank8 += rank[i];
                    i++;
                }
                else break;
            }while (1);
            _ranks.push_back(rank8);
        }else
            _ranks.push_back(rank);
    }
}

void Board::move()
{
}
