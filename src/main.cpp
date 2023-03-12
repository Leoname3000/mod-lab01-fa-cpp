// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    char *str = const_cast<char*>("  Ab9cd   Abcd abc  AB");
    std::cout << faStr1(str) << std::endl;
    std::cout << faStr2(str) << std::endl;
    std::cout << faStr3(str) << std::endl;
    return 0;
}
