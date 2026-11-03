#include "ThucPham.h"
#include <iomanip>
#include <iostream>

using namespace std;

ThucPham::ThucPham() : Hanghoa(), ngayhethan("") {}

ThucPham::ThucPham(const string& ma, const string& ten, const string& loai, 
                   const string& dvt, int sl, int gia, const string& hsd)
    : Hanghoa(ma, ten, loai, dvt, sl, gia), ngayhethan(hsd) {}

string ThucPham::getthuoctinh() const {
    return ngayhethan;
}
void ThucPham::setthuoctinh(const string& hsd) {
    ngayhethan = hsd;
}
void ThucPham::show() {
    cout << left
         << setw(10) << mahang 
         << setw(22) << tenhang
         << setw(20) << loaihang 
         << setw(15) << donvitinh
         << setw(12) << soluong 
         << setw(10) << dongia
         << setw(15) << ngayhethan << endl;
}