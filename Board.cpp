#include "Board.h"
#include "iostream"
#include "sstream"
#include "math.h"

using namespace std;

Board::Board() {
    for(int i=0; i<=63;i++){
        theSquares[i].setPiece(nullptr);
        theSquares[i].setSquareName(static_cast<SquareName>(i));
    }
    bitboardWhite = 0x0;
    bitboardBlack = 0x0;
    bitboard_p = 0x0;
    bitboard_P = 0x0;
    bitboard_Empty = 0x0;
}

string Board::getFen()
{
    string rawFen, fen;
    for(auto square : theSquares){
        auto sqName = square.getSquareName();
        if(auto piece = square.getPiece()){ //Square is not empty
            rawFen += piece->getFENchar();
            if(sqName==h8||sqName==h7||sqName==h6||sqName==h5||sqName==h4||sqName==h3||sqName==h2)
                rawFen+="/";
        }
        else{//Square is empty
            rawFen+="1";
            if(sqName==h8||sqName==h7||sqName==h6||sqName==h5||sqName==h4||sqName==h3||sqName==h2)
                rawFen+="/";
        }
    }
    //At this point rawFen is filled.
    //Now shrink it.
    int sum=1;
    for(int i=0; i<= rawFen.length(); i++){
        if(rawFen[i]=='1' && rawFen[i+1] == '1'){//Two or more empty squares
            sum++;
        }else{//Is a piece
            if(sum>=2)
                fen+=to_string(sum);
            else
                fen+=rawFen[i];
            sum=1;
        }
    }
    return fen;
}

void Board::printBoard(){
    //Print Board squares with pieces and empty
    int rank =8;
    for(int i=0; i<=63;i++){
        if(i==a8 || i==a7 || i==a6 || i==a5 || i==a4 || i==a3 || i==a2 || i==a1){
            cout<<rank<<" ";
            rank--;
        }
        if(theSquares[i].getPiece()){
            auto p = theSquares[i].getPiece();
            cout <<p->getUnicode()<<" ";
        }else{
            cout<<". ";
        }
        if(i==h8 || i==h7 || i==h6 || i==h5 || i==h4 || i==h3 || i==h2)
            cout<<endl;
    }
    cout<<endl<<"  a b c d e f g h"<<endl<<endl;
}

void Board::printBitboard(uint64_t bb)
{
    int count=8; int rank =8;
    cout<<rank<<" ";
    while(bb){
        if((bb & 1)==1){
            cout<<"o ";
            count--;
        }
        else{
            cout<<". ";
            count--;
        }
        if(count == 0 && rank >=2){
            cout<<endl;
            cout<<--rank<<" ";
            count=8;
        }
        bb = bb >>1;
    }
    cout<<endl<<"  a b c d e f g h"<<endl<<endl;
}

void Board::setFEN(string fen){
    int squareCounter=0;
    Piece *newPiece = nullptr;
    tokenizeRanks(fen);
    for(string rank : theRanks){
        for(char c : rank){
            switch (c) {
            case 'P':
                newPiece = Piece::createNewPiece(PAWN, WHITE);
                addPiece(newPiece, squareCounter);
                bitboard_P |= 1UL << (squareCounter-1);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'R':
                newPiece = Piece::createNewPiece(ROOK, WHITE);
                addPiece(newPiece, squareCounter);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'N':
                newPiece = Piece::createNewPiece(KNIGHT, WHITE);
                addPiece(newPiece, squareCounter);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'B':
                newPiece = Piece::createNewPiece(BISHOP, WHITE);
                addPiece(newPiece, squareCounter);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'Q':
                newPiece = Piece::createNewPiece(QUEEN, WHITE);
                addPiece(newPiece, squareCounter);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'K':
                newPiece = Piece::createNewPiece(KING, WHITE);
                addPiece(newPiece, squareCounter);
                bitboardWhite |= 1UL << (squareCounter-1);
                break;
            case 'p':
                newPiece = Piece::createNewPiece(PAWN, BLACK);
                addPiece(newPiece, squareCounter);
                bitboard_p |= 1UL << (squareCounter-1);
                bitboardBlack |= 1UL << (squareCounter-1);
                break;
            case 'r':
                newPiece = Piece::createNewPiece(ROOK, BLACK);
                addPiece(newPiece, squareCounter);
                bitboardBlack |= 1UL << (squareCounter-1);
                break;
            case 'n':
                newPiece = Piece::createNewPiece(KNIGHT, BLACK);
                addPiece(newPiece, squareCounter);
                bitboardBlack |= 1UL << (squareCounter-1);
                break;
            case 'b':
                newPiece = Piece::createNewPiece(BISHOP, BLACK);
                addPiece(newPiece, squareCounter);
                bitboardBlack |= 1UL << (squareCounter-1);
                break;
            case 'q':
                newPiece = Piece::createNewPiece(QUEEN, BLACK);
                addPiece(newPiece, squareCounter);
                bitboardBlack |= 1UL << (squareCounter-1);
                break;
            case 'k':
                newPiece = Piece::createNewPiece(KING, BLACK);
                addPiece(newPiece, squareCounter);
                bitboardBlack |= 1UL << (squareCounter-1);
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
    //Link all pieces to square.
    for(auto p : thePieces){
        int i = p->getSquare();
        theSquares[i].setPiece(p);
    }
}

void Board::tokenizeRanks(string fen){
    istringstream iss(fen);
    string rank, rank8;
    int i=0;
    while(std::getline(iss, rank, '/')) {
        if(theRanks.size() == 7){
            do{        //Get rank 8, stops in first space.
                if (rank[i] != ' '){
                    rank8 += rank[i];
                    i++;
                }
                else break;
            }while (1);
            theRanks.push_back(rank8);
        }else
            theRanks.push_back(rank);
    }
}

void Board::addPiece(Piece *theNewPiece, int &squareCounter){
    theNewPiece->setSquare((SquareName)squareCounter);
    squareCounter++;
    thePieces.push_back(theNewPiece);
}

void Board::pawnPush(Color player, string movement)
{

    //    if(theMove.length() == 2){//move straight
    //        Square sq = theSquares[2].
    //        for(int i=0; i<=7; i++)
    //        {

    //        }
    //    }else if(move[1]=='x' && move.length() == 3 ){//pawn takes

    //    }
    //    if(move[1] == 'x' ) //pawn takes. exf6
    cout<<"pawn takes"<<endl;
}

void Board::move(Color player, string movement)
{
    parseMove(player,movement);
    moveToBitboard();
    bitToBoard();
}
//get piece, from and where is moving.
void Board::parseMove(Color player, string newMove)
{
    string f;
    stringstream ss;
    int rank;
    myMove.player = player;
    //    if(player == WHITE){
    if(newMove.length()==2){
        myMove.piece = PAWN;
        //Obtain file
        myMove.fileTo = newMove[0];
        //Obtain rank;
        ss<<newMove[1];
        ss>>rank;
        myMove.rankTo =  rank;
        //        }
        //    }else{
    }
    cout<<myMove.fileTo<<myMove.rankTo<<endl;
}

void Board::moveToBitboard(){
    switch (myMove.piece) {
    case PAWN:
        if(myMove.player == WHITE){
            auto pawnToMove = bitboard_P & maskBitboardFile[4];

            //Clear bit of pawnToMove in the 2 bitboards
            bitboard_P ^= pawnToMove;
            bitboardWhite ^= pawnToMove;

            //get squareFrom
            myMove.squareFrom = bitToSquare(pawnToMove);

            //pawn single push
            pawnToMove >>= 8;

            //get squareTo
            myMove.squareTo = bitToSquare(pawnToMove);

            //Add pushed pawn to both bitboards
            bitboard_P = bitboard_P | pawnToMove;
            bitboardWhite = bitboardWhite|pawnToMove;

        }else{}break;
    case ROOK:break;
    case KNIGHT:break;
    case BISHOP:break;
    case QUEEN:break;
    case KING:break;
    }
}

void Board::bitToBoard()
{
    auto pieceToMove = theSquares[myMove.squareFrom].getPiece();//get piece to move
    pieceToMove->setSquare(myMove.squareTo);//assign piece to new square
    theSquares[myMove.squareTo].setPiece(pieceToMove);//assign new square to new piece
    theSquares[myMove.squareFrom].clear();//remove piece from old square
}

    //    int i=0;
    //    while(bitboard_P){//read bit by bit
    //        if(( bitboard_P & 1) == 1){//found pawn
    //            //Push Pawn and update
    //            auto pieceToMove = theSquares[(SquareName)i+8].getPiece(); //get piece to move
    //            pieceToMove->setSquare(static_cast<SquareName>(i+8)); //assign piece to new square
    //            theSquares[i].setPiece(pieceToMove); //assign new square to new piece
    //            theSquares[i+8].clear(); //remove piece from old square.
    //            i++;

    //            //                    //assign new square to all white pawns. pushed all.
    //            //                    //                bitBoard_P = bitBoard_P >>1;
    //        }
    //        else{
    //            //                cout<<0;
    //            i++;
    //        }
    //        bitboard_P = bitboard_P >> 1;
    //    }


void Board::movement(Color player, string theMove)
{
    if(player == WHITE){
        cout<<std::hex << bitboard_P<<endl;
        bitboard_P = bitboard_P >> 8; //push all pawns in bitboard
        cout<<std::hex << bitboard_P<<endl;
        int i=0;
        while(bitboard_P){//read bit by bit
            if(( bitboard_P & 1) == 1){//found pawn
                //                cout<<1;
                //                cout<<i<<" ";

                //Push Pawn and update
                auto pieceToMove = theSquares[(SquareName)i+8].getPiece(); //get piece to move
                pieceToMove->setSquare(static_cast<SquareName>(i+8)); //assign piece to new square
                theSquares[i].setPiece(pieceToMove); //assign new square to new piece
                theSquares[i+8].clear(); //remove piece from old square.
                i++;

                //assign new square to all white pawns. pushed all.
                //                bitBoard_P = bitBoard_P >>1;
            }
            else{
                //                cout<<0;
                i++;
            }
            bitboard_P = bitboard_P >> 1;
        }
    }
    else{
        //        shift <<
    }
}


void Board::fromTo(Square sq1, Square sq2){
    //    auto pieceToMove = sq1
}

SquareName Board::bitToSquare(u_int64_t pieceBitboard)
{
    int squareNumber = 0;
    while (pieceBitboard) {
        if((pieceBitboard & 1) == 0){
            squareNumber++;
        }
        pieceBitboard >>=1;
    }
    return static_cast<SquareName>(squareNumber);
}
