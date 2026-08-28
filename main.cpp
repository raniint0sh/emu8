#include <cstdint>
#import <iostream>
#include <string>
#import <fstream>

#import "MemoryMap.h"
#import "disassembler.h"
#import "utilities.h"



int main(int argc, char* argv[])
{
    std::cout << argv[1] << std::endl;


    std::ifstream inFile(argv[1], std::ios::binary | std::ios::ate);
    if(!inFile.is_open()){
        std::cerr << "Failed top pen file!!!" << std::endl;
        return 1;
    }
    
    // Since we opened at the end, tellg() gives us the total file size
    int size = inFile.tellg();
    std::cout << size;
    
    // Seek back to the beginning of the file to prepare for reading
    inFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
  
    if(inFile.read(buffer.data(), size)){
        std::cout << "Successfully read " << size << " bytes." << std::endl;
    }




    MemoryMap& mem = MemoryMap::getInstance();
    int j = 0x200;
    for(int i=0; i < size; i++){
        //memoryMap.m_memory.data[i] = buffer[i];
        //mem.MEMORY.charblock[j] = buffer[i];
        mem.MEMORY.byteBlock[j] = static_cast<uint8_t>(buffer[i]);
        j++;
    }
     
    for(int i=0x000; i < 0xFFF; i++){
        //memoryMap.m_memory.raw[i] = util::swapBytes(memoryMap.m_memory.raw[i]);
       mem.MEMORY.block[i] = util::swapBytes(mem.MEMORY.block[i]);
    }
  
    Disassembler dis;
    std::string out;
    std::stringstream m_fileBuffer;
    mem.PC = 0x200;
   for(uint16_t i=0x000; i < 0XFFF; i++){
        uint16_t newPC = mem.PC/2;
        out = util::printMessage2("%d: %X\n", (mem.PC-512), mem.MEMORY.block[newPC]);
        m_fileBuffer << out;

        dis.Disassemble(mem.MEMORY.block[newPC]);

    }



    std::ofstream outputFile("Temp_Out.txt");
    if(outputFile.is_open()){
        outputFile << m_fileBuffer.str();
        outputFile.close();

    }







    dis.Print();

    return 0;
}
