#pragma once
#include <iostream>
#include "Date.h"
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

inline long long stringToLL(const string &str)
{
    if (str.empty())
    {
        throw invalid_argument("Chuỗi rỗng");
    }
    return stoll(str);
}

inline int stringToINT(const string &str)
{
    if (str.empty())
    {
        throw invalid_argument("Chuỗi rỗng");
    }
    return stoi(str);
}

inline string toUpperString(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = toupper(static_cast<unsigned char>(str[i]));
    }
    return str;
}

inline string toLowerString(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = tolower(static_cast<unsigned char>(str[i]));
    }
    return str;
}