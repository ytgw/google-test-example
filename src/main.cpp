#include <iostream>
#include <vector>
#include "add.hpp"
#include "multiply.hpp"


int main(void) {
    std::cout << "add result: " << add(1, 2) << std::endl;
    print_multiply(2, 3);

    return 0;
}
