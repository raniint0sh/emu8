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

    dis.Print();

    return 0;
}
