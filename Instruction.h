#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <random>
#include "Keypad.h"
#include "utilities.h"
#include "MemoryMap.h"

#ifndef INSTRUCTION_H // include guard
#define INSTRUCTION_H

class Instruction {

    public:
        Instruction();
        ~Instruction();

        bool Disassemble(uint16_t opcode);
        void clear();

        uint16_t inst;
        uint8_t command;
        uint8_t X;
        uint8_t Y;
        uint8_t byte;
        uint16_t addr;
        uint8_t keypress;
        Keypad m_key;



};



#endif
