#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>


// 0 - 12 
enum {EMPTY, WPAWN, WKNIGHT, WBISHOP, WROOK, WQUEEN, WKING,BPAWN, BKNIGHT, BBISHOP, BROOK, BQUEEN, BKING};


class Board { 

    private:
        int board[8][8]; 
    
    public:
        Board();
        void print();
        void movePiece(std::string&, std::string&);
        bool canPawnMove(int fromCol, int fromRow, int toCol, int toRow);
        bool canKnightMove(int, int, int, int);
        bool canBishopMove(int, int, int, int);
        bool canRookMove(int, int, int, int);
        bool canQueenMove(int, int, int, int);
        bool canPieceMove(int, int, int, int, int);
        
        
};


