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
        mem.MEMORY.byteBlock[j] = static_cast<uint8_t>(buffer[i]);
        j++;
    }
     
    printf("addr: %X",mem.ReadInstruction(0x200));

  
    Disassembler dis;
    std::string out;
    std::stringstream m_fileBuffer;
    uint16_t instruction = 0;
    mem.PC = 0x200;
   for(uint16_t i=0x000; i < 0XFFF; i++){
         instruction = mem.ReadInstruction(mem.PC);
        out = util::printMessage2("%d: %X\n", (mem.PC-512), instruction);
        m_fileBuffer << out;

        dis.Disassemble(instruction);

    }



    std::ofstream outputFile("Temp_Out.txt");
    if(outputFile.is_open()){
        outputFile << m_fileBuffer.str();
        outputFile.close();

    }







    dis.Print();

    return 0;
}
