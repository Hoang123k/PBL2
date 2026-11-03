#pragma once
#include "Phieunhap.h"
#include <string>
#include <vector>

class Dsphieunhap {
private:
    int soluongphieu;
    std::vector<Phieunhap> dsPN;

public:
    Dsphieunhap();
    ~Dsphieunhap();

    friend void docfile(Dsphieunhap& ds, const std::string& filename);
    void show() const; // Thêm const
};