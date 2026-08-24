#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>
#include <format>

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
        void Handle_0_instructions(uint16_t instruction);
        void Handle_1_instructions(uint16_t instruction);
        void Handle_2_instructions(uint16_t instruction);
        void Handle_3_instructions(uint16_t instruction);
        void Handle_4_instructions(uint16_t instruction);
        void Handle_5_instructions(uint16_t instruction);
        void Handle_6_instructions(uint16_t instruction);
        void Handle_7_instructions(uint16_t instruction);
        void Handle_8_instructions(uint16_t instruction);

    
};

#endif