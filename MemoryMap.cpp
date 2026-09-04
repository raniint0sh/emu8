#include "MemoryMap.h"


MemoryMap::MemoryMap(){
    for(int i=0; i < 0xFFF; i++){
        MEMORY.byteBlock[i] = 0x0000;
    }
    for(int i=0; i < 16; i++){
        V[i] = 0;
        stack[i] = 0;
    }
    I = 0;
    PC = 0;
    SP = 0;
    DT = 0;
    ST = 0;


}

MemoryMap::~MemoryMap(){

}

uint16_t MemoryMap::ReadInstruction(uint16_t addr){
    uint16_t result = 0;
    result = MEMORY.byteBlock[addr] << 8;
    result = result + MEMORY.byteBlock[addr + 1];
    PC = PC + 2;
return result;


}

