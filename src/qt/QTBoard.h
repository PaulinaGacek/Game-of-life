#ifndef SNAKE2QT_BOARD_H
#define SNAKE2QT_BOARD_H

#include <QWidget>
#include <QKeyEvent>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "../common/Algorithm.h"

class Board : public QWidget {

public:
    explicit Board(const char* initial_file, int length, int width,size_t period, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    static const int IMAGES = 3;
    QImage aliveStroll, aliveNorris, aliveLeclerc;
    std::vector<std::vector<int>> board;
    Algorithm algorithm;

    const size_t PERIOD;
    const int WIDTH, HEIGHT;
    const int PIXEL_SIZE = 25;
    int timerId = 0;

    void load_images();
    void play_game();
    void animate();
    void display_board();
};

#endif //SNAKE2QT_BOARD_H
