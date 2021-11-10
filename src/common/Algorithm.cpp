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
                grid[y][x] = 1;
            }
        }
    }
    return true;
}

void Algorithm::display_grid(std::vector<std::vector<int>> &v) const {
    for(size_t i = 0 ; i < LENGTH; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

size_t Algorithm::getNrOfAliveNeighbours(size_t x, size_t y) const {
    size_t aliveNeighbours = 0;
    if (x > 0){
        aliveNeighbours += grid[y][x - 1];
        if(y > 0){
            aliveNeighbours += grid[y - 1][x - 1];
            aliveNeighbours += grid[y-1][x];
        }
        if(y < LENGTH-1){
            aliveNeighbours += grid[y+1][x-1];
            aliveNeighbours += grid[y+1][x];
        }
    }
    if(x < WIDTH-1){
        aliveNeighbours += grid[y][x + 1];
        if(y > 0){
            aliveNeighbours += grid[y-1][x + 1];
        }
        if(y < LENGTH-1){
            aliveNeighbours += grid[y+1][x + 1];
        }
    }
    return aliveNeighbours;
}

void Algorithm::compute_next_grid() {
    std::vector<std::vector<int>> new_grid;
    new_grid.reserve(LENGTH);
    std::vector<int> row_with_zeroes(WIDTH,0);
    for(size_t i = 0; i < LENGTH; ++i){
        new_grid.push_back(row_with_zeroes);
    }
    for(size_t i = 0; i < LENGTH; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            size_t aliveNeighbours = getNrOfAliveNeighbours(j,i);
            if(grid[i][j]==0 && aliveNeighbours == 3){
                new_grid[i][j] = 1;
            }
            else if(grid[i][j]==1){
                if(aliveNeighbours==2 || aliveNeighbours==3)
                    new_grid[i][j] = 1;
            }
        }
    }
    grid = std::move(new_grid);
}

void Algorithm::set_size(size_t length, size_t width) {
    WIDTH = width;
    LENGTH = length;

    std::vector<std::vector<int>> grid2;
    grid2.reserve(length);
    std::vector<int> row_with_zeroes(width,0);
    for(size_t i = 0; i < length; ++i){
        grid2.push_back(row_with_zeroes);
    }
    grid = std::move(grid2);
}
