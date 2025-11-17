#include "board.h"
#include <iostream>

int main() {

    Board B;
    B.print();


    std::cout << "from : " << std::endl;
    int fromX, fromY;
    std::cin >> fromX >> fromY;

    std::cout << "to : " << std::endl;
    int toX, toY;
    std::cin >> toX >> toY;

    system("clear");
    B.movePiece(fromX, fromY, toX, toY);

}