#include "Algorithm.h"
#include <fstream>

Algorithm::Algorithm(size_t width, size_t length) :WIDTH(width),LENGTH(length){
    grid.reserve(length);
    std::vector<int> row_with_zeroes(width,0);
    for(size_t i = 0; i < length; ++i){
        grid.push_back(row_with_zeroes);
    }
}

bool Algorithm::load_grid_from_file(const char *file_name) {
    std::cout << "Load grid from file" << std::endl;
    std::fstream grid_file;
    grid_file.open(file_name, std::ios::in);
    if (!grid_file) {
        std::cerr << "No such file as "<< file_name;
        return false;
    }
    else {
        size_t x,y;
        while (grid_file >> y >> x) {
            if( x < WIDTH && y < LENGTH){
                std::cout << "y: "<< y<< "  x: " << x << std::endl;
                grid[y][x] = 1;
            }
        }
    }
    return true;
}

void Algorithm::display_grid() const {
    for(size_t i = 0 ; i < LENGTH; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
