#ifndef CHESSTYPES_H
#define CHESSTYPES_H
#include "string"

using namespace std;
enum SquareName{
    a8,b8,c8,d8,e8,f8,g8,h8,
    a7,b7,c7,d7,e7,f7,g7,h7,
    a6,b6,c6,d6,e6,f6,g6,h6,
    a5,b5,c5,d5,e5,f5,g5,h5,
    a4,b4,c4,d4,e4,f4,g4,h4,
    a3,b3,c3,d3,e3,f3,g3,h3,
    a2,b2,c2,d2,e2,f2,g2,h2,
    a1,b1,c1,d1,e1,f1,g1,h1
};

enum file{
    a,b,c,d,e,f,g,h
};
const u_int64_t maskBitboardFile[8]={
    0x0101010101010101, //file a
    0x0202020202020202, //file b
    0x0404040404040404, //file c
    0x0808080808080808, //file d
    0x1010101010101010, //file e
    0x2020202020202020, //file f
    0x4040404040404040, //file g
    0x8080808080808080}; //file h

//const uint64_t maskBitboardFileH =0x8080808080808080;
//const uint64_t maskBitboardFileG =0x4040404040404040;
//const uint64_t maskBitboardFileF =0x2020202020202020;
//const uint64_t maskBitboardFileE =0x1010101010101010;
//const uint64_t maskBitboardFileD =0x0808080808080808;
//const uint64_t maskBitboardFileC =0x0404040404040404;
//const uint64_t maskBitboardFileB =0x0202020202020202;
//const uint64_t maskBitboardFileA =0x0101010101010101;

enum ChessPiece{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

//typedef to bitboard
//typedef unsigned long long  U64;

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
const static string FEN_MATE = "R2k4/1R6/2B5/pPp2P2/2p1K3/2p4p/P1N2P1P/8 b - - 0 1";
const static string FEN_TRICKY = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
const static string FEN_TEST = "pppppppp/8/8/8/8/8/8/PPPPPPPP w - - 0 1";

#endif // CHESSTYPES_H
