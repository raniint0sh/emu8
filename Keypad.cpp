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