#include "Piece.h"
#include "pieces/Pawn.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"

Piece::Piece()
{
}

Piece* Piece::createNewPiece(ChessPiece p, Color c)
{
    Piece *piece = nullptr;
    switch (p) {
    case PAWN:
        piece = new Pawn(c);
        break;
    case ROOK:
        piece = new Rook(c);
        break;
    case KNIGHT:
        piece = new Knight(c);
        break;
    case BISHOP:
        piece = new Bishop(c);
        break;
    case QUEEN:
        piece = new Queen(c);
        break;
    case KING:
        piece = new King(c);
        break;
    default:
        piece = nullptr;
    }
    return piece;
}

//Piece::Piece(Status s)
//{
    //    this->setStatusa(s);
//}
