#include <string>
#include "make_string.hpp"


std::string make_string_return(const int stringSize) {
    std::string output = "";

    for (int i = 0; i < stringSize; i++) {
        output += "a";
    }
    return output;
}

void make_string_arg(std::string& output, const int stringSize) {
    output = "";

    for (int i = 0; i < stringSize; i++) {
        output += "a";
    }
}

void make_chars(char* output, const int stringSize) {
    for (int i = 0; i < stringSize; i++) {
        output[i] = 'a';
    }
    output[stringSize] = '\0';
}
