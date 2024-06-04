#include <iostream>
#include "print_int.hpp"
#include "substract.hpp"

void Substract::print_substract(const int a, const int b) const {
    print_int(a - b);
}

void Substract::print_int(const int val) const {
    // プロダクト時はグローバルで定義した関数を呼ぶ。
    ::print_int(val);
}
