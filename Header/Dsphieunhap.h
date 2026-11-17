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
    bool save_dsPN = 1;
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

    // Báo cáo và thống kế
    // Thống kê hàng nhập
        // cost
        friend long long TK_1thang(Dsphieunhap& ds);
        friend long long TK_1ngay(Dsphieunhap& ds);
        friend long long TK_khoangtg(Dsphieunhap& ds);
        void max_PN();


    // Thống kê tồn kho
    void canhbao_hsd(Kho& kho);

    // Thống kê nhà cung cấp
    void Tyle_Ncc(qlncc &n);
    friend long long cost_PN(Phieunhap &pn);
    long long tong_gtri_ncc(const std::string &ma);
    void ncc_biggest(qlncc &n);

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
    void searchByNgayNhap(Date &ngay) const;
    // delete
    void deleteByMaPhieu(const std::string &ma);
};