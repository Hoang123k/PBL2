#pragma once
#include "Hanghoa.h"
#include "Ncc.h"
class Chitietphieunhap{
    private:
        string mahang;
        string mancc;
        int soluongnhap;
        int dongianhap;
    public:
        Chitietphieunhap();
        ~Chitietphieunhap();
        Chitietphieunhap(const string, const string, const int, const int);
        int thanhtien();
        // GETTER
        int getsoluongnhap();
        int getdongianhap();
        // SETTER
        void setsoluongnhap(int);
        void setdongianhap(int);
};