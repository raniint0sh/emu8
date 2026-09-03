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

#ifndef EMULATOR_H // include guard
#define EMULATOR_H

class Emulator
{
    public:
        Emulator();
        ~Emulator();
    
        void Disassemble(uint16_t instruction);
        void Print();

    private:
        MemoryMap& mem = MemoryMap::getInstance();
        bool DEBUG = true;

        void PrintDebug();


        bool LoadRom(std::string romPath);

        

        
};

#endif