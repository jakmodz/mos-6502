#pragma once 
#include <array>
#include <cstdint>
#include <cstddef>

class Memory
{

public:
    Memory();
    unsigned char read(uint16_t address) const;
    void write(uint16_t address,unsigned value);
    unsigned char* data();
    size_t size() const;
    
private:
    std::array<unsigned char,65536> memory;
};
