#include "Phieunhap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Phieunhap::Phieunhap() : soluonghh(0) {}

Phieunhap::~Phieunhap() {}

Phieunhap::Phieunhap(const string& maphieu, const Date& ngay, int soluong)
    : maphieu(maphieu), ngaynhap(ngay), soluonghh(soluong) {}

string Phieunhap::getmaphieu() const {
    return this->maphieu;
}

Date Phieunhap::getngay() const {
    return this->ngaynhap;
}

int Phieunhap::getsoluong() const {
    return this->soluonghh;
}

void Phieunhap::setmaphieu(const string& maphieu) {
    this->maphieu = maphieu;
}

void Phieunhap::setngay(const Date& ngay) {
    this->ngaynhap = ngay;
}

void Phieunhap::setsoluong(int soluong) {
    this->soluonghh = soluong;
}

void docfile(Phieunhap& pn, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file phieu nhap: " << filename << endl;
        return;
    }
    
    pn.PN.clear();
    string line;
    
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        
        stringstream ss(line);
        string mahang, mancc, soluong, dongia;
        
        getline(ss, mahang, '|');
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
    cout << "Doc file phieu nhap thanh cong! Tong so mat hang: " << pn.soluonghh << endl;
}

void Phieunhap::show() const {
    cout << string(65, '=') << endl;
    cout << left 
         << setw(12) << "Ma Phieu: " << setw(15) << this->maphieu
         << setw(12) << "Ngay Nhap: " << this->ngaynhap << endl;
         
    cout << "So luong mat hang: " << this->soluonghh << endl;
    cout << string(65, '-') << endl;
    
    cout << left
         << setw(12) << "Ma Hang"
         << setw(12) << "Ma NCC"
         << setw(15) << "So Luong"
         << setw(15) << "Don Gia" << endl;
    cout << string(65, '-') << endl;            
    
    for (size_t i = 0; i < this->PN.size(); i++) {
        this->PN[i].show();
    }
    cout << string(65, '=') << endl;
}