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
        case 'q':
            result = 0x4;
            break;
        case 'w':
            result = 0x5;
            break;
        case 'e':
            result = 0x6;
            break;
        case 'a':
            result = 0x7;
            break;
        case 's':
            result = 0x8;
            break;
        case 'd':
            result = 0x9;
            break;
        case 'x':
            result = 0x0;
            break;
        case 'z':
            result = 0xA;
            break;
        case 'c':
            result = 0xB;
            break;
        case '4':
            result = 0xC;
            break;
        case 'r':
            result = 0xD;
            break;
        case 'f':
            result = 0xE;
            break;
        case 'v':
            result = 0xF;
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
    noecho();             // Don't print the keys to the screen
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
    std::cout<< ch << "\n";
    return result;

}

bool Keypad::isKeyUnpressed(uint8_t key){

    initscr();            // Start ncurses mode
    cbreak();             // Grab keystrokes immediately 
    noecho();             // Don't print the keys to the screen
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
            result = 'q';
            break;
        case 0x5:
            result = 'w';
            break;
        case 0x6:
            result = 'e';
            break;
        case 0x7:
            result = 'a';
            break;
        case 0x8:
            result = 's';
            break;
        case 0x9:
            result = 'd';
            break;
        case 0x0:
            result = 'x';
            break;
        case 0xA:
            result = 'z';
            break;
        case 0xB:
            result = 'c';
            break;;
        case 0xC:
            result = '4';
            break;
        case 0xD:
            result = 'r';
            break;
        case 0xE:
            result = 'f';
            break;
        case 0xF:
            result = 'v';
            break;
        default:
            result = 'P';
    }

    return result;

}