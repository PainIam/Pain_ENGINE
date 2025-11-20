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

bool Board::canPawnMove(int fromCol, int fromRow, int toCol, int toRow) {

/*
simple pawn movement check
    : checks if the forward squares are empty, no diagnal captures
    : calculates 2 move and 1 move distance
    : super overcomplicated for no reason
*/

    int d = fromRow - toRow;
    
    if (board[fromRow][fromCol] == 1) {
        
        if ((fromRow == 6 && fromCol == toCol) && (d > 0 && d < 3) && (board[fromRow - 1][toCol] == EMPTY && board[toRow][toCol]) == EMPTY)
            return true;
        else if ((fromRow < 6 && fromCol == toCol) && (d > 0 && d < 2) && (fromRow != 0) && board[fromRow-1][toCol] == EMPTY)
            return true;
        else
            return false;

    } else if (board[fromRow][fromCol] == 7) {
        if ((fromRow == 1 && fromCol == toCol) && (d > -3 && d < 0) && (board[fromRow + 1][toCol] == EMPTY && board[toRow][toCol]) == EMPTY) {
            return true;
        } else if ((fromRow > 2 && fromCol == toCol) && (d > -2 && d < 0) && (fromRow != 7) && board[fromRow + 1][toCol] == EMPTY) {
            return true;
        } else
            return false;
    } else 
        return false;

}

bool Board::canKnightMove(int fromCol, int fromRow, int toCol, int toRow) {
    int d1 = abs(fromRow - toRow);
    int d2 = abs(fromCol - toCol);

    if ((d1 == 2) && (d2 == 1))
        return true;
    else if ((d2 == 2) && (d1 == 1))
        return true;
    else
        return false;
    return false;
}

bool Board::canBishopMove(int fromCol, int fromRow, int toCol, int toRow) {

    int d1 = abs(fromCol - toCol);
    int d2 = abs(fromRow - toRow);

    if (d1 == d2)
        return true;

    return false;
}

bool Board::canRookMove(int fromCol, int fromRow, int toCol, int toRow) {

    if ((fromCol == toCol) || (fromRow == toRow))
        return true;
    return false;
}

bool Board::canQueenMove(int fromCol, int fromRow, int toCol, int toRow) {
    /*basically a combo of rook and bishop*/

    int d1 = abs(fromCol - toCol);
    int d2 = abs(fromRow - toRow);

    if ((d1 == d2) || ((fromCol == toCol) || (fromRow == toRow)))
        return true;

    return false;
}

bool Board::canPieceMove(int piece, int fromCol, int fromRow, int toCol, int toRow) {
    if (piece == 1 || piece == 7)
        return canPawnMove(fromCol, fromRow, toCol, toRow);
    else if (piece == 2 || piece == 8)
        return canKnightMove(fromCol, fromRow, toCol, toRow);
    else if (piece == 3 || piece == 9)
        return canBishopMove(fromCol, fromRow, toCol, toRow);
    else if (piece == 4 || piece == 10)
        return canRookMove(fromCol, fromRow, toCol, toRow);
    else if (piece == 5 || piece == 11)
        return canQueenMove(fromCol, fromRow, toCol, toRow);
    
    return false;
            

}

void Board::movePiece(std::string&from, std::string&to) {

    /*
    takes a 2 strings of valid coordinates the converts them to 
    integers and map then into the board as valid indices
    
    */

    int fromCol = from[0] - 'a';
    int fromRow = 8 - (from[1] - '0');

    int toCol = to[0] - 'a';
    int toRow = 8 - (to[1] - '0');


    int temp = board[fromRow][fromCol];
    if(canPieceMove(temp, fromCol, fromRow, toCol, toRow)) {
    board[fromRow][fromCol] = EMPTY;
    board[toRow][toCol] = temp;
    }
    print();

}