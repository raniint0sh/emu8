#include "disassembler.h"
#include "utilities.h"
#include <cstdint>



Disassembler::Disassembler()
{}

Disassembler::~Disassembler()
{}



void Disassembler::Disassemble(uint16_t instruction)
{
    uint16_t key = (instruction >> util::BIT_SHIT_TO_4_NIBBLE);
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
        case 0x5:
             Handle_5_instructions(instruction);
             break;
        case 0x6:
             Handle_6_instructions(instruction);
             break;
        case 0x7:
             Handle_7_instructions(instruction);
             break;
        case 0x8:
             Handle_8_instructions(instruction);
             break;





        default:
            std::string outString;
            outString = util::printMessage1("Could not disassemble instruction: ", 
                instruction);
            m_fileBuffer << outString.c_str();

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
    std::string outString;
    
    if(instruction == 0x00E0){
        m_fileBuffer << "CLS\n";
    }
    else if(instruction == 0x00EE){
        m_fileBuffer << "RET\n";
    }
    else if((instruction & 0xF000) == 0x0){
        outString = util::printMessage1("SYS %X\n",
            util::getNNN(instruction));
        m_fileBuffer << outString.c_str();
    }
}
void Disassembler::Handle_1_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage1("JP  %X\n", 
        util::getNNN(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_2_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage1("CALL %X\n",
        util::getNNN(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_3_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage2("SE V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_4_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage2("SNE V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_5_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage2("SE V%X, V%X\n", 
        util::getRegisterX(instruction),
        util::getRegisterY(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_6_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage2("LD V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_7_instructions(uint16_t instruction){
    std::string outString;
    outString = util::printMessage2("ADD V%X, %X\n", 
        util::getRegisterX(instruction), 
        util::getLastByte(instruction));
    m_fileBuffer << outString.c_str();
}

void Disassembler::Handle_8_instructions(uint16_t instruction){
    std::string outString;
    uint8_t key = util::getLastNibble(instruction);

    switch(key){
        case 0x0:
            outString = util::printMessage2("LD V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x1:
            outString = util::printMessage2("OR V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x2:
            outString = util::printMessage2("AND V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x3:
            outString = util::printMessage2("XOR V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x4:
            outString = util::printMessage2("ADD V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x5:
            outString = util::printMessage2("SUB V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x6:
            outString = util::printMessage2("SHR V%X {, V%X}\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x7:
            outString = util::printMessage2("SUBN V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0xE:
            outString = util::printMessage2("SHL V%X {, V%X}\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;     
    }
    m_fileBuffer << outString.c_str();
}