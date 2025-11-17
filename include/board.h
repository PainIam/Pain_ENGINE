#pragma once
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
        void movePiece(int fromX, int fromY, int toX, int toY);
};


