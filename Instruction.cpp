#include "Instruction.h"
#include <cstdint>


Instruction::Instruction(){

}

Instruction::~Instruction(){

}

bool Instruction::Disassemble(uint16_t opcode){
    clear();
    inst = opcode;
    command = (opcode >> util::BIT_SHIT_TO_4_NIBBLE);
    switch(command)
    {
        case 0x0:
            byte = util::getLastByte(opcode);
            break;
        case 0x1:
            addr = util::getNNN(opcode);
            break;
        case 0x2:
             addr = util::getNNN(opcode);
             break;
        case 0x3:
             X = util::getRegisterX(opcode);
             byte = util::getLastByte(opcode);
             break;
        case 0x4:
             X = util::getRegisterX(opcode);
             byte = util::getLastByte(opcode);
             break;
        case 0x5:
             X = util::getRegisterX(opcode);
             Y = util::getRegisterY(opcode);
             break;
        case 0x6:
             X = util::getRegisterX(opcode);
             byte = util::getLastByte(opcode);
             break;
        case 0x7:
             X = util::getRegisterX(opcode);
             byte = util::getLastByte(opcode);
             break;
        case 0x8:
             X = util::getRegisterX(opcode);
             Y = util::getRegisterY(opcode);
             byte = util::getLastNibble(opcode);
             break;
        case 0x9:
             X = util::getRegisterX(opcode);
             Y = util::getRegisterY(opcode);
             break;
        case 0xA:
             addr = util::getNNN(opcode);
             break;
        case 0xB:
             addr = util::getNNN(opcode);
             break;
        case 0xC:
             X = util::getRegisterX(opcode);
             byte = util::getLastByte(opcode);
             break;
        case 0xD:
             X = util::getRegisterX(opcode);
             Y = util::getRegisterY(opcode);
             byte = util::getLastNibble(opcode);
             break;
        case 0xE:
             byte = util::getLastByte(opcode);
             break;
        case 0xF:
             X = util::getRegisterX(opcode); 
             byte = util::getLastByte(opcode);
             break;
        default:   
            return false;
    }
    return true;
}

void Instruction::clear(){
        command = 0;
        X = 0;
        Y = 0;
        byte = 0;
        addr = 0;
        keypress = 0;
        m_key.clear();
}