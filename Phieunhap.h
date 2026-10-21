#pragma once
#include "Chitietphieunhap.h"
#include "Date.h"
#include<vector>
class Phieunhap{
    private: 
        string maphieu;
        Date ngaynhap;
        int soluonghh;
        vector<Chitietphieunhap> PN;
    public:
        Phieunhap();
        ~Phieunhap();
        Phieunhap(const string, const Date, const int);
        // GETTER
        string getmaphieu();
        Date getngay();
        int getsoluong();
        // SETTER
        void setmaphieu(string);
        void setngay(Date);
        void setsoluong(int);

        friend void docfile(Phieunhap&, const string&);
        void show();
};