#include "Emulator.h"

bool Emulator::Instruction_D(){
    bool result = true;

    m_display.DrawSprite(mem.V[I.X], mem.V[I.Y], I.byte);

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    m_debugArgs[2] = I.byte;
    PrintDebug(3, "DRW V%X, V%X, %X\n", m_debugArgs);

    return result;
}

