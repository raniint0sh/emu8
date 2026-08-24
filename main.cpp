#import <iostream>
#import "disassembler.h"


int main()
{
    std::cout << "Hello World!" << std::endl;

    Disassembler dis;

    dis.Disassemble(0x00E0);
    dis.Disassemble(0x00EE);
    dis.Disassemble(0x0123);
    dis.Disassemble(0x1654);
    dis.Disassemble(0x2789);
    dis.Disassemble(0x3124);
    dis.Disassemble(0x4F87);
    dis.Disassemble(0x5EA5);
    dis.Disassemble(0x64B5);
    dis.Disassemble(0x7A03);
    
    dis.Disassemble(0x8131);
    dis.Disassemble(0x8132);
    dis.Disassemble(0x8133);
    dis.Disassemble(0x8134);
    dis.Disassemble(0x8135);

    dis.Disassemble(0x8246);

    dis.Print();

    return 0;
}
