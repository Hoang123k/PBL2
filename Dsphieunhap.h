#pragma once
#include "Phieunhap.h"
class Dsphieunhap{
    private:
        int soluongphieu;
        vector<Phieunhap> dsPN;
    public:
        Dsphieunhap();
        ~Dsphieunhap();
        // void incacphieunhap();

        friend void docfile(Dsphieunhap&, const string&);
        void show();
};