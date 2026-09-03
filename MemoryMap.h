#include <cstdint>

#ifndef MEMORYMAP_H // include guard
#define MEMORYMAP_H

union memorystructure{
    char charblock[0xFFF];
    uint8_t byteBlock[0xFFF];
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
        uint16_t V[16];
        uint16_t I;
        uint16_t PC;
        uint16_t SP;
        uint8_t DT;
        uint8_t ST;
        uint16_t stack[16];

        inline void incrementPC(){
            PC = PC + 1;
        }

        uint16_t ReadInstruction(uint16_t addr);


};

#endif

