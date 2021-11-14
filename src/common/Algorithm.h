// Created by Paulina Gacek on 06.11.2021.

#ifndef GAMEOFLIFE_ALGORITHM_H
#define GAMEOFLIFE_ALGORITHM_H

#include <iostream>
#include <vector>
#include <chrono>

/**
 * Class implements algorithm which generates next states of the grid
 * according to "The game of life" rules when initial grid is provided
 */

class Algorithm {
public:
    Algorithm(size_t width, size_t length);
    bool load_grid_from_file(const char* file_name);
    void compute_next_grid();
    std::vector<std::vector<int>>& get_grid(){return grid;}

private:
    inline size_t getNrOfAliveNeighbours(size_t x, size_t y)const;
    void display_grid(std::vector<std::vector<int>> &v)const;
    void updateComputationTimeFile(std::chrono::time_point<std::chrono::system_clock> start,
                                   std::chrono::time_point<std::chrono::system_clock> end);
    void clearComputationTimeFile();

    const size_t WIDTH, LENGTH;
    std::vector<std::vector<int>> grid;
};


#endif //GAMEOFLIFE_ALGORITHM_H
