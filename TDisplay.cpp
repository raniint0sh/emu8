#include "TDisplay.h"

TDisplay::TDisplay(){
    clear();
}

TDisplay::~TDisplay(){
}

void TDisplay::printDisplay(){
    printFrameLine();
    for(int row = 0;row < ROW;row++){
        //std::cout << "r" << row <<":";
        for(int col = 0;col < COL;col++){
            std::cout << m_display[col][row];
        }
        std::cout<<'\n';
    }
    printFrameLine();
}

void TDisplay::clear(){
    for(int row = 0;row < ROW;row++){
        for(int col = 0;col < COL;col++){
            m_display[col][row] = ' ';
        }
        std::cout << "\n";
    }

}

void TDisplay::printFrameLine(){
    for(int i=0; i < COL; i++){
        std::cout << '-';
    }
    std::cout<<'\n';
}

void TDisplay::printDisplay2(){
  initscr();


    char map[5][11] = {
        "##########",
        "#        #",
        "#  @     #",
        "#        #",
        "##########"
    };
    // 2. Loop through the rows and columns
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 11; x++) {
            // mvaddch takes: (y_coordinate, x_coordinate, character)
            mvaddch(y, x, map[y][x]);
        }
    }




    for(int row = 0;row < ROW;row++){
        //std::cout << "r" << row <<":";
        for(int col = 0;col < COL;col++){
            mvaddch(row, col, m_display[col][row]);
        }
    }
    



    // Refresh the screen to show the text
    refresh();            

    endwin();

}