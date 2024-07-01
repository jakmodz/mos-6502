#include "cpuMemory.h"
#include <iostream>
#include "cpu.h"

int main() {
    Memory memory;
   
    
 memory.write(0x6000, 0xA2); // LDX #$00 - Load X with 0
    memory.write(0x6001, 0x00); // Operand 0

    memory.write(0x6002, 0xA0); // LDY #$0A - Load Y with 10
    memory.write(0x6003, 0x0A); // Operand 10

    memory.write(0x6004, 0xA9); // LDA #$00 - Load A with 0
    memory.write(0x6005, 0x00); // Operand 0

    memory.write(0x6006, 0xE8); // INX - Increment X

    memory.write(0x6007, 0x18); // CLC - Clear carry

    memory.write(0x6008, 0x65); // ADC $00 - Add memory to accumulator (0x00)
    memory.write(0x6009, 0x00); // Address $00

    memory.write(0x600A, 0x88); // DEY - Decrement Y

    memory.write(0x600B, 0xD0); // BNE - Branch if not equal
    memory.write(0x600C, 0xF8); // Offset -8 (loop back to increment X and add)

    memory.write(0x600D, 0x8D); // STA $01 - Store accumulator in memory
    memory.write(0x600E, 0x01); // Address $01
    memory.write(0x600F, 0x00); // High byte of address $0001

    memory.write(0x6010, 0x60); // RTS - Return from subroutine

    Cpu cpu(memory);

    
    cpu.execute(0x6000);
    std::cout << "dada\n";

    return 0;
}
