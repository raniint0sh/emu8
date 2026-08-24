#import "disasembler.h"


void Disasemble(uint16_t instruction)
{
    uint16_t outputVar = 0;

    if(instruction == 0x00E0)
    {
        printf("Clear Screen\n");
    }
    else if(instruction == 0x00EE)
    {
        printf("Return\n");
    }
    else if((instruction & 0xF000) == 0x0)
    {
        outputVar = instruction & 0x0FFF;
        printf("SYS %x\n", outputVar);
    }




}