#include "cpu.h"
#include "cpuMemory.h"
Cpu::Cpu(Memory& memory) : memory(memory) , p(0X20)
{
    x = 0;
    y = 0; 
    a = 0;
   sp = 0; 
   pc = 0;
}
unsigned char Cpu::fetch()
{
    return memory.read(pc++);
}

unsigned char Cpu::read(uint16_t address)
{
    return memory.read(address);
}

void Cpu::write(uint16_t address, unsigned char value)
{
    memory.write(address,value);
}

void Cpu::executeInstruction(unsigned opcode)
{
   switch (opcode) {
    case 0x69: Adc(immediate()); break;
    case 0x65: Adc(zeroPage()); break;
    case 0x75: Adc(zeroPageX()); break;
    case 0x6D: Adc(absolute()); break;
    case 0x7D: Adc(absoluteX()); break;
    case 0x79: Adc(absoluteY()); break;
    case 0x61: Adc(indirectX()); break;
    case 0x71: Adc(indirectY()); break;
    case 0x29: And(immediate()); break;
    case 0x25: And(zeroPage()); break;
    case 0x35: And(zeroPageX()); break;
    case 0x2D: And(absolute()); break;
    case 0x3D: And(absoluteX()); break;
    case 0x39: And(absoluteY()); break;
    case 0x21: And(indirectX()); break;
    case 0x31: And(indirectY()); break;
    case 0x0A: AslAccumulator(); break;
    case 0x06: Asl(zeroPage()); break;
    case 0x16: Asl(zeroPageX()); break;
    case 0x0E: Asl(absolute()); break;
    case 0x1E: Asl(absoluteX()); break;
    case 0x24: Bit(zeroPage()); break;
    case 0x2C: Bit(absolute()); break;
    case 0xC9: Cmp(immediate()); break;
    case 0xC5: Cmp(zeroPage()); break;
    case 0xD5: Cmp(zeroPageX()); break;
    case 0xCD: Cmp(absolute()); break;
    case 0xDD: Cmp(absoluteX()); break;
    case 0xD9: Cmp(absoluteY()); break;
    case 0xC1: Cmp(indirectX()); break;
    case 0xD1: Cmp(indirectY()); break;
    case 0xE0: Cpx(immediate()); break;
    case 0xE4: Cpx(zeroPage()); break;
    case 0xEC: Cpx(absolute()); break;
    case 0xC0: Cpy(immediate()); break;
    case 0xC4: Cpy(zeroPage()); break;
    case 0xCC: Cpy(absolute()); break;
    case 0xC6: Dec(zeroPage()); break;
    case 0xD6: Dec(zeroPageX()); break;
    case 0xCE: Dec(absolute()); break;
    case 0xDE: Dec(absoluteX()); break;
    case 0x49: Eor(immediate()); break;
    case 0x45: Eor(zeroPage()); break;
    case 0x55: Eor(zeroPageX()); break;
    case 0x4D: Eor(absolute()); break;
    case 0x5D: Eor(absoluteX()); break;
    case 0x59: Eor(absoluteY()); break;
    case 0x41: Eor(indirectX()); break;
    case 0x51: Eor(indirectY()); break;
    case 0xE6: Inc(zeroPage()); break;
    case 0xF6: Inc(zeroPageX()); break;
    case 0xEE: Inc(absolute()); break;
    case 0xFE: Inc(absoluteX()); break;
    case 0xA9: Lda(immediate()); break;
    case 0xA5: Lda(zeroPage()); break;
    case 0xB5: Lda(zeroPageX()); break;
    case 0xAD: Lda(absolute()); break;
    case 0xBD: Lda(absoluteX()); break;
    case 0xB9: Lda(absoluteY()); break;
    case 0xA1: Lda(indirectX()); break;
    case 0xB1: Lda(indirectY()); break;
    case 0xA2: Ldx(immediate()); break;
    case 0xA6: Ldx(zeroPage()); break;
    case 0xB6: Ldx(zeroPageY()); break;
    case 0xAE: Ldx(absolute()); break;
    case 0xBE: Ldx(absoluteY()); break;
    case 0xA0: Ldy(immediate()); break;
    case 0xA4: Ldy(zeroPage()); break;
    case 0xB4: Ldy(zeroPageX()); break;
    case 0xAC: Ldy(absolute()); break;
    case 0xBC: Ldy(absoluteX()); break;
    case 0x4A: LsrAccumulator(); break;
    case 0x46: Lsr(zeroPage()); break;
    case 0x56: Lsr(zeroPageX()); break;
    case 0x4E: Lsr(absolute()); break;
    case 0x5E: Lsr(absoluteX()); break;
    case 0x09: Ora(immediate()); break;
    case 0x05: Ora(zeroPage()); break;
    case 0x15: Ora(zeroPageX()); break;
    case 0x0D: Ora(absolute()); break;
    case 0x1D: Ora(absoluteX()); break;
    case 0x19: Ora(absoluteY()); break;
    case 0x01: Ora(indirectX()); break;
    case 0x11: Ora(indirectY()); break;
    case 0xAA: Tax(); break;
    case 0xA8: Tay(); break;
    case 0xBA: Tsx(); break;
    case 0x8A: Txa(); break;
    case 0x9A: Txs(); break;
    case 0x98: Tya(); break;
    case 0x2A: RolAccumulator(); break;
    case 0x26: Rol(zeroPage()); break;
    case 0x36: Rol(zeroPageX()); break;
    case 0x2E: Rol(absolute()); break;
    case 0x66: Ror(zeroPage()); break;
    case 0x76: Ror(zeroPageX()); break;
    case 0x6E: Ror(absolute()); break;
    case 0x7E: Ror(absoluteX()); break;
    case 0xE9: Sbc(immediate()); break;
    case 0xE5: Sbc(zeroPage()); break;
    case 0xF5: Sbc(zeroPageX()); break;
    case 0xED: Sbc(absolute()); break;
    case 0xFD: Sbc(absoluteX()); break;
    case 0xF9: Sbc(absoluteY()); break;
    case 0xE1: Sbc(indirectX()); break;
    case 0xF1: Sbc(indirectY()); break;
    case 0x85: Sta(zeroPage()); break;
    case 0x95: Sta(zeroPageX()); break;
    case 0x8D: Sta(absolute()); break;
    case 0x9D: Sta(absoluteX()); break;
    case 0x99: Sta(absoluteY()); break;
    case 0x81: Sta(indirectX()); break;
    case 0x91: Sta(indirectY()); break;
    case 0x86: Stx(zeroPage()); break;
    case 0x96: Stx(zeroPageY()); break;
    case 0x8E: Stx(absolute()); break;
    case 0x84: Sty(zeroPage()); break;
    case 0x94: Sty(zeroPageX()); break;
    case 0x8C: Sty(absolute()); break;
    case 0x00: Brk(); break;
    case 0x40: Rti(); break;
    case 0x60: Rts(); break;
    case 0x48: Pha(); break;
    case 0x68: Pla(); break;
    case 0x08: Php(); break;
    case 0x28: Plp(); break;
    case 0xEA: Nop(); break;
    case 0xD0: Bne(immediate()); break;
    
    default: std::cerr << "Nieznana instrukcja: " << std::hex << int(opcode) << std::endl; break;
}

}

void Cpu::setFlag(unsigned char flag , bool value)
{
        if (value) {
        p |= (1 << flag);
    } else {
        p &= ~(1 << flag);
    }
}

bool Cpu::getFlag(unsigned char flag) const
{
    return p & (1 << flag);
}

void Cpu::updateZeroAndNegativeFlags(unsigned char value)
{
    setFlag(ZERO_FLAG, value == 0);
    setFlag(NEGATIVE_FLAG, value & 0x80);
}

void Cpu::reset()
{
    pc = memory.read(0xFFFC) | (memory.read(0xFFFD) << 8);
    sp = 0xFF;
    p = 0x20;
}

void Cpu::Dec(uint16_t adress)
{
    

    auto value = memory.read(adress);
    --value;
    memory.write(adress,value);

}

void Cpu::Inc(uint16_t adress)
{
    auto value = memory.read(adress);
    ++value;
    memory.write(adress,value);
}

void Cpu::Sta(uint16_t adress)
{
    write(adress,a);
}

void Cpu::Sty(uint16_t adress)
{
     write(adress,y);
}

void Cpu::Stx(uint16_t adress)
{
    write(adress,x);
}

void Cpu::Bit(uint16_t adress)
{
    unsigned char  value = read(adress);
    setFlag(ZERO_FLAG, (a & value) == 0);
    setFlag(OVERFLOW_FLAG, value & 0x40);
    setFlag(NEGATIVE_FLAG, value & 0x80);
}

void Cpu::Lda(unsigned char value)
{
    a = value;
    updateZeroAndNegativeFlags(a);

}

void Cpu::Ldx(unsigned char value)
{
    x = value;;
    updateZeroAndNegativeFlags(x);
}

void Cpu::Ldy(unsigned char value)
{
        y = value;
        updateZeroAndNegativeFlags(y);
}

void Cpu::Adc(unsigned char value)
{
    uint16_t sum = a + value + (p & 0x01);
    if (sum > 0xFF) {
        p |= 0x01;
    } else {
        p &= ~0x01;
    }
    a = sum & 0xFF;
    updateZeroAndNegativeFlags(x);
}

void Cpu::Bne(uint8_t offset)
{
    if (!getFlag(ZERO_FLAG)) {
        int8_t signedOffset = static_cast<int8_t>(offset); 
        pc += signedOffset; 
    }
}

void Cpu::Sbc(unsigned char value)
{
    Adc(~value);
}

void Cpu::Nop()
{

}

void Cpu::Jmp(uint16_t adress)
{
    pc = memory.read(adress);
}

void Cpu::Tax()
{
    x = a;
    updateZeroAndNegativeFlags(x);
}

void Cpu::RolAccumulator()
{
    bool carry = getFlag(CARRY_FLAG); 
    setFlag(CARRY_FLAG, a & 0x80); 
    a = (a << 1) | carry; 
    updateZeroAndNegativeFlags(a);
}

void Cpu::LsrAccumulator()
{
        setFlag(CARRY_FLAG, a & 0x01); 
    a >>= 1;
    updateZeroAndNegativeFlags(a); 
}

void Cpu::Txs()
{
     sp = x;
}

void Cpu::Txa()
{
    a=x;
    updateZeroAndNegativeFlags(a);
}

void Cpu::Tay()
{
    y = a;
    updateZeroAndNegativeFlags(y);
}

void Cpu::Tya()
{
    y= a;
    updateZeroAndNegativeFlags(y);
}

void Cpu::Tsx()
{
    x = sp;
    updateZeroAndNegativeFlags(x);
}

void Cpu::Inx()
{
    ++x;
    updateZeroAndNegativeFlags(x);
}

void Cpu::AslAccumulator()
{
    setFlag(CARRY_FLAG, a & 0x80); 
    a <<= 1; 
    updateZeroAndNegativeFlags(a); 
}

void Cpu::Dex()
{
    --x;
    updateZeroAndNegativeFlags(x);
}

void Cpu::Iny()
{
     ++y;
    updateZeroAndNegativeFlags(y);
}

void Cpu::Dey()
{
     --y;
    updateZeroAndNegativeFlags(y);
}

void Cpu::Sec()
{
    p |= 0x01;
}

void Cpu::Clc()
{
      p &= ~0x01; 
}

void Cpu::Pha()
{
    write(0x0100 + sp--, a);
}

void Cpu::Pla()
{
    a = read(0x100 + ++sp);
    updateZeroAndNegativeFlags(a);
}

void Cpu::Php()
{
    write(0x0100 + sp--,p | 0x30);
}

void Cpu::Plp()
{
    p = read(0x0100 + ++sp);
    p |= 0x20;
}

void Cpu::Brk()
{
    pc++;
    write(0x0100 + sp--, (pc >> 8) & 0xFF);
    write(0x0100 + sp--, pc & 0xFF);
    setFlag(BREAK_COMMAND_FLAG, true);
    write(0x0100 + sp--, p | 0x30);
    setFlag(INTERRUPT_DISABLE_FLAG, true);
    pc = read(0xFFFE) | (read(0xFFFF) << 8);
}

void Cpu::Rti()
{
    p = read(0x0100 + ++sp);
    p |= 0x20; 
    pc = read(0x0100 + ++sp);
    pc |= (read(0x0100 + ++sp) << 8);
}

unsigned char Cpu::immediate()
{
    return fetch();
}

uint16_t Cpu::zeroPage()
{
    return  fetch();
}

void Cpu::Ror(uint16_t address)
{
    
}

void Cpu::RorAccumulator()
{
    bool oldCarry = getFlag(CARRY_FLAG);
    setFlag(CARRY_FLAG, a & 0x01);
    a >>= 1;
    if (oldCarry) {
        a |= 0x80;
    }
    updateZeroAndNegativeFlags(a);
}

void Cpu::Cpy(uint16_t address)
{
    uint8_t value = read(address);
    setFlag(CARRY_FLAG, y >= value);
    updateZeroAndNegativeFlags(y - value);
}

void Cpu::Eor(uint16_t address)
{
     a ^= read(address);
    updateZeroAndNegativeFlags(a);
}

void Cpu::Cmp(uint16_t address)
{
     uint8_t value = read(address);
    setFlag(CARRY_FLAG, a >= value);
    updateZeroAndNegativeFlags(a - value);
}

void Cpu::Cpx(uint16_t address)
{
    uint8_t value = read(address);
    setFlag(CARRY_FLAG, x >= value);
    updateZeroAndNegativeFlags(x - value);
}

void Cpu::Lsr(uint16_t address)
{
    uint8_t value = read(address);
    setFlag(CARRY_FLAG, value & 0x01);
    value >>= 1;
    write(address, value);
    updateZeroAndNegativeFlags(value);
}

void Cpu::And(uint16_t address)
{
     a &= read(address); 
    updateZeroAndNegativeFlags(a);
}

uint16_t Cpu::zeroPageX()
{
    return (fetch() + x) & 0xFF;
}

uint16_t Cpu::absolute()
{
     uint16_t lo = fetch();
    uint16_t hi = fetch();
    return (hi << 8) | lo;
}

uint16_t Cpu::absoluteX()
{
     uint16_t lo = fetch();
    uint16_t hi = fetch();
    return ((hi << 8) | lo) + x;
}

uint16_t Cpu::absoluteY()
{
  uint16_t lo = fetch();
    uint16_t hi = fetch();
    return ((hi << 8) | lo) + y;
}

uint16_t Cpu::indirectX()
{
         uint8_t zpAddress = (fetch() + x) & 0xFF;
    uint8_t lo = memory.read(zpAddress);
    uint8_t hi = memory.read((zpAddress + 1) & 0xFF);
    return (hi << 8) | lo;
}

uint16_t Cpu::indirectY()
{
    uint8_t zpAddress = fetch();
    uint8_t lo = memory.read(zpAddress);
    uint8_t hi = memory.read((zpAddress + 1) & 0xFF);
    return ((hi << 8) | lo) + y;
}

uint16_t Cpu::zeroPageY()
{
    return (fetch() + y) & 0xFF;
}

void Cpu::Asl(uint16_t address)
{
      setFlag(CARRY_FLAG, a & 0x80);
    a <<= 1;
    updateZeroAndNegativeFlags(a);
}

void Cpu::AndOp(uint16_t address)
{
    a &= read(address);
    updateZeroAndNegativeFlags(a);
}

void Cpu::Jsr(uint16_t address)
{
     pc--;
    write(0x0100 + sp--, (pc >> 8) & 0xFF);
    write(0x0100 + sp--, pc & 0xFF);
    pc = address;
}

void Cpu::Rts()
{
      pc = (memory.read(0x100 + ++sp) | (memory.read(0x100 + ++sp) << 8)) + 1;
}

void Cpu::Ora(uint16_t address)
{
    a |= read(address);
    updateZeroAndNegativeFlags(a);
}

void Cpu::Rol(uint16_t address)
{
    uint8_t value = read(address);
    uint8_t carry = getFlag(CARRY_FLAG);
    setFlag(CARRY_FLAG, value & 0x80);
    value = (value << 1) | carry;
    write(address, value);
    updateZeroAndNegativeFlags(value);
}

void Cpu::execute()
{
 
    pc = 0x6000;
    sp = 0xFF; // Initialize stack pointer
    int cos = 0;
    while (true) {
        std::cout << "Program Counter (pc): " << std::hex << pc << std::endl;
        unsigned char opcode = fetch();
        std::cout << "Fetched opcode: " << std::hex << (int)opcode << std::endl;
        executeInstruction(opcode);
        std::cout << "Stack Pointer (sp): " << std::hex << (int)sp << std::endl;

        if (opcode == 0x60) {  // RTS opcode
            std::cout << "RTS encountered. Exiting.\n";
            break;
        } 
       std::cout<<x;

           cos++;
        if (cos >= 8)
        {
            break;
        }
    }
}
