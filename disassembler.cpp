#include "disassembler.h"
#include "utilities.h"
#include <cstdint>



Disassembler::Disassembler()
{}

Disassembler::~Disassembler()
{}



void Disassembler::Disassemble(uint16_t instruction)
{
    m_outString.clear();
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
        case 0x9:
             Handle_9_instructions(instruction);
             break;
        case 0xA:
             Handle_A_instructions(instruction);
             break;
        case 0xB:
             Handle_B_instructions(instruction);
             break;
        case 0xC:
             Handle_C_instructions(instruction);
             break;
        case 0xD:
             Handle_D_instructions(instruction);
             break;
        case 0xE:
             Handle_E_instructions(instruction);
             break;
        case 0xF:
             Handle_F_instructions(instruction);
             break;


        default:   
            m_outString = util::printMessage1("***Error: %X\n", 
                instruction);
            m_fileBuffer << m_outString.c_str();

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
    if(instruction == 0x00E0){
        m_fileBuffer << "CLS\n";
    }
    else if(instruction == 0x00EE){
        m_fileBuffer << "RET\n";
    }
    else if((instruction & 0xF000) == 0x0){
        m_outString = util::printMessage1("SYS %X\n",
            util::getNNN(instruction));
        m_fileBuffer << m_outString.c_str();
    }
}
void Disassembler::Handle_1_instructions(uint16_t instruction){
    m_outString = util::printMessage1("JP  %X\n", 
        util::getNNN(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_2_instructions(uint16_t instruction){
    m_outString = util::printMessage1("CALL %X\n",
        util::getNNN(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_3_instructions(uint16_t instruction){
    m_outString = util::printMessage2("SE V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_4_instructions(uint16_t instruction){
    m_outString = util::printMessage2("SNE V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_5_instructions(uint16_t instruction){
    m_outString = util::printMessage2("SE V%X, V%X\n", 
        util::getRegisterX(instruction),
        util::getRegisterY(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_6_instructions(uint16_t instruction){
    printf("HEX: %X\n", instruction);
    m_outString = util::printMessage2("LD V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_7_instructions(uint16_t instruction){
    m_outString = util::printMessage2("ADD V%X, %X\n", 
        util::getRegisterX(instruction), 
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_8_instructions(uint16_t instruction){
    uint8_t key = util::getLastNibble(instruction);

    switch(key){
        case 0x0:
            m_outString = util::printMessage2("LD V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x1:
            m_outString = util::printMessage2("OR V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x2:
            m_outString = util::printMessage2("AND V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x3:
            m_outString = util::printMessage2("XOR V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x4:
            m_outString = util::printMessage2("ADD V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x5:
            m_outString = util::printMessage2("SUB V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x6:
            m_outString = util::printMessage2("SHR V%X {, V%X}\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0x7:
            m_outString = util::printMessage2("SUBN V%X, V%X\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;
        case 0xE:
            m_outString = util::printMessage2("SHL V%X {, V%X}\n", 
                util::getRegisterX(instruction),
                util::getRegisterY(instruction));
            break;     
    }
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_9_instructions(uint16_t instruction){
    m_outString = util::printMessage2("SNE V%X, V%X\n", 
        util::getRegisterX(instruction), 
        util::getRegisterY(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_A_instructions(uint16_t instruction){
    m_outString = util::printMessage1("LD I, %X\n", 
        util::getNNN(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_B_instructions(uint16_t instruction){
    m_outString = util::printMessage1("JP V0, %X\n", 
        util::getNNN(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_C_instructions(uint16_t instruction){
    m_outString = util::printMessage2("RND V%X, %X\n", 
        util::getRegisterX(instruction), 
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_D_instructions(uint16_t instruction){
    m_outString = util::printMessage3("DRW V%X, V%X, %X\n", 
        util::getRegisterX(instruction), 
        util::getRegisterY(instruction),
    util::getLastNibble(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_E_instructions(uint16_t instruction){
    if(util::getLastByte(instruction) == 0x9E){
        m_outString = util::printMessage1("SKP V%X\n", 
            util::getRegisterX(instruction));    
    }else if(util::getLastByte(instruction) == 0xA1){
        m_outString = util::printMessage1("SKNP V%X\n", 
            util::getRegisterX(instruction));
    }
    else{
         m_outString = util::printMessage1("***ERROR: %X\n", 
        instruction);
    }
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_F_instructions(uint16_t instruction){
    uint16_t key = util::getLastByte(instruction);
    switch(key){
        case 0x07:
            m_outString = util::printMessage1("LD V%X, DT\n", 
                util::getRegisterX(instruction));
            break;
        case 0x0A:
            m_outString = util::printMessage1("LD V%X, K\n", 
                util::getRegisterX(instruction));
            break;
        case 0x15:
            m_outString = util::printMessage1("LD DT, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x18:
            m_outString = util::printMessage1("LD ST, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x1E:
            m_outString = util::printMessage1("ADD I, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x29:
            m_outString = util::printMessage1("LD F, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x33:
            m_outString = util::printMessage1("LD B, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x55:
            m_outString = util::printMessage1("LD [I], V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x65:
            m_outString = util::printMessage1("LD V%X, [I]\n", 
                util::getRegisterX(instruction));
            break;
    }
    m_fileBuffer << m_outString.c_str();    
}