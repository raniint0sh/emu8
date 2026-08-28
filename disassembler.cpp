#include "disassembler.h"




Disassembler::Disassembler()
{}

Disassembler::~Disassembler()
{}



void Disassembler::Disassemble(uint16_t instruction)
{
    m_outString.clear();
    std::cout << instruction << std::endl;
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
        mem.incrementPC();
    }
    else if(instruction == 0x00EE){
        mem.PC = mem.stack[mem.SP];
        mem.SP--;
        m_fileBuffer << "RET\n";
    }
    else if((instruction & 0xF000) == 0x0){
        mem.PC = util::getNNN(instruction);
        m_outString = util::printMessage1("SYS %X\n",
            mem.PC);
        m_fileBuffer << m_outString.c_str();
    }
}
void Disassembler::Handle_1_instructions(uint16_t instruction){
    mem.PC = util::getNNN(instruction);  
    m_outString = util::printMessage1("JP  %X\n", 
        mem.PC);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_2_instructions(uint16_t instruction){
    mem.SP++;
        mem.incrementPC();
    mem.stack[mem.SP] = mem.PC;
    mem.PC = util::getNNN(instruction);
    m_outString = util::printMessage1("CALL %X\n",
        mem.PC);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_3_instructions(uint16_t instruction){
    X = util::getRegisterX(instruction);
    byte = util::getLastByte(instruction);

    if(mem.V[X] == byte){
        mem.incrementPC();
        mem.incrementPC();
    }
    else{
        mem.incrementPC();
    }

    m_outString = util::printMessage2("SE V%X, %X\n", 
        X,
        byte);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_4_instructions(uint16_t instruction){
        X = util::getRegisterX(instruction);
    byte = util::getLastByte(instruction);

    if(mem.V[X] != byte){
        mem.incrementPC();
        mem.incrementPC();
    }
    else{
        mem.incrementPC();
    }
    m_outString = util::printMessage2("SNE V%X, %X\n", 
        util::getRegisterX(instruction),
        util::getLastByte(instruction));
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_5_instructions(uint16_t instruction){
    X = util::getRegisterX(instruction);
    Y = util::getRegisterY(instruction);
    if(mem.V[X] == mem.V[Y]){
        mem.incrementPC();
        mem.incrementPC();
    }
    else{
        mem.incrementPC();
    }
    
    m_outString = util::printMessage2("SE V%X, V%X\n", 
        X,
        Y);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_6_instructions(uint16_t instruction){
    mem.incrementPC();
    X = util::getRegisterX(instruction);
    byte = util::getLastByte(instruction);
    mem.V[X] = byte;
    m_outString = util::printMessage2("LD V%X, %X\n", 
        X,
        byte);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_7_instructions(uint16_t instruction){
    mem.incrementPC();
    X = util::getRegisterX(instruction);
    byte = util::getLastByte(instruction);

    mem.V[X] = mem.V[X]+byte;

    m_outString = util::printMessage2("ADD V%X, %X\n", 
        X, 
        byte);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_8_instructions(uint16_t instruction){
    uint8_t key = util::getLastNibble(instruction);
    int temp = 0;
    switch(key){
        case 0x0:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            mem.V[X] = mem.V[Y];
            m_outString = util::printMessage2("LD V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x1:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            mem.V[X] = mem.V[X] | mem.V[Y];    
            m_outString = util::printMessage2("OR V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x2:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            mem.V[X] = mem.V[X] & mem.V[Y];
            m_outString = util::printMessage2("AND V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x3:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            mem.V[X] = mem.V[X] ^ mem.V[Y];
            m_outString = util::printMessage2("XOR V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x4:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            temp = mem.V[X] + mem.V[Y];
            if(temp > 255){
                mem.V[0xF] = 1;
            }
            else {
                mem.V[0xF] = 0;
            }
            mem.V[X] = mem.V[X] + mem.V[Y];
            
            m_outString = util::printMessage2("ADD V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x5:
            mem.incrementPC();  
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            if(mem.V[X] > mem.V[Y]){
                mem.V[0xF] = 1;
            }
            else {
                mem.V[0xF] = 0;
            }
            mem.V[X] = mem.V[X] - mem.V[Y];
                
            m_outString = util::printMessage2("SUB V%X, V%X\n", 
                X,
                Y);
            break;
        case 0x6:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            if((mem.V[X] & 0b0001) == 1){
                mem.V[0xF] = 1;
            }
            else {
                mem.V[0xF] = 0;
            }
            mem.V[X] = mem.V[X] / 2;
            
            m_outString = util::printMessage2("SHR V%X {, V%X}\n", 
                X,
                Y);
            break;
        case 0x7:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            if(mem.V[Y] > mem.V[X]){
                mem.V[0xF] = 1;
            }
            else {
                mem.V[0xF] = 0;
            }
            mem.V[X] = mem.V[Y] - mem.V[X];
            
            m_outString = util::printMessage2("SUBN V%X, V%X\n", 
                X,
                Y);
            break;
        case 0xE:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            Y = util::getRegisterY(instruction);
            if((mem.V[X] & 0b1000) == 1){
                mem.V[0xF] = 1;
            }
            else {
                mem.V[0xF] = 0;
            }
            mem.V[X] = mem.V[X] * 2;
                
            m_outString = util::printMessage2("SHL V%X {, V%X}\n", 
                X,
                Y);
            break;     
    }
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_9_instructions(uint16_t instruction){
    X = util::getRegisterX(instruction);
    Y = util::getRegisterY(instruction);
    if(mem.V[X] != mem.V[Y]){
        mem.incrementPC();
        mem.incrementPC();
    }
    else{
        mem.incrementPC();
    }

    m_outString = util::printMessage2("SNE V%X, V%X\n", 
        X, 
        Y);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_A_instructions(uint16_t instruction){
    mem.incrementPC();
    addr = util::getNNN(instruction);
    mem.I = addr;
    m_outString = util::printMessage1("LD I, %X\n", 
        addr);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_B_instructions(uint16_t instruction){
    addr = util::getNNN(instruction);
    mem.PC = mem.V[0] + addr;
    m_outString = util::printMessage1("JP V0, %X\n", 
        addr);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_C_instructions(uint16_t instruction){
    mem.incrementPC();
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 255); // define the range

    X = util::getRegisterX(instruction);
    byte = util::getLastByte(instruction);
    mem.V[X] = distr(gen) & byte;

    m_outString = util::printMessage2("RND V%X, %X\n", 
        X, 
        byte);
    m_fileBuffer << m_outString.c_str();
}

void Disassembler::Handle_D_instructions(uint16_t instruction){
    mem.incrementPC();
    X = util::getRegisterX(instruction);
    Y = util::getRegisterY(instruction);
    byte = util::getLastNibble(instruction);
    m_outString = util::printMessage3("DRW V%X, V%X, %X\n", 
        X, 
        Y,
        byte);
    m_fileBuffer << m_outString.c_str();

    DrawSprite(byte);
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
    util::BCDType tempBCD;
    switch(key){
        case 0x07:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            mem.V[X] = mem.DT;
            m_outString = util::printMessage1("LD V%X, DT\n", 
                X);
            break;
        case 0x0A:
//***************Need to Add LOGIC */
            mem.incrementPC();  
            m_outString = util::printMessage1("LD V%X, K\n", 
                util::getRegisterX(instruction));
            break;
        case 0x15:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            mem.DT = mem.V[X];
            m_outString = util::printMessage1("LD DT, V%X\n", 
                X);
            break;
        case 0x18:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            mem.ST = mem.V[X];
            m_outString = util::printMessage1("LD ST, V%X\n", 
                X);
            break;
        case 0x1E:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            mem.I = mem.I + mem.V[X];
            m_outString = util::printMessage1("ADD I, V%X\n", 
                X);
            break;
        case 0x29:
//***************Need to add logic */
            mem.incrementPC();
            m_outString = util::printMessage1("LD F, V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x33:
            mem.incrementPC();
            X = util::getRegisterX(instruction);
            tempBCD = util::BCD(mem.V[X]);
            mem.MEMORY.byteBlock[mem.I] = tempBCD.hundreds;
            mem.MEMORY.byteBlock[mem.I+1] = tempBCD.tens;
            mem.MEMORY.byteBlock[mem.I+2] = tempBCD.ones;
            m_outString = util::printMessage1("LD B, V%X\n", 
                X);
            break;
        case 0x55:
//***************Need to add logic */
            mem.incrementPC();
            m_outString = util::printMessage1("LD [I], V%X\n", 
                util::getRegisterX(instruction));
            break;
        case 0x65:
//***************Need to add logic */
            mem.incrementPC();
            m_outString = util::printMessage1("LD V%X, [I]\n", 
                util::getRegisterX(instruction));
            break;
    }
    m_fileBuffer << m_outString.c_str();    
}

void Disassembler::DrawSprite(uint8_t byte){
    uint16_t location = mem.I;
    uint8_t data;
    m_outString.clear();
    bool run1 = true;
    bool run2 = true;
    uint8_t count = 0;
    uint8_t mask = 0b10000000;

    while(run1){
        data = mem.MEMORY.byteBlock[location];
        while(run2){
            if(data & mask){
                m_outString = m_outString + "#";
            }
            else{
                m_outString = m_outString + " ";
            }
            mask = mask >> 1;
            if(mask < 1){
                run2 = false;
                m_outString = m_outString + "\n";
            }
        }
        run2 = true;
        mask = 0b10000000;
        location++;
        count++;
        if(count > 3){
            run1 = false;
        }
    }
    m_outString = m_outString + "\n";
    m_fileBuffer << m_outString.c_str();    

}