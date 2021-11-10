// Created by Paulina Gacek on 06.11.2021.

#ifndef GAMEOFLIFE_ALGORITHM_H
#define GAMEOFLIFE_ALGORITHM_H

#include <iostream>
#include <vector>

class Algorithm {
public:
    Algorithm(size_t width, size_t length);
    bool load_grid_from_file(const char* file_name);
    void compute_next_grid();
    void display_grid(std::vector<std::vector<int>> &v)const;
    std::vector<std::vector<int>>& get_grid(){return grid;}
    inline size_t getNrOfAliveNeighbours(size_t x, size_t y)const;
    void set_size(size_t length, size_t width);

private:
    size_t WIDTH, LENGTH;
    std::vector<std::vector<int>> grid;

};


#endif //GAMEOFLIFE_ALGORITHM_H
