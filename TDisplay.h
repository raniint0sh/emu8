#include <iostream>
#include <cstdint>
#include <ncurses.h>

#ifndef TDISPLAY_H // include guard
#define TDISPLAY_H

static const int ROW = 32;
static const int COL = 64;


class TDisplay{

public:
    TDisplay();
    ~TDisplay();
    void printDisplay();
    void printDisplay2();


private:

    void clear();
    char m_display[COL][ROW];
    void printFrameLine();

};









#endif