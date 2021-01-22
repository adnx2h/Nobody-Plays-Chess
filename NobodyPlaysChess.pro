TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Board.cpp \
        Square.cpp \
        pieces/King.cpp \
        pieces/Queen.cpp \
        pieces/Pawn.cpp \
        pieces/Rook.cpp \
        pieces/Knight.cpp \
        pieces/Bishop.cpp \
        pieces/Piece.cpp \
        main.cpp

HEADERS += \
    Board.h \
    Square.h \
    pieces/King.h \
    pieces/Queen.h \
    pieces/Pawn.h \
    pieces/Rook.h \
    pieces/Knight.h \
    pieces/Bishop.h \
    pieces/Piece.h \
    chessTypes.h
