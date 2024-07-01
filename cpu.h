#include <iostream>
#include "cpuMemory.h"
class Cpu
{
public:
    Cpu(Memory& memory);
    void reset();
    void execute(int programStart);
    unsigned char fetch();

private:
    
    unsigned char read(uint16_t address);
    void write(uint16_t address, unsigned char value);
    void executeInstruction(unsigned opcode);
    uint16_t pc ;
    unsigned char sp ;
    unsigned char a ;
    unsigned char x ;
    unsigned char y ;
    unsigned char p ;
    Memory& memory;


    
    void setFlag(unsigned char flag , bool value);
    bool getFlag(unsigned char flag) const;
    void updateZeroAndNegativeFlags(unsigned char  value);
    

    // instructios
    void Dec(uint16_t adress);
    void Jmp(uint16_t adress);
    void Inc(uint16_t adress);
    void Sta(uint16_t adress);
    void Sty(uint16_t adress);
    void Stx(uint16_t adress);
    void Bit(uint16_t adress);
    void Cpy(uint16_t address);
    void Eor(uint16_t address);
    void Cmp(uint16_t address);
    void Cpx(uint16_t address);
    void Lsr(uint16_t address);
    void Asl(uint16_t address);
    void AndOp(uint16_t address);
    void Jsr(uint16_t address);
    void Rts();
    void Ora(uint16_t address);
    void Rol(uint16_t address);
    void And(uint16_t address);
    

    uint16_t zeroPageX();
    uint16_t absolute();
    uint16_t absoluteX();
    uint16_t absoluteY();
    uint16_t indirectX();
    uint16_t indirectY(); 
    uint16_t zeroPageY();


    void Lda(unsigned char value);
    void Ldx(unsigned char value);
    void Ldy(unsigned char value);
    void Adc(unsigned char value);
    void Bne(uint8_t offset);

    void Sbc(unsigned char value);  
    void Nop();
    void Tax();
    void RolAccumulator() ;
    void LsrAccumulator();
    void Txs();
    void Txa();
    void Tay();
    void Tya();
    void Tsx();
    void Inx();
    void AslAccumulator();
    void Dex();
    void Iny();
    void Dey();
    void Sec();
    void Clc();
    void Pha();
    void Pla();
    void Php();
    void Plp();
    void Brk();
    void Rti();
    


    unsigned char immediate();
    uint16_t zeroPage();

    void Ror(uint16_t address);
    void RorAccumulator();

};
constexpr uint8_t CARRY_FLAG = 0;
constexpr uint8_t ZERO_FLAG = 1;
constexpr uint8_t INTERRUPT_DISABLE_FLAG = 2;
constexpr uint8_t DECIMAL_MODE_FLAG = 3;
constexpr uint8_t BREAK_COMMAND_FLAG = 4;
constexpr uint8_t UNUSED_FLAG = 5; // Always set to 1
constexpr uint8_t OVERFLOW_FLAG = 6;
constexpr uint8_t NEGATIVE_FLAG = 7;