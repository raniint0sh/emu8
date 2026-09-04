#include "Emulator.h"

bool Emulator::Instruction_F(){
    bool result = true;
    
  switch(I.byte)
    {
    case 0x07:
        result = Inst_F_Byte_07();
        break;
    case 0X0A:
        result = Inst_F_Byte_0A();
        break;
    case 0X15:
        result = Inst_F_Byte_15();
        break;    
    case 0x18:
        result = Inst_F_Byte_18();
        break;
    case 0x1E:
        result = Inst_F_Byte_1E();
        break;
    case 0x29:
        result = Inst_F_Byte_29();
        break;
    case 0X33:
        result = Inst_F_Byte_33();
        break;
    case 0x55:
        result = Inst_F_Byte_55();
        break;
    case 0x65:
        result = Inst_F_Byte_65();
        break;
    default:
        m_debugOut = util::printMessage1("***ERROR: %X", I.inst);
        std::cout << m_debugOut.c_str();
        result = false;
    }
    return result;
}

bool Emulator::Inst_F_Byte_07(){
    bool result = true;
    mem.V[I.X] = mem.DT;

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = mem.DT;
    PrintDebug(2, "LD V%X, DT\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_0A(){
    bool result = true;
    I.keypress = I.m_key.GetKeypress();
    mem.V[I.X] = I.keypress;

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.keypress;
    PrintDebug(2, "LD V%X, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_15(){
    bool result = true;
    mem.DT = mem.V[I.X];

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD DT, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_18(){
    bool result = true;
    mem.ST = mem.V[I.X];

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD ST, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_1E(){
    bool result = true;
    mem.I = mem.I + mem.V[I.X];

    m_debugArgs[0] = I.X;
    PrintDebug(1, "ADD I, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_29(){
    bool result = true;
    //******************************** */

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD F, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_33(){
    bool result = true;
    util::BCDType tempBCD;
    tempBCD = util::BCD(mem.V[I.X]);
    mem.MEMORY.byteBlock[mem.I] = tempBCD.hundreds;
    mem.MEMORY.byteBlock[mem.I+1] = tempBCD.tens;
    mem.MEMORY.byteBlock[mem.I+2] = tempBCD.ones;

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD B, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_55(){
    bool result = true;
    //******************************** */

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD [I], V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_F_Byte_65(){
    bool result = true;
    //******************************** */

    m_debugArgs[0] = I.X;
    PrintDebug(1, "LD V%X, [I]\n", m_debugArgs);

    return result;
}