#include "Phieunhap.h"
#include<fstream>
#include<sstream>
#include<iomanip>

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

void docfile(Phieunhap& pn,const string& filename){
    ifstream file(filename);
    string line;
    while(getline(file,line)){
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        stringstream ss(line);
        string mahang, mancc, soluong, dongia;
        getline(ss, mahang,   '|');
        getline(ss, mancc,  '|');
        getline(ss, soluong, '|');
        getline(ss, dongia,  '|');
        if (mahang.empty() || mancc.empty()) continue;
        Chitietphieunhap temp;
        temp.setmahang(mahang);
        temp.setmancc(mancc);
        temp.setsoluongnhap(soluong.empty() ? 0 : stoi(soluong));
        temp.setdongianhap(dongia.empty() ? 0 : stoi(dongia));
        pn.PN.push_back(temp);
    }
    pn.soluonghh = pn.PN.size();
    printf("Doc file phieu nhap thanh cong\n");
}

void Phieunhap::show(){
    cout << left 
         << setw(10) << "Ma Phieu" << this->maphieu
         << setw(12) << "Ngay Nhap" << this->ngaynhap
         << setw(15) << "So luong hh" << this->soluonghh<< endl;

    cout << left
         << setw(10) << "Ma Hang"
         << setw(10) << "Ma NCC"
         << setw(15) << "So Luong Nhap"
         << setw(15) << "Don Gia Nhap" << endl;
    cout << string(75, '-') << endl;              
    for(int i=0;i<this->PN.size();i++){
        this->PN[i].show();
    }
}