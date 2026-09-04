#include <cstdint>

#include <string>
#include <fstream>
#include "Emulator.h"
#include "MemoryMap.h"
#include "disassembler.h"
#include "utilities.h"



int main(int argc, char* argv[])
{
    Emulator emu8;
    emu8.LoadRom(argv[1]);

    return 0;



    MemoryMap& mem = MemoryMap::getInstance();
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
