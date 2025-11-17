#include "board.h"

Board::Board() {
        int start[8][8] =  {
            {BROOK, BKNIGHT, BBISHOP, BQUEEN, BKING, BBISHOP, BKNIGHT, BROOK}, 
            {BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
            {WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN},
            {WROOK, WKNIGHT, WBISHOP, WQUEEN, WKING, WBISHOP, WKNIGHT, WROOK}
        };

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                board[i][j] = start[i][j]; // initialize the board
            }
        }
};



/*
print function which works by mapping a string index t
to the enum number on the board
*/

void Board::print() {
    
    std::string pieces = " PNBRQKpnbrqk";

    int count = 8;
    
    for(int i = 0; i < 8; i++) {
        std::cout << count << "   |";
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == EMPTY) {
                std::cout << " __|";
            } else {
                std::cout << ""<< pieces[board[i][j]] << "__|"; // map enum number to string pieces 
            }
        }
        count--;
        std::cout << std::endl;
    }
    std::cout << "      a   b   c   d   e   f   g   h" << std::endl;
}

/*
move fn, no legal move checks, 
*/

void Board::movePiece(int fromX, int fromY, int toX, int toY) {

    int temp = board[fromX][fromY];
    board[fromX][fromY] = EMPTY;
    board[toX][toY] = temp;
    print();

}