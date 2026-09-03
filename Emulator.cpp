#include "Emulator.h"

Emulator::Emulator(){

}

Emulator::~Emulator(){

}

bool Emulator::LoadRom(std::string romPath)
{
    std::ifstream inFile(romPath, std::ios::binary | std::ios::ate);
    if(!inFile.is_open()){
        std::cerr << "Failed top pen file!!!" << std::endl;
        return false;
    }
    
    // Since we opened at the end, tellg() gives us the total file size
    int size = inFile.tellg();
    
    // Seek back to the beginning of the file to prepare for reading
    inFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
  
    if(inFile.read(buffer.data(), size)){
        std::cout << "Successfully read " << size << " bytes." << std::endl;
    }

    int j = 0x200;
    for(int i=0; i < size; i++){
        mem.MEMORY.byteBlock[j] = static_cast<uint8_t>(buffer[i]);
        j++;
    }
    
    return true;

}