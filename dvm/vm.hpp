#ifndef VM_H
#define VM_H

#define END      0x00
#define I8_PUSH  0x01
#define I16_PUSH 0x02
#define I32_PUSH 0x03
#define I64_PUSH 0x04
#define U8_PUSH  0x05
#define U16_PUSH 0x06
#define U32_PUSH 0x07
#define U64_PUSH 0x08
#define POP      0x09
#define I8_PUT   0x0A
#define I16_PUT  0x0B
#define I32_PUT  0x0C
#define I64_PUT  0x0D
#define U8_PUT   0x0E
#define U16_PUT  0x0F
#define U32_PUT  0x10
#define U64_PUT  0x11
#define PTR_I8   0x12
#define PTR_I16  0x13
#define PTR_I32  0x14
#define PTR_I64  0x15
#define PTR_U8   0x16
#define PTR_U16  0x17
#define PTR_U32  0x18
#define PTR_U64  0x19

#include <cinttypes>
#include <vector>
#include <string>

class VirtualMachine {
public:
    int ip = 0;

    struct stack_pointer {
        std::string stack_type;
        int32_t address;
    };

    std::vector<uint64_t> u64_stack;
    std::vector<uint32_t> u32_stack;
    std::vector<uint16_t> u16_stack;
    std::vector<uint8_t>   u8_stack;
    std::vector<int64_t>  i64_stack;
    std::vector<int32_t>  i32_stack;
    std::vector<int16_t>  i16_stack;
    std::vector<int8_t>    i8_stack;
    std::vector<stack_pointer>  pointer_stack;

    std::vector<int> code;

    void execute();
    bool load(const char* filename);

    // Debug functions
    void total_mem();
    void mem_test();
};


#endif