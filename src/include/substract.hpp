#pragma once

class Substract {
public:
    void print_substract(const int a, const int b) const;
private:
    // テスト用に子クラスから書き換えるためvirtualをつける。
    virtual void print_int(const int val) const;
};
