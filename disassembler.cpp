#include "disassembler.h"
#include <cstdint>



Disassembler::Disassembler()
{}

Disassembler::~Disassembler()
{}



void Disassembler::Disassemble(uint16_t instruction)
{
    uint16_t key = (instruction >> BIT_SHIT_TO_4_NIBBLE);
    switch(key)
    {
        case 0x0:
            Handle_0_instructions(instruction);
            break;
        case 0x1:
             Handle_1_instructions(instruction);
             break;
        case 0x2:
             Handle_2_instructions(instruction);
             break;
        case 0x3:
             Handle_3_instructions(instruction);
             break;
        case 0x4:
             Handle_4_instructions(instruction);
             break;
    }



}

void Disassembler::Print(){
    //std::string tempOut = m_fileBuffer.str();
    //std::cout << tempOut;

    std::ofstream outputFile("Assembler_Out.txt");
    if(outputFile.is_open()){
        outputFile << m_fileBuffer.str();
        outputFile.close();
    }

}

void Disassembler::Handle_0_instructions(uint16_t instruction){
    uint16_t outputVar = 0;
    char temp[20];
    
    if(instruction == 0x00E0){
        m_fileBuffer << "CLS\n";
    }
    else if(instruction == 0x00EE){
        m_fileBuffer << "RET\n";
    }
    else if((instruction & 0xF000) == 0x0){
        outputVar = instruction & 0x0FFF;
        snprintf(temp, sizeof(temp), "SYS %X\n", outputVar);
        m_fileBuffer << temp;
    }
}
void Disassembler::Handle_1_instructions(uint16_t instruction){
    uint16_t outputVar = 0;
    char temp[20];
    outputVar = instruction & 0x0FFF;
    snprintf(temp, sizeof(temp), "JP  %X\n", outputVar);
    m_fileBuffer << temp;
}

void Disassembler::Handle_2_instructions(uint16_t instruction){
    uint16_t outputVar = 0;
    char temp[20];
    outputVar = instruction & 0x0FFF;
    snprintf(temp, sizeof(temp), "CALL %X\n", outputVar);
    m_fileBuffer << temp;
}

void Disassembler::Handle_3_instructions(uint16_t instruction){
    uint8_t registerV = 0;
    uint8_t byte = 0;
    char temp[20];
    registerV = (instruction & 0x0F00) >> BIT_SHIT_TO_3_NIBBLE;
    byte = (instruction & 0x00FF);
    snprintf(temp, sizeof(temp), "SE V%X, %X\n", registerV, byte);
    m_fileBuffer << temp;
}

void Disassembler::Handle_4_instructions(uint16_t instruction){
    uint8_t registerV = 0;
    uint8_t byte = 0;
    char temp[20];
    registerV = (instruction & 0x0F00) >> BIT_SHIT_TO_3_NIBBLE;
    byte = (instruction & 0x00FF);
    snprintf(temp, sizeof(temp), "SNE V%X, %X\n", registerV, byte);
    m_fileBuffer << temp;
}