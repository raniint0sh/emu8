#include "Keypad.h"



uint8_t Keypad::GetKeypress(){
    char input;
    std::cin>>input;
    uint8_t result;
    switch(input){
        case '1':
            result = 0x1;
            break;
        case '2':
            result = 0x2;
            break;
        case '3':
            result = 0x3;
            break;
        case '4':
            result = 0x4;
            break;
        case '5':
            result = 0x5;
            break;
        case '6':
            result = 0x6;
            break;
        case '7':
            result = 0x7;
            break;
        case '8':
            result = 0x8;
            break;
        case '9':
            result = 0x9;
            break;
        case '0':
            result = 0x1;
            break;
        case 'A':
            result = 0xA;
            break;
        case 'a':
            result = 0xA;
            break;
        case 'B':
            result = 0xB;
            break;
        case 'b':
            result = 0xB;
            break;
        case 'C':
            result = 0xC;
            break;
        case 'c':
            result = 0xC;
            break;
        case 'D':
            result = 0xD;
            break;
        case 'd':
            result = 0xD;
            break;
        case 'E':
            result = 0xE;
            break;
        case 'e':
            result = 0xE;
            break;
        case 'F':
            result = 0xF;
            break;
        case 'f':
            result = 0xf;
            break;
        default:
            std::cout << "***ERROR with KeyPAD!!!!";
            result = 99;
    }

    return result;

}

bool Keypad::isKeyPressed(uint8_t key){

    initscr();            // Start ncurses mode
    cbreak();             // Grab keystrokes immediately 
    //noecho();             // Don't print the keys to the screen
    keypad(stdscr, TRUE); // Enable arrow keys

    nodelay(stdscr, TRUE);

    int ch;
    bool result;
    uint8_t keypressed = toIntChar(key);
    ch = getch();
    if(ch == keypressed){
        result = true;
    }
    else{
        result = false;
    }
    //mvaddch(20, 20, ch);
    refresh();

    return result;

}

bool Keypad::isKeyUnpressed(uint8_t key){

    initscr();            // Start ncurses mode
    cbreak();             // Grab keystrokes immediately 
    //noecho();             // Don't print the keys to the screen
    keypad(stdscr, TRUE); // Enable arrow keys

    nodelay(stdscr, TRUE);

    int ch;
    bool result;
    uint8_t keypressed = toIntChar(key);
    ch = getch();
    if(ch != keypressed){
        result = true;
    }
    else{
        result = false;
    }
    //mvaddch(20, 20, ch);
    refresh();

    return result;

}

uint8_t Keypad::toIntChar(uint8_t key){
    uint8_t result;
    switch(key){
        case 0x1:
            result = '1';
            break;
        case 0x2:
            result = '2';
            break;
        case 0x3:
            result = '3';
            break;
        case 0x4:
            result = '4';
            break;
        case 0x5:
            result = '5';
            break;
        case 0x6:
            result = '6';
            break;
        case 0x7:
            result = '7';
            break;
        case 0x8:
            result = '8';
            break;
        case 0x9:
            result = '9';
            break;
        case 0x0:
            result = '0';
            break;
        case 0xA:
            result = 'a';
            break;
        case 0xB:
            result = 'b';
            break;;
        case 0xC:
            result = 'c';
            break;
        case 0xD:
            result = 'd';
            break;
        case 0xE:
            result = 'e';
            break;
        case 0xF:
            result = 'f';
            break;
        default:
            result = 99;
    }

    return result;

}