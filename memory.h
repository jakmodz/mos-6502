#pragma once 
#include <array>


class Memory
{

public:
    Memory();
    uint8_t read(uint16_t address) const;
    void write(uint16_t address,uint8_t value);
    uint8_t* data();
    size_t size() const;
    
private:
    std::array<uint8_t,65536> memory;
};
