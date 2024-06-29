#include "cpuMemory.h"
#include <iostream>
#include "cpu.h"

int main() {
    Memory memory;
   
    // Initialize your memory with program instructions and data
    // Example: Write your program into memory
    memory.write(0x6000, 0xA2); // LDX immediate
    memory.write(0x6001, 0x00); // Operand (start with 0)
    memory.write(0x6002, 0x8E); // STX absolute
    memory.write(0x6003, 0x00); // Address ($00)
    memory.write(0x6004, 0x60); // RTS (end of loop initialization)

    memory.write(0x6005, 0xEE); // INC absolute
    memory.write(0x6006, 0x00); // Address ($00)
    memory.write(0x6007, 0xEC); // CPX absolute
    memory.write(0x6008, 0x00); // Operand (compare with $00)
    memory.write(0x6009, 0xD0); // BNE relative
    memory.write(0x600A, 0xF8); // Offset (-8, loop back to INC)


    Cpu cpu(memory);

    // Start CPU execution
    cpu.execute();
    std::cout << "dada\n";

    return 0;
}
