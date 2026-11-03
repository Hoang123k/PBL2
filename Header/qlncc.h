#pragma once
#include "Ncc.h"
#include <vector>
#include <memory>
#include <string>

class qlncc {
public:
    int soluong_ncc;
    std::vector<std::unique_ptr<Ncc>> ql_ncc;

    qlncc();
    ~qlncc();

    friend void docfile(qlncc& ql, const std::string& filename);
    void show() const;
};