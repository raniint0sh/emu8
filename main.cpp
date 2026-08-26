#import <iostream>
#include <string>
#include <iterator>
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




    MemoryMap memoryMap;
    for(int i=0; i < size; i++){
        memoryMap.m_memory.data[i] = buffer[i];
    }

    for(int i=0x000; i < 0xFFF; i++){
        memoryMap.m_memory.raw[i] = util::swapBytes(memoryMap.m_memory.raw[i]);
    }

    Disassembler dis;
    std::string out;
    std::stringstream m_fileBuffer;

    for(uint16_t i=0x000; i < 0XFFF; i++){
        out = util::printMessage2("%d: %X\n", i, memoryMap.m_memory.raw[i]);
        m_fileBuffer << out;
        dis.Disassemble(memoryMap.m_memory.raw[i]);

    }



    std::ofstream outputFile("Temp_Out.txt");
    if(outputFile.is_open()){
        outputFile << m_fileBuffer.str();
        outputFile.close();

    }







    dis.Print();

    return 0;
}
