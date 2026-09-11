#include "Emulator.h"

bool Emulator::Instruction_E(){
    bool result = true;
    
    if((I.byte & 0xFF) == 0x9E){
        result = Inst_E_Byte_9E();
    }
    else if((I.byte & 0xFF) == 0xA1){
        result = Inst_E_Byte_A1();
    }
    else{
        m_debugOut = util::printMessage1("***ERROR: %X", I.inst);
        std::cout << m_debugOut.c_str();
        result = false; 
    }
    
    return result;
}

bool Emulator::Inst_E_Byte_9E(){
    bool result = true;
    m_debugArgs[1] = 0;

    if(m_keypad.isKeyPressed(mem.V[I.X])){
        mem.incrementPC();
        m_debugArgs[1] = 1;
    }

    m_debugArgs[0] = mem.V[I.X];
    PrintDebug(2, "Key pressed %X:%d\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_E_Byte_A1(){
    bool result = true;
    m_debugArgs[1] = 0;
    if(m_keypad.isKeyUnpressed(mem.V[I.X])){
        mem.incrementPC();
        m_debugArgs[1] = 1;
    }    

    m_debugArgs[0] = mem.V[I.X];
    PrintDebug(2, "Key UNpressed %X:%d\n", m_debugArgs);

    return result;
}
