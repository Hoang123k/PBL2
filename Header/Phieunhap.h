#pragma once
#include "Chitietphieunhap.h"
#include "Date.h"
#include "Kho.h"
#include "qlncc.h"
#include <string>
#include <vector>
class Dsphieunhap;
class Phieunhap {
private: 
    std::string maphieu;
    Date ngaynhap;
    long long soluonghh;
    std::vector<Chitietphieunhap> PN;
    
public:
    bool save_PN = 1;
    Phieunhap();
    ~Phieunhap();
    Phieunhap(const std::string& maphieu, const Date& ngaynhap, int soluong = 0);

    std::string getmaphieu() const;
    Date getngay() const;
    int getsoluong() const;
    std::vector<Chitietphieunhap>& getPN();

    void setmaphieu(const std::string& maphieu);
    void setngay(const Date& ngaynhap);
    void setsoluong(int soluong);
    void setPN(const std::vector<Chitietphieunhap>& PN);

    friend void docfile(Phieunhap& pn, const std::string& filename);
    friend void luufile(Phieunhap& pn, const std::string& filename);

    // cost
    friend long long cost_PN(Phieunhap& pn);
    

    void show() const;

    //them
    int check_mahang_ncc(const std::string, const std::string);
    bool add_1hh(Kho&, qlncc&, Dsphieunhap*);
    void add_nhh(const int&,Kho&,qlncc&, Dsphieunhap*);

    // //sort
    void sortByMaHang(vector<Chitietphieunhap> &pn,int low, int high);
    // search
    // update
    // xoa


    

};