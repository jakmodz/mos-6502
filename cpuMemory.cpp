#include "cpuMemory.h"
#include <cstdint>
#include <stdio.h>

Memory::Memory()
{
    memory.fill(0);
}

unsigned char Memory::read(uint16_t address) const
{
    return memory.at(address);
}

void Memory::write(uint16_t address, unsigned value)
{
      memory[address] = value;
}

unsigned char* Memory::data()
{
    return memory.data();
}


size_t Memory::size() const
{
    return memory.size();
}