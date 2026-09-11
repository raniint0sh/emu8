#include <atomic>
#include <iostream>
#include <cstdint>
#include <ncurses.h>
#include "MemoryMap.h"

#ifndef TDISPLAY_H // include guard
#define TDISPLAY_H

static const int ROW = 32;
static const int COL = 64;

static uint8_t SPRITE_LENGTH = 8;
static wchar_t BIT_ON = L'\u2588';
//static char BIT_ON = '█';
static wchar_t BIT_OFF = ' ';

class TDisplay{

public:
    TDisplay();
    ~TDisplay();
    void printDisplay();
    void printDisplay2();
    void DrawSprite(uint8_t X, uint8_t Y, uint8_t N);
    void clear();

private:


    char m_display[ROW][COL];
    void printFrameLine();
    MemoryMap& mem = MemoryMap::getInstance();
    

};









#endif