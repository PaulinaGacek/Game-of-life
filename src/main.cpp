#include <iostream>
#include "common/Algorithm.h"
#include "fstream"

int main() {
    std::fstream grid_file;
    grid_file.open("../src/common/config.txt", std::ios::in);
    if (!grid_file) {
        std::cerr << "No such file as config.txt";
    }
    else {
        size_t width, length;
        char mode[20],initial_file[40];
        grid_file.getline(mode, strlen(mode));
        grid_file >> width >> length;
        std::cout << width << " "<< length<< std::endl;
        grid_file >> initial_file;
        std::cout << initial_file;
        grid_file.close();
        Algorithm algorithm(width, length);
        algorithm.load_grid_from_file(initial_file);
        algorithm.display_grid();
    }
    return 0;
}
