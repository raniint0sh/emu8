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

