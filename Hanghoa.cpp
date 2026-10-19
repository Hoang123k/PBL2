#include "Hanghoa.h"
#include<string.h>
Hanghoa::Hanghoa(){}
Hanghoa::~Hanghoa(){}
Hanghoa::Hanghoa(const string mahang, const string tenhang, 
    const string loaihang, const string donvitinh,
    const int soluong,const int dongia) 
    : mahang(mahang), tenhang(tenhang), loaihang(loaihang),
    donvitinh(donvitinh), soluong(soluong), dongia(dongia){}

// GETTER
string Hanghoa::getmahang(){
    return this->mahang;
}
string Hanghoa::gettenhang(){
    return this->tenhang;
}
string Hanghoa::getloaihang(){
    return this->loaihang;
}
string Hanghoa::getdonvitinh(){
    return this->donvitinh;
}
int Hanghoa::getsoluong(){
    return this->soluong;
}
int Hanghoa::getdongia(){
    return this->dongia;
}

// SETTER

void Hanghoa::setmahang(string mahang){
    this->mahang = mahang;
}
void Hanghoa::settenhang(string tenhang){
    this->tenhang = tenhang;
}
void Hanghoa::setloaihang(string loaihang){
    this->loaihang = loaihang;
}
void Hanghoa::setdonvitinh(string donvitinh){
    this->donvitinh = donvitinh;
}
void Hanghoa::setsoluong(int soluong){
    this->soluong = soluong;
}
void Hanghoa::setdongia(int dongia){
    this->dongia = dongia;
}

void Hanghoa::show(){
    cout << "Ma hang: " << this->mahang << " | "
        << "Ten hang: " << this->tenhang << " | "
        << "Loai hang: " << this->loaihang << " | "
        << "Don vi tinh: " << this->donvitinh << " | "
        << "So luong: " << this->soluong << " | "
        << "Don gia: " << this->dongia << " | " << endl;
}