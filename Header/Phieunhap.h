#pragma once
#include "Chitietphieunhap.h"
#include "Date.h"
#include <string>
#include <vector>

class Phieunhap {
private: 
    std::string maphieu;
    Date ngaynhap;
    int soluonghh;
    std::vector<Chitietphieunhap> PN;

public:
    Phieunhap();
    ~Phieunhap();
    Phieunhap(const std::string& maphieu, const Date& ngaynhap, int soluong = 0);

    std::string getmaphieu() const;
    Date getngay() const;
    int getsoluong() const;

    void setmaphieu(const std::string& maphieu);
    void setngay(const Date& ngaynhap);
    void setsoluong(int soluong);

    friend void docfile(Phieunhap& pn, const std::string& filename);
    void show() const; // Đảm bảo có từ khóa const ở đây
};