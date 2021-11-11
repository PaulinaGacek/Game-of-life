#include <QPainter>
#include <QTime>
#include "QTBoard.h"
#include <ctime>

Board::Board(const char* initial_file, int length, int width, QWidget *parent):
        QWidget(parent), HEIGHT(length), WIDTH(width), algorithm(Algorithm(width, length)){
    algorithm.load_grid_from_file(initial_file);
    board.reserve(length);
    std::vector<int> row_with_zeroes(width, 0);
    for(size_t i = 0; i < length; ++i){
        board.push_back(row_with_zeroes);
    }
    board = algorithm.get_grid();
    setStyleSheet("background-color: rgb(216, 216, 209)");
    setFixedSize(length * PIXEL_SIZE, width * PIXEL_SIZE);
    load_images();
    play_game();
}

void Board::load_images() {
    alive.load("../Helmets/LanceStrollMini.png");
}

void Board::play_game() {
    algorithm.compute_next_grid();
    board = algorithm.get_grid();
    timerId = startTimer(DELAY);
}

void Board::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    display_board();
}

void Board::display_board() {

    QPainter qp(this);
    for(size_t i = 0 ; i < HEIGHT; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            if(board[i][j]==1)
                qp.drawImage(i*PIXEL_SIZE,j*PIXEL_SIZE,alive);
        }
    }
}

void Board::animate() {
    algorithm.compute_next_grid();
    board = algorithm.get_grid();
}

void Board::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    animate(); // changes the state
    repaint();
}

void Board::keyPressEvent(QKeyEvent *e) {
    int key = e->key();
    if (key == Qt::Key_Pause)
        std::cout << "Key pressed";
    QWidget::keyPressEvent(e);
}



