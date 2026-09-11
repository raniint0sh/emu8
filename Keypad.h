#include <cstdint>
#include <iostream>
#include <ncurses.h>


#ifndef KEYPAD_H // include guard
#define KEYPAD_H


class Keypad {

/* The Keypad needs to be

    1 2 3 C
    4 5 6 D
    7 8 9 E
    A 0 B F

    which I will map to:
    to the same letter values.
    to not confuse people.
    understood they won't have the same shape.

*/
public:
uint8_t GetKeypress();
inline void clear(){
    m_keypressed = 0;
}
    bool isKeyPressed(uint8_t key);
    bool isKeyUnpressed(uint8_t key);
    uint8_t toIntChar(uint8_t key);


private:
uint8_t m_keypressed;



};


#endif