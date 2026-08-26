#include <cstdint>

#ifndef MEMORY_H // include guard
#define MEMORY_H

class MemoryMap {

    public:
        MemoryMap();
        ~MemoryMap();

        union memory{
            uint16_t raw[0xFFF];
            char data[0xFFF*2];
        };
        

    memory m_memory;


};

#endif

