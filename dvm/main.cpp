#include "vm.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    VirtualMachine vm;

    vm.total_mem();

    if (!vm.load(argv[1])) {
        std::cout << "Could not load bytecode." << '\n';
    }

    vm.execute();
    vm.total_mem();

    return 0;
}