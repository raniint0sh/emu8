#include "Emulator.h"

bool Emulator::Instruction_E(){
    bool result = true;
    
    if(I.byte == 0x9E){
        result = Inst_E_Byte_9E();
    }
    else if(I.byte == 0xA1){
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
    
//****************************** */

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SKP V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Inst_E_Byte_A1(){
    bool result = true;
    
/******************************* */

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SKNP V%X\n", m_debugArgs);

    return result;
}
