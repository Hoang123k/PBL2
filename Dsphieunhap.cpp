#include "Dsphieunhap.h"
#include<fstream>
#include<sstream>
#include<iomanip>
Dsphieunhap::Dsphieunhap(){}
Dsphieunhap::~Dsphieunhap(){}

void docfile(Dsphieunhap& ds, const string& filename){
    ifstream file(filename);
    string line;
    while(getline(file,line)){
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        stringstream ss(line);
        string maphieu, ngay, soluong;
        getline(ss, maphieu,   '|');
        getline(ss, ngay,  '|');
        getline(ss, soluong, '|');
        stringstream ss1(ngay);
        string d,m,y;
        getline(ss1,d,'/');
        getline(ss1,m,'/');
        getline(ss1,y);
        if (maphieu.empty()) continue;
        Phieunhap temp;
        temp.setmaphieu(maphieu);
        temp.setngay(Date(stoi(d),stoi(m),stoi(y)));
        temp.setsoluong(soluong.empty() ? 0 : stoll(soluong));
        ds.dsPN.push_back(temp);
    }
    ds.soluongphieu = ds.dsPN.size();
    printf("Doc file danh sach phieu nhap thanh cong\n");
    
}

void Dsphieunhap::show() {
    cout << "So luong phieu nhap: " << dsPN.size() << endl;
    cout << string(40, '-') << endl;
    cout << left
         << setw(10) << "Ma phieu"
         << setw(10) << "Ngay nhap"
         << setw(10) << "So luong" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < this->dsPN.size(); i++) {
        cout << left
             << setw(10) << this->dsPN[i].getmaphieu()
             << setw(12) << this->dsPN[i].getngay()
             << setw(10) << this->dsPN[i].getsoluong() << endl;
    }
    cout << string(40, '-') << endl;
}