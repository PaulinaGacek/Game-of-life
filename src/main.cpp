#include <thread>
#include <QApplication>
#include "common/Algorithm.h"
#include "console/ConsoleBoard.h"
#include "qt/QTBoard.h"

int main(int argc, char *argv[]) {
    const char* config_file = "../src/common/config.txt";
    std::fstream grid_file;
    grid_file.open(config_file, std::ios::in);
    if (!grid_file) {
        std::cerr << "No such file as " << config_file << std::endl;
    }
    else {
        size_t width, length, period;
        char mode[20],initial_file[40];
        grid_file.getline(mode, strlen(mode));
        grid_file >> width >> length;
        grid_file >> initial_file;
        grid_file >> period;
        grid_file.close();
        if(strcmp(mode,"CONSOLE")==0){
            ConsoleBoard consoleBoard(initial_file,width,length, period);
            consoleBoard.run_game();
        }
        else if(strcmp(mode,"QT")==0){
            QApplication app(argc, argv);
            Board window(initial_file,width,length, period);
            window.setWindowTitle("The Game Of Life");
            window.show();
            return QApplication::exec();
        }
        else{
            std::cerr << "Improper syntax of config file"<< std::endl;
        }
    }
    return 0;
}
