// Created by Paulina Gacek on 05.11.2021.

#ifndef GAMEOFLIFE_CONSOLEBOARD_H
#define GAMEOFLIFE_CONSOLEBOARD_H
#include <vector>
#include <fstream>
#include <iostream>
#include "../common/Algorithm.h"

class ConsoleBoard {
    size_t LENGTH = 0, WIDTH = 0;
    Algorithm algorithm;
    std::vector<std::vector<int>> board;
    void display_board();
public:
    ConsoleBoard();
    void run_game();
};


#endif //GAMEOFLIFE_CONSOLEBOARD_H
