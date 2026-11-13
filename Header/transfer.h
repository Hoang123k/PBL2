#pragma once
#include<iostream>
inline long long stringToLL(const std::string& str) {
    if (str.empty()) {
        throw invalid_argument("Chuoi rong");
    }
    return stoll(str);
}
