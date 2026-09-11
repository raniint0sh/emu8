#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <random>
#include <chrono>
#include <thread>
#include "Keypad.h"
#include "Instruction.h"
#include "utilities.h"
#include "MemoryMap.h"
#include "TDisplay.h"

#ifndef EMULATOR_H // include guard
#define EMULATOR_H

class Emulator
{
    public:
        Emulator();
        ~Emulator();
    
        bool LoadRom(std::string romPath);
        bool Run();

    private:
        std::string DEBUG_FILE = "Emu9Debug.txt";
        TDisplay m_display;

        MemoryMap& mem = MemoryMap::getInstance();
        bool DEBUG = true;
        Instruction I;

        double m_hz = 60.0; // Desired frequency in Hz (e.g., 10 times per second)
        bool m_DT_timerStarted;
        bool m_ST_timerStarted;
        std::chrono::steady_clock::time_point m_DT_time;
        std::chrono::steady_clock::time_point m_ST_time;



        bool HandleInstruction();
        bool Instruction_0();
        bool Instruction_1();
        bool Instruction_2();
        bool Instruction_3();
        bool Instruction_4();
        bool Instruction_5();
        bool Instruction_6();
        bool Instruction_7();
        bool Instruction_8();
        bool Inst_8_Nibble_0();
        bool Inst_8_Nibble_1();
        bool Inst_8_Nibble_2();
        bool Inst_8_Nibble_3();
        bool Inst_8_Nibble_4();
        bool Inst_8_Nibble_5();
        bool Inst_8_Nibble_6();
        bool Inst_8_Nibble_7();
        bool Inst_8_Nibble_E();
        bool Instruction_9();
        bool Instruction_A();
        bool Instruction_B();
        bool Instruction_C();
        bool Instruction_D();
        bool Instruction_E();
        bool Inst_E_Byte_9E();
        bool Inst_E_Byte_A1();
        bool Instruction_F();
        bool Inst_F_Byte_07();
        bool Inst_F_Byte_0A();
        bool Inst_F_Byte_15();
        bool Inst_F_Byte_18();
        bool Inst_F_Byte_1E();
        bool Inst_F_Byte_29();
        bool Inst_F_Byte_33();
        bool Inst_F_Byte_55();
        bool Inst_F_Byte_65();
        
        bool Handle_timers();

        
        
        void PrintDebugFile();
        void PrintDebug(uint8_t numberOfArgs, std::string statement, uint16_t arguments[3]);


        Keypad m_keypad;
        std::string m_debugOut;
        uint16_t m_debugArgs[3];
        std::stringstream m_fileBuffer;


        

        
};

#endif