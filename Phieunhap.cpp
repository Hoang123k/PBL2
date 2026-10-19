#include "Phieunhap.h"
Phieunhap::Phieunhap(){}
Phieunhap::~Phieunhap(){}
Phieunhap::Phieunhap(const string maphieu, const Date ngay, const int soluong)
    : maphieu(maphieu), ngaynhap(ngay), soluonghh(soluong){}
string Phieunhap::getmaphieu(){
    return this->maphieu;
}
Date Phieunhap::getngay(){
    return this->ngaynhap;
}
int Phieunhap::getsoluong(){
    return this->soluonghh;
}
void Phieunhap::setmaphieu(string maphieu){
    this->maphieu = maphieu;
}
void Phieunhap::setngay(Date ngay){
    this->ngaynhap = ngay;
}
void Phieunhap::setsoluong(int soluong){
    this->soluonghh = soluong;
}