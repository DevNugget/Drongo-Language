#include "errors.hpp"
#include <iostream>

void error(std::string msg) {
    std::cerr << "ERROR: " << msg << '\n';
}