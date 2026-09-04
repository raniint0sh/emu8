#include "Emulator.h"

bool Emulator::Instruction_D(){
    bool result = true;

    //DrawSprite();  *************

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "DRW V%X, V%X, %X\n", m_debugArgs);

    return result;
}

