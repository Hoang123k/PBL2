#include "Chitietphieunhap.h"
Chitietphieunhap::Chitietphieunhap(){}
Chitietphieunhap::~Chitietphieunhap(){}
Chitietphieunhap::Chitietphieunhap(const string mahang,
    const string mancc, const int soluongnhap, const int dongianhap)
    : mahang(mahang), mancc(mancc), soluongnhap(soluongnhap), dongianhap(dongianhap){}
int Chitietphieunhap::thanhtien(){
    return this->soluongnhap*this->dongianhap;
}
// GETTER
int Chitietphieunhap::getsoluongnhap(){
    return this->soluongnhap;
}
int Chitietphieunhap::getdongianhap(){
    return this->dongianhap;
}
// SETTER
void Chitietphieunhap::setsoluongnhap(int soluong){
    this->soluongnhap = soluong;
}
void Chitietphieunhap::setdongianhap(int dongia){
    this->dongianhap = dongia;
}