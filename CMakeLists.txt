cmake_minimum_required(VERSION 3.10)

# Set the project name
project(NobodyPlaysChess)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(NobodyPlaysChess
    Bitboard.cpp
    Board.cpp
    Move.cpp
    Square.cpp
    pieces/King.cpp
    pieces/Queen.cpp
    pieces/Pawn.cpp
    pieces/Rook.cpp
    pieces/Knight.cpp
    pieces/Bishop.cpp
    pieces/Piece.cpp
    main.cpp
)

# Include directories
target_include_directories(NobodyPlaysChess PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/pieces
)