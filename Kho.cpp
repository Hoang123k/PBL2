#include "Kho.h"
#include<fstream>
#include<sstream>
#include<iomanip>

Kho::Kho(){}
Kho::~Kho(){}
void Kho::show(){
    cout << "So luong hang hoa hien tai tring kho: " << this->soluonghang << endl;
    cout << left
        << setw(10) << "Ma Hang"
        << setw(18) << "Ten Hang"
        << setw(12)  << "Loai Hang"
        << setw(15)  << "Don vi tinh"
        << setw(12)  << "So luong"
        << setw(10) << "Don gia" << endl;
    cout << string(75, '-') << endl;              

    for(int i=0;i<this->kho.size();i++){
        this->kho[i].show();
    }
}
void docfile(Kho& k,const string& filename){
    ifstream file(filename);
    string line;
    while(getline(file,line)){
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        stringstream ss(line);
        string ma, ten, loai, dvt, sl, gia;
        getline(ss, ma,   '|');
        getline(ss, ten,  '|');
        getline(ss, loai, '|');
        getline(ss, dvt,  '|');
        getline(ss, sl,   '|');
        getline(ss, gia,  '|');
        if (ma.empty()) continue;

        Hanghoa h;
        h.setmahang(ma);
        h.settenhang(ten);
        h.setloaihang(loai);
        h.setdonvitinh(dvt);
        h.setsoluong(sl.empty() ? 0 : stoll(sl));
        h.setdongia(gia.empty() ? 0 : stod(gia));
        k.kho.push_back(h);
    }
    k.soluonghang = k.kho.size();
    printf("Doc file quan li kho thanh cong\n");
}