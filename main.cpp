#include <string>
#include "Emulator.h"
#include "MemoryMap.h"
#include "disassembler.h"
#include "utilities.h"

int main(int argc, char* argv[])
{
    Emulator emu8;
    emu8.LoadRom(argv[1]);
    emu8.Run();

    return 0;

}
