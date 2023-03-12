// Copyright 2022 UNN-IASR
#include <cstring>
#include <cctype>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
        }
        if (inWord && isdigit(str[i])) {
            hasDigit = true;
        }
        if (str[i] == ' ' && inWord) {
            inWord = false;
            if (!hasDigit) {
                count++;
            }
            hasDigit = false;
        }
    }
    if (inWord && !hasDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasIllegalSymbols = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                if (!isupper(str[i])) {
                    hasIllegalSymbols = true;
                }
            } else if (!islower(str[i])) {
                hasIllegalSymbols = true;
            }
        }
        if (str[i] == ' ' && inWord) {
            inWord = false;
            if (!hasIllegalSymbols) {
                count++;
            }
            hasIllegalSymbols = false;
        }
    }
    if (inWord && !hasIllegalSymbols) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int symbols = 0;
    unsigned int words = 0;
    bool inWord = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
        }
        if (inWord) {
            if (str[i] != ' ') {
                symbols++;
            } else {
                inWord = false;
                words++;
            }
        }
    }
    if (inWord) {
        words++;
    }
    if (words == 0) {
        return 0;
    }
    double symbolsAverage = static_cast<double>(symbols) / words;
    return static_cast<unsigned int>(round(symbolsAverage));
}
