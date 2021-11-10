#include "ConsoleBoard.h"
#include <thread>
#include <conio.h>

void ConsoleBoard::run_game() {
    while(true){
        system("cls");
        display_board();
        algorithm.compute_next_grid();
        board = algorithm.get_grid();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void ConsoleBoard::display_board() {
    for(size_t i = 0 ; i < LENGTH; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            if(board[i][j]==0){
                std::cout << " ";
            }
            else{
                std::cout << "O";
            }
        }
        std::cout << std::endl;
    }
}

ConsoleBoard::ConsoleBoard():algorithm(Algorithm(WIDTH, LENGTH)) {
    std::fstream grid_file;
    grid_file.open("../src/common/config.txt", std::ios::in);
    if (!grid_file) {
        std::cerr << "No such file as config.txt";
    }
    else {
        char mode[20],initial_file[40];
        grid_file.getline(mode, strlen(mode));
        grid_file >> WIDTH >> LENGTH;
        grid_file >> initial_file;
        grid_file.close();
        algorithm.set_size(LENGTH,WIDTH);
        algorithm.load_grid_from_file(initial_file);
        board.reserve(LENGTH);
        std::vector<int> row_with_zeroes(WIDTH,0);
        for(size_t i = 0; i < LENGTH; ++i){
            board.push_back(row_with_zeroes);
        }
        board = algorithm.get_grid();
    }
}
