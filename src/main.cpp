#include <chrono>
#include <iostream>
#include <vector>

#include "add.hpp"
#include "multiply.hpp"
#include "substract.hpp"
#include "make_string.hpp"

#ifndef APP_VERSION
#define APP_VERSION "UnknownVersion"
#endif
#ifndef GIT_STATUS
#define GIT_STATUS "UnknownGitStatus"
#endif
const std::string appVersion = APP_VERSION;
const std::string gitStatus = GIT_STATUS;

void printTime(
    const std::string& head,
    const std::chrono::steady_clock::time_point start,
    const std::chrono::steady_clock::time_point end
) {
    double timeMs = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);

    std::cout << head << " -> timeMs=" << timeMs << std::endl;
}


int main(void) {
    std::cout << "appVersion: " << appVersion << std::endl;
    std::cout << "gitStatus: " << gitStatus << std::endl;
    std::cout << "add result: " << add(1, 2) << std::endl;

    std::cout << "multiply result: ";
    print_multiply(2, 3);

    std::cout << "substract result: ";
    Substract().print_substract(5, 2);


    const int stringSize = 1 << 15;
    const int arraySize = stringSize + 1;
    std::string str1, str2;
    char str3[arraySize];

    const std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
    str1 = make_string_return(stringSize);
    const std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

    const std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
    make_string_arg(str2, stringSize);
    const std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

    const std::chrono::steady_clock::time_point start3 = std::chrono::steady_clock::now();
    make_chars(str3, stringSize);
    const std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();

    printTime("make_string_return", start1, end1);
    printTime("make_string_arg   ", start2, end2);
    printTime("make_chars        ", start3, end3);

    return 0;
}
