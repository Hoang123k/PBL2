#pragma once
#include <string>

class Chitietphieunhap {
private:
    std::string mahang;
    std::string mancc;
    long long soluongnhap;
    long long dongianhap;

public:
    Chitietphieunhap();
    ~Chitietphieunhap();
    Chitietphieunhap(const std::string& mahang, const std::string& mancc, long long soluongnhap, long long dongianhap);

    long long thanhtien() const;

    // GETTER (Thêm const)
    std::string getmahang() const;
    std::string getmancc() const;
    long long getsoluongnhap() const;
    long long getdongianhap() const;

    // SETTER (Dùng const std::string&)
    void setmahang(const std::string& mahang);
    void setmancc(const std::string& mancc);
    void setsoluongnhap(long long soluongnhap);
    void setdongianhap(long long dongianhap);

    void show() const;
};