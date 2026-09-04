#include "Emulator.h"

bool Emulator::Instruction_8(){
    bool result = true;
    
    switch(I.byte)
    {
    case 0x0:
        result = Inst_8_Nibble_0();
        break;
    case 0x1:
        result = Inst_8_Nibble_1();
        break;
    case 0x2:
        result = Inst_8_Nibble_2();
        break;    
    case 0x3:
        result = Inst_8_Nibble_3();
        break;
    case 0x4:
        result = Inst_8_Nibble_4();
        break;
    case 0x5:
        result = Inst_8_Nibble_5();
        break;
    case 0x6:
        result = Inst_8_Nibble_6();
        break;
    case 0x7:
        result = Inst_8_Nibble_7();
        break;
    case 0xE:
        result = Inst_8_Nibble_E();
        break;
    default:
        m_debugOut = util::printMessage1("***ERROR: %X", I.inst);
        std::cout << m_debugOut.c_str();
        result = false;
    }
    return result;
}

bool Emulator::Inst_8_Nibble_0(){
    bool result = true;
    mem.V[I.X] = mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "LD V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_1(){
    bool result = true;
    mem.V[I.X] = mem.V[I.X] | mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "OR V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_2(){
    bool result = true;
    mem.V[I.X] = mem.V[I.X] & mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "AND V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_3(){
    bool result = true;
    mem.V[I.X] = mem.V[I.X] ^ mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "XOR V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_4(){
    bool result = true;
    mem.V[I.X] = mem.V[I.X] + mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "ADD V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_5(){
    bool result = true;
    if(mem.V[I.X] > mem.V[I.Y]){
        mem.V[0xF] = 1;
    }
    else {
        mem.V[0xF] = 0;
    }
    mem.V[I.X] = mem.V[I.X] - mem.V[I.Y];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SUB V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_6(){
    bool result = true;
    if((mem.V[I.X] & 0b0001) == 1){
        mem.V[0xF] = 1;
    }
    else {
        mem.V[0xF] = 0;
    }
    mem.V[I.X] = mem.V[I.X] / 2;

    m_debugArgs[0] = I.X;
    PrintDebug(1, "SHR V%X {, V%X}\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_7(){
    bool result = true;
    if(mem.V[I.Y] > mem.V[I.X]){
        mem.V[0xF] = 1;
    }
    else {
        mem.V[0xF] = 0;
    }
    mem.V[I.X] = mem.V[I.Y] - mem.V[I.X];

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SUBN V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_8_Nibble_E(){
    bool result = true;
    if((mem.V[I.X] & 0b1000) == 1){
        mem.V[0xF] = 1;
    }
    else {
        mem.V[0xF] = 0;
    }
    mem.V[I.X] = mem.V[I.X] * 2;

    m_debugArgs[0] = I.X;
    PrintDebug(1, "SHR V%X {, V%X}\n", m_debugArgs);

    return result;
}