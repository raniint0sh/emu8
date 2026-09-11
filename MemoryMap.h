#include <cstdint>

#ifndef MEMORYMAP_H // include guard
#define MEMORYMAP_H

union memorystructure{
    char charblock[0xFFF];
    uint8_t byteBlock[0xFFF];
};

enum Fonts:uint16_t{
  
    F0=0x050,
    F1=0x055,
    F2=0x05A,
    F3=0x05F,
    F4=0x064,
    F5=0x069,
    F6=0x06E,
    F7=0x073,
    F8=0x078,
    F9=0x07D,
    FA=0x082,
    FB=0x087,
    FC=0x08C,
    FD=0x091,
    FE=0x095,
    FF=0x09B
};




class MemoryMap {

    private:
        MemoryMap();

    public:
        
        ~MemoryMap();
        
        MemoryMap(const MemoryMap&) = delete;
        MemoryMap& operator=(const MemoryMap&) = delete;
        MemoryMap(MemoryMap&&) = delete;
        MemoryMap& operator=(MemoryMap&&) = delete;    

        static MemoryMap& getInstance() {
        // Guaranteed to be destroyed and initialized thread-safely since C++11
        static MemoryMap instance; 
        return instance;
        }

        memorystructure MEMORY;
        uint8_t V[16];
        uint16_t I;
        uint16_t PC;
        uint16_t SP;
        uint8_t DT;
        uint8_t ST;
        uint16_t stack[16];

        inline void incrementPC(){
            PC = PC + 2;
        }

        uint16_t ReadInstruction(uint16_t addr);
        void LoadFonts();

};

#endif

