#include <iostream>
#include <vector>
#include "add.hpp"
#include "multiply.hpp"
#include "substract.hpp"


int main(void) {
    std::cout << "add result: " << add(1, 2) << std::endl;

    std::cout << "multiply result: ";
    print_multiply(2, 3);

    std::cout << "substract result: ";
    Substract().print_substract(5, 2);

    return 0;
}
