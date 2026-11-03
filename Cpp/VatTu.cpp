#include "VatTu.h"
#include <iomanip>
#include <iostream>

using namespace std;

VatTu::VatTu() : Hanghoa(), chatlieu("") {}

VatTu::VatTu(const string& ma, const string& ten, const string& loai, 
             const string& dvt, int sl, int gia, const string& cl)
    : Hanghoa(ma, ten, loai, dvt, sl, gia), chatlieu(cl) {}

string VatTu::getthuoctinh() const {
    
    return chatlieu;
}
void VatTu::setthuoctinh(const string& cl) {
    chatlieu = cl;
}
void VatTu::show(){
    cout << left
         << setw(10) << mahang 
         << setw(22) << tenhang
         << setw(20) << loaihang 
         << setw(15) << donvitinh
         << setw(12) << soluong 
         << setw(10) << dongia
         << setw(15) << chatlieu << endl;
}