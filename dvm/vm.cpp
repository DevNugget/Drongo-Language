#include "vm.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void VirtualMachine::total_mem() {
    size_t total_mem = 0;
    total_mem += u64_stack.capacity() * sizeof(uint64_t);
    total_mem += u32_stack.capacity() * sizeof(uint32_t);
    total_mem += u16_stack.capacity() * sizeof(uint16_t);
    total_mem += u8_stack.capacity() * sizeof(uint8_t);
    total_mem += i64_stack.capacity() * sizeof(int64_t);
    total_mem += i32_stack.capacity() * sizeof(int32_t);
    total_mem += i16_stack.capacity() * sizeof(int16_t);
    total_mem += i8_stack.capacity() * sizeof(int8_t);
    std::cout << "Total memory usage: " << total_mem << " bytes\n";
}

void VirtualMachine::mem_test() {
    return;
}

void VirtualMachine::execute() {
    for (;;) {
        switch(code[ip++]) {
            case END: {
                return;
            }

            case I8_PUSH: {
                i8_stack.push_back(code[ip++]);
                break;
            }

            case I16_PUSH: {
                i16_stack.push_back(code[ip++]);
                break;
            }

            case I32_PUSH: {
                i32_stack.push_back(code[ip++]);
                break;
            }

            case I64_PUSH: {
                i64_stack.push_back(code[ip++]);
                break;
            }

            case U8_PUSH: {
                u8_stack.push_back(code[ip++]);
                break;
            }

            case U16_PUSH: {
                u16_stack.push_back(code[ip++]);
                break;
            }

            case U32_PUSH: {
                u32_stack.push_back(code[ip++]);
                break;
            }

            case U64_PUSH: {
                u64_stack.push_back(code[ip++]);
                break;
            }

            case I8_PUT: {
                std::cout << (int32_t)i8_stack.back() << '\n';
                i8_stack.pop_back();
                break;
            }

            case I16_PUT: {
                std::cout << (int32_t)i16_stack.back() << '\n';
                i16_stack.pop_back();
                break;
            }

            case I32_PUT: {
                std::cout << i32_stack.back() << '\n';
                i32_stack.pop_back();
                break;
            }

            case I64_PUT: {
                std::cout << i64_stack.back() << '\n';
                i64_stack.pop_back();
                break;
            }

            case U8_PUT: {
                std::cout << (int32_t)u8_stack.back() << '\n';
                u8_stack.pop_back();
                break;
            }

            case U16_PUT: {
                std::cout << (int32_t)u16_stack.back() << '\n';
                u16_stack.pop_back();
                break;
            }

            case U32_PUT: {
                std::cout << u32_stack.back() << '\n';
                u32_stack.pop_back();
                break;
            }

            case U64_PUT: {
                std::cout << u64_stack.back() << '\n';
                u64_stack.pop_back();
                break;
            }

            case PTR_I8: {
                stack_pointer ptr;
                ptr.stack_type = "i8";
                ptr.address = i8_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_I16: {
                stack_pointer ptr;
                ptr.stack_type = "i16";
                ptr.address = i16_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_I32: {
                stack_pointer ptr;
                ptr.stack_type = "i32";
                ptr.address = i32_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_I64: {
                stack_pointer ptr;
                ptr.stack_type = "i64";
                ptr.address = i64_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_U8: {
                stack_pointer ptr;
                ptr.stack_type = "i8";
                ptr.address = u8_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_U16: {
                stack_pointer ptr;
                ptr.stack_type = "i16";
                ptr.address = u16_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_U32: {
                stack_pointer ptr;
                ptr.stack_type = "i32";
                ptr.address = u32_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_U64: {
                stack_pointer ptr;
                ptr.stack_type = "i64";
                ptr.address = u64_stack.size() - 1;
                pointer_stack.push_back(ptr);
                break;
            }

            case PTR_ADD: {
                stack_pointer ptr2 = pointer_stack.back();
                pointer_stack.pop_back();
                stack_pointer ptr1 = pointer_stack.back();
                pointer_stack.pop_back();
                int a, b;

                if (ptr2.stack_type == "i8") {
                    a = i8_stack[ptr2.address];
                } else if (ptr2.stack_type == "i16") {
                    a = i16_stack[ptr2.address];
                } else if (ptr2.stack_type == "i32") {
                    a = i32_stack[ptr2.address];
                } else if (ptr2.stack_type == "i64") {
                    a = i64_stack[ptr2.address];
                } else if (ptr2.stack_type == "u8") {
                    a = u8_stack[ptr2.address];
                } else if (ptr2.stack_type == "u16") {
                    a = u16_stack[ptr2.address];
                } else if (ptr2.stack_type == "u32") {
                    a = u32_stack[ptr2.address];
                } else if (ptr2.stack_type == "u64") {
                    a = u64_stack[ptr2.address];
                }

                if (ptr1.stack_type == "i8") {
                    b = i8_stack[ptr1.address];
                } else if (ptr1.stack_type == "i16") {
                    b = i16_stack[ptr1.address];
                } else if (ptr1.stack_type == "i32") {
                    b = i32_stack[ptr1.address];
                } else if (ptr1.stack_type == "i64") {
                    b = i64_stack[ptr1.address];
                } else if (ptr1.stack_type == "u8") {
                    b = u8_stack[ptr1.address];
                } else if (ptr1.stack_type == "u16") {
                    b = u16_stack[ptr1.address];
                } else if (ptr1.stack_type == "u32") {
                    b = u32_stack[ptr1.address];
                } else if (ptr1.stack_type == "u64") {
                    b = u64_stack[ptr1.address];
                }
                //std::cout << "a: " << a << "\nb: " << b << '\n';
                return_reg = a + b;
                break;
            }

            case I_RET: {
                int8_t ret_type = code[ip++];
                switch(ret_type) {
                    case 8: {
                        i8_stack.push_back((int8_t)return_reg);
                        break;
                    }

                    case 16: {
                        i16_stack.push_back((int16_t)return_reg);
                        break;
                    }

                    case 32: {
                        i32_stack.push_back((int32_t)return_reg);
                        break;
                    }

                    case 64: {
                        i64_stack.push_back(return_reg);
                        break;
                    }
                }
                break;
            }

            case U_RET: {
                int8_t ret_type = code[ip++];
                switch(ret_type) {
                    case 8: {
                        u8_stack.push_back(return_reg);
                        break;
                    }

                    case 16: {
                        u16_stack.push_back(return_reg);
                        break;
                    }

                    case 32: {
                        u32_stack.push_back(return_reg);
                        break;
                    }

                    case 64: {
                        u64_stack.push_back(return_reg);
                        break;
                    }
                }
                break;
            }
        }
    }
}

bool VirtualMachine::load(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            code.push_back(value);
        }
    }
    return true;
}

