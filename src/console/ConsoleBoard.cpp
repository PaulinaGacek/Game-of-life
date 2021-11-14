#include "ConsoleBoard.h"
#include <thread>
#include <conio.h>

void ConsoleBoard::run_game() {
    while(true){
        system("cls");
        display_board();
        algorithm.compute_next_grid();
        board = algorithm.get_grid();
        std::this_thread::sleep_for(std::chrono::milliseconds(PERIOD));
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

ConsoleBoard::ConsoleBoard(const char *initial_state, size_t width, size_t length, size_t period):
    LENGTH(length), WIDTH(width), PERIOD(period), algorithm(Algorithm(width, length)) {
    algorithm.load_grid_from_file(initial_state);
    board.reserve(length);
    std::vector<int> row_with_zeroes(width,0);
    for(size_t i = 0; i < length; ++i){
        board.push_back(row_with_zeroes);
    }
    board = algorithm.get_grid();
}
