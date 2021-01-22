#ifndef CHESSTYPES_H
#define CHESSTYPES_H
#include "string"

using namespace std;
enum SquareName{
    A8,B8,C8,D8,E8,F8,G8,H8,
    A7,B7,C7,D7,E7,F7,G7,H7,
    A6,B6,C6,D6,E6,F6,G6,H6,
    A5,B5,C5,D5,E5,F5,G5,H5,
    A4,B4,C4,D4,E4,F4,G4,H4,
    A3,B3,C3,D3,E3,F3,G3,H3,
    A2,B2,C2,D2,E2,F2,G2,H2,
    A1,B1,C1,D1,E1,F1,G1,H1
};

enum ChessPiece{
    PAWNN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

const string W_PAWN = "♙";
const string W_ROOK = "♖";
const string W_KNIGHT = "♘";
const string W_BISHOP = "♗";
const string W_QUEEN = "♕";
const string W_KING = "♔";
const string B_PAWN = "♟︎";
const string B_ROOK = "♜";
const string B_KNIGHT = "♞";
const string B_BISHOP = "♝";
const string B_QUEEN = "♛";
const string B_KING = "♚";
const string EMPTY = "*";

enum Color{
    BLACK,
    WHITE
};

enum Status{
    NOT_ACTIVE,
    ACTIVE
};

const static string FEN_START = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
const static string FEN_FULL = "KKKKKKKK/rrrrrrrr/BBBBBBBB/qqqqqqqq/NNNNNNNN/pppppppp/RRRRRRRR/KKKKKKKK w - - 0 1";
const static string FEN_MATE = "R2k4/1R6/8/pPp2P2/2p1K3/2p4p/P1N2P1P/8 b - - 0 1";
const static string FEN_TRICKY = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
const static string FEN_PYRAMID = "K7/8/8/8/8/8/8/8 w - - 0 1";

#endif // CHESSTYPES_H
