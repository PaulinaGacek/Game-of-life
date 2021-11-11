// Created by Paulina Gacek on 05.11.2021.

#ifndef GAMEOFLIFE_CONSOLEBOARD_H
#define GAMEOFLIFE_CONSOLEBOARD_H
#include <vector>
#include <fstream>
#include <iostream>
#include "../common/Algorithm.h"

class ConsoleBoard {
    const size_t LENGTH, WIDTH;
    Algorithm algorithm;
    std::vector<std::vector<int>> board;
    void display_board();
public:
    ConsoleBoard(const char* initial_state, size_t width, size_t length);
    void run_game();
};


#endif //GAMEOFLIFE_CONSOLEBOARD_H
