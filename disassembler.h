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

#ifndef DISASEMBLER_H // include guard
#define DISASEMBLER_H

class Disassembler
{
    public:
        Disassembler();
        ~Disassembler();
    
        void Disassemble(uint16_t instruction);
        void Print();

    private:
        std::stringstream m_fileBuffer;
        std::string m_outString;
        uint8_t X;
        uint8_t Y;
        uint8_t byte;
        uint16_t addr;
        uint8_t keypress;
        Keypad m_key;


        void Handle_0_instructions(uint16_t instruction);
        void Handle_1_instructions(uint16_t instruction);
        void Handle_2_instructions(uint16_t instruction);
        void Handle_3_instructions(uint16_t instruction);
        void Handle_4_instructions(uint16_t instruction);
        void Handle_5_instructions(uint16_t instruction);
        void Handle_6_instructions(uint16_t instruction);
        void Handle_7_instructions(uint16_t instruction);
        void Handle_8_instructions(uint16_t instruction);
        void Handle_9_instructions(uint16_t instruction);
        void Handle_A_instructions(uint16_t instruction);
        void Handle_B_instructions(uint16_t instruction);
        void Handle_C_instructions(uint16_t instruction);
        void Handle_D_instructions(uint16_t instruction);
        void Handle_E_instructions(uint16_t instruction);
        void Handle_F_instructions(uint16_t instruction);

        void DrawSprite(uint8_t byte);

        MemoryMap& mem = MemoryMap::getInstance();
};

#endif