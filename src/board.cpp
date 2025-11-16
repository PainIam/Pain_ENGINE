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
//10-8=3
void Board::print() {
    
    std::string pieces = " PNBRQKpnbrqk";

    int count = 8;
    
    for(int i = 0; i < 8; i++) {
        std::cout << count << "   |";
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == EMPTY) {
                std::cout << " __|";
            } else {
                std::cout << ""<<pieces[board[i][j]] << "__|";
            }
        }
        count--;
        std::cout << std::endl;
    }

}
