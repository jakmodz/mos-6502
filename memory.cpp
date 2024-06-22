#include "memory.h"

Memory::Memory()
{
    memory.fill(0);
}

uint8_t Memory::read(uint16_t address) const
{
    return memory[address];
}

void Memory::write(uint16_t address, uint8_t value)
{
    memory[address] = value;
}

uint8_t *Memory::data()
{
    return memory.data();
}

size_t Memory::size() const
{
    return memory.size();
}