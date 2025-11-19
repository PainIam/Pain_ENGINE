#include "board.h"
#include <iostream>

bool valid_input(const std::string& coordinate) {
  
    int range = coordinate[1] - '0';

    return (!(coordinate[0] >= 'a' && coordinate[0] <= 'h') || !(range >= 1 && range <= 8));
}

int main() {

    Board B;
    B.print();

    std::string from;
    std::string to;

    while(true) {
    std::cout << "from : ";
    std::cin >> from;
    while(valid_input(from)) {
        std::cout << "Incorrect input : " << std::endl;
        std::cout << "from : ";
        std::cin >> from;
    }

    std::cout << "to : ";
    std::cin >> to;

    while(valid_input(to)) {
        std::cout << "Incorrect input : " << std::endl;
        std::cout << "to : " << std::endl;
        std::cin >> to;
    }
    system("clear");
    B.movePiece(from, to);
    }

}