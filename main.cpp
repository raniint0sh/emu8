#import <iostream>
#import "disasembler.h"


int main()
{
    std::cout << "Hello World!" << std::endl;

    Disasemble(0x00E0);
    Disasemble(0x00EE);
    Disasemble(0x0123);



    return 0;
}
