#include "Chitietphieunhap.h"
#include<iomanip>

Chitietphieunhap::Chitietphieunhap(){}
Chitietphieunhap::~Chitietphieunhap(){}
Chitietphieunhap::Chitietphieunhap(const string mahang,
    const string mancc, const int soluongnhap, const int dongianhap)
    : mahang(mahang), mancc(mancc), soluongnhap(soluongnhap), dongianhap(dongianhap){}

int Chitietphieunhap::thanhtien(){
    return this->soluongnhap*this->dongianhap;
}

// GETTER
string Chitietphieunhap::getmahang(){
    return this->mahang;
}
string Chitietphieunhap::getmancc(){
    return this->mancc;
}
int Chitietphieunhap::getsoluongnhap(){
    return this->soluongnhap;
}
int Chitietphieunhap::getdongianhap(){
    return this->dongianhap;
}
// SETTER
void Chitietphieunhap::setmahang(string mahang){
    this->mahang = mahang;
}
void Chitietphieunhap::setmancc(string mancc){
    this->mancc = mancc;
}
void Chitietphieunhap::setsoluongnhap(int soluong){
    this->soluongnhap = soluong;
}
void Chitietphieunhap::setdongianhap(int dongia){
    this->dongianhap = dongia;
}

void Chitietphieunhap::show(){
    cout << left
         << setw(10) << this->mahang
         << setw(10) << this->mancc
         << setw(15)  << this->soluongnhap
         << setw(15) << this->dongianhap << endl;
}