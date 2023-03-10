#include "vm.hpp"

int main(int argc, char* argv[]) {
    VirtualMachine vm;

    //vm.total_mem();
    vm.load(argv[1]);
    vm.execute();
    //vm.total_mem();

    return 0;
}