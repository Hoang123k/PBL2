#include "Chitietphieunhap.h"
#include <iomanip>
#include <iostream>

using namespace std;

Chitietphieunhap::Chitietphieunhap() : soluongnhap(0), dongianhap(0) {}

Chitietphieunhap::~Chitietphieunhap() {}

Chitietphieunhap::Chitietphieunhap(const string& mahang, const string& mancc, long long soluongnhap, long long dongianhap)
    : mahang(mahang), mancc(mancc), soluongnhap(soluongnhap), dongianhap(dongianhap) {}

long long Chitietphieunhap::thanhtien() const {
    return this->soluongnhap * this->dongianhap;
}

// GETTER
string Chitietphieunhap::getmahang() const {
    return this->mahang;
}
string Chitietphieunhap::getmancc() const {
    return this->mancc;
}
long long Chitietphieunhap::getsoluongnhap() const {
    return this->soluongnhap;
}
long long Chitietphieunhap::getdongianhap() const {
    return this->dongianhap;
}

// SETTER
void Chitietphieunhap::setmahang(const string& mahang) {
    this->mahang = mahang;
}
void Chitietphieunhap::setmancc(const string& mancc) {
    this->mancc = mancc;
}
void Chitietphieunhap::setsoluongnhap(long long soluongnhap) {
    this->soluongnhap = soluongnhap;
}
void Chitietphieunhap::setdongianhap(long long dongianhap) {
    this->dongianhap = dongianhap;
}

void Chitietphieunhap::show() const {
    cout << left
         << setw(10) << this->mahang
         << setw(10) << this->mancc
         << setw(15) << this->soluongnhap
         << setw(15) << this->dongianhap 
         << setw(15) << this->thanhtien() << endl; // Tiện thể in luôn thành tiền cho đẹp bảng
}