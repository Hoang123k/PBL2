#pragma once
#include <string>
#include <vector>
#include "Phieunhap.h"

class Dsphieunhap
{
private:
    int soluongphieu;
    std::vector<Phieunhap> dsPN;

public:
    Dsphieunhap();
    ~Dsphieunhap();

    // Getter
    int &getsoluongphieu();
    std::vector<Phieunhap> &getdsPN();

    // setter
    void setsoluongphieu(const int &);
    void setdsPN(const std::vector<Phieunhap> &);

    friend void docfile(Dsphieunhap &ds, const std::string &filename);
    friend void luuphieunhap(Dsphieunhap &ds, const string &filename);
    friend void luufile(Dsphieunhap &ds, const std::string &filename);

    // cost
    friend long long TK_1thang(Dsphieunhap& ds);
    friend long long TK_1ngay(Dsphieunhap& ds);
    friend long long TK_khoangtg(Dsphieunhap& ds);
    Phieunhap& max_PN();

    void show() const;
    // thêm
    int get_index_maphieu(std::string);
    bool check_maphieu(const std::string);
    bool check_date(const Date &);
    void add(Kho &, qlncc &);
    // update
    void update();
    // sort
    void sortByMaPhieu(std::vector<Phieunhap> &ds, int low, int high);
    void sortByNgayNhap(std::vector<Phieunhap> &ds, int low, int high);
    void sortBySoLuong(std::vector<Phieunhap> &ds, int low, int high);

    // find
    void searchByMaPhieu(const std::string &ma) const;
    void searchByNgayNhap(const Date &ngay) const;
    // delete
    void deleteByMaPhieu(const std::string &ma);
};