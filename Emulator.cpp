#include "Emulator.h"

Emulator::Emulator(){

}

Emulator::~Emulator(){

}

bool Emulator::LoadRom(std::string romPath)
{
    std::ifstream inFile(romPath, std::ios::binary | std::ios::ate);
    if(!inFile.is_open()){
        std::cerr << "Failed top pen file!!!" << std::endl;
        return false;
    }
    
    // Since we opened at the end, tellg() gives us the total file size
    int size = inFile.tellg();
    
    // Seek back to the beginning of the file to prepare for reading
    inFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
  
    if(inFile.read(buffer.data(), size)){
        std::cout << "Successfully read " << size << " bytes." << std::endl;
    }

    int j = 0x200;
    for(int i=0; i < size; i++){
        mem.MEMORY.byteBlock[j] = static_cast<uint8_t>(buffer[i]);
        j++;
    }

    return true;

}

void Emulator::PrintDebugFile(){

   std::ofstream outputFile("Emu9Debug.txt");
    if(outputFile.is_open()){
        outputFile << m_fileBuffer.str();
        outputFile.close();
    }
}

void Emulator::PrintDebug(uint8_t numberOfArgs, std::string statement, uint16_t arguments[3]){
    if(!DEBUG){
        return;
    }
    
    switch(numberOfArgs){
    case 0:
        m_fileBuffer << statement.c_str();
        break;
    case 1:
        m_debugOut = util::printMessage1(statement, 
            arguments[0]);
        m_fileBuffer << m_debugOut.c_str();
        break;
    case 2:
        m_debugOut = util::printMessage2(statement, 
            arguments[0], 
            arguments[1]);
        m_fileBuffer << m_debugOut.c_str();
        break;
    case 3:
        m_debugOut = util::printMessage3(statement, 
            arguments[0],
            arguments[1], 
            arguments[2]);
        m_fileBuffer << m_debugOut.c_str();
        break;

    }

}



bool Emulator::Run(){
    mem.PC = 0x200;
    uint16_t opcode;
    bool result = true;

    for(uint16_t i=0x000; i < 0XFFF; i++){
        opcode = mem.ReadInstruction(mem.PC);

        I.Disassemble(opcode);
            
        
        
        if(DEBUG){
            m_debugOut = util::printMessage2("%d: %X\n", (mem.PC-512), opcode);
            m_fileBuffer << m_debugOut;
        }
        
        

    }
    return true;
}

bool Emulator::HandleInstruction(){
    bool result = true;

    switch(I.command){
    case 0x0:
        result = Instruction_0();
        break;
    case 0x1:
        result = Instruction_1();
        break;
    case 0x2:
        result = Instruction_2();
        break;
    case 0x3:
        result = Instruction_3();
        break;
    case 0x4:
        result = Instruction_4();
        break;
    case 0x5:
        result = Instruction_5();
        break;
    case 0x6:
        result = Instruction_6();
        break;
    case 0x7:
        result = Instruction_7();
        break;
    case 0x8:
        result = Instruction_8();
        break;
    case 0x9:
        result = Instruction_9();
        break;
    case 0xA:
        result = Instruction_A();
        break;
    case 0xB:
        result = Instruction_B();
        break;
    case 0xC:
        result = Instruction_C();
        break;
    case 0xD:
        result = Instruction_D();
        break;
    case 0xE:
        result = Instruction_E();
        break;        
    case 0xF:
        result = Instruction_F();
        break;
    default:
        m_debugOut = util::printMessage1("***ERROR: %X", I.inst);
        std::cout << m_debugOut.c_str();
        result = false;
    }

    return true;
}

bool Emulator::Instruction_0(){
    bool result = true;
    if(I.byte == 0xE0){
        //Clear Screen**************
        PrintDebug(0, "CLS\n", m_debugArgs);
    }
    else if(I.byte == 0xEE){
        mem.PC = mem.stack[mem.SP];
        mem.SP--;
        PrintDebug(0, "RET\n",m_debugArgs);
    }
    else{
        m_debugOut = util::printMessage1("***ERROR: %X", I.inst);
        std::cout << m_debugOut.c_str();
        result = false;
    }       
    return result;
}

bool Emulator::Instruction_1(){
    bool result = true;
    mem.PC = I.addr;

    m_debugArgs[0] = I.addr;
    PrintDebug(2, "JP %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_2(){
    bool result = true;
    mem.SP++;
    mem.stack[mem.SP] = mem.PC;
    mem.PC = I.addr;
    
    m_debugArgs[0] = I.addr;
    PrintDebug(2, "CALL %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_3(){
    bool result = true;
    if(mem.V[I.X] == I.byte){
        mem.incrementPC();
    } 

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "SE V%X, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_4(){
    bool result = true;
    if((mem.V[I.X] & 0xFF) != I.byte){
        mem.incrementPC();
        mem.incrementPC();
    }
    else{
        mem.incrementPC();
    }

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "SNE V%X, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_5(){
    bool result = true;
    if(mem.V[I.X] == mem.V[I.Y]){
        mem.incrementPC();
    } 

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SE V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_6(){
    bool result = true;
    mem.V[I.X] = I.byte;

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "LD V%X, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_7(){
    bool result = true;
    mem.V[I.X] = mem.V[I.X] + I.byte;

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "ADD V%X, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_9(){
    bool result = true;
    if(mem.V[I.X] != mem.V[I.Y]){
        mem.incrementPC();
    } 

    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.Y;
    PrintDebug(2, "SNE V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_A(){
    bool result = true;
    mem.I = I.addr;

    m_debugArgs[0] = I.addr;
    PrintDebug(1, "SNE V%X, V%X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_B(){
    bool result = true;
    mem.PC = mem.V[0] + I.addr;

    m_debugArgs[0] = I.addr;
    PrintDebug(1, "JP V0, %X\n", m_debugArgs);

    return result;
}

bool Emulator::Instruction_C(){
    bool result = true;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 255); // define the range

    mem.V[I.X] = distr(gen) & I.byte;
    
    m_debugArgs[0] = I.X;
    m_debugArgs[1] = I.byte;
    PrintDebug(2, "RND V%X, %X\n", m_debugArgs);

    return result;
}

