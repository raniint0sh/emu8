#include "MemoryMap.h"


MemoryMap::MemoryMap(){
    for(int i=0; i < 0xFFF; i++){
        m_memory.raw[i] = 0x0000;
    }
}

MemoryMap::~MemoryMap(){

}