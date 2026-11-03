#include "Dsphieunhap.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Dsphieunhap::Dsphieunhap() : soluongphieu(0) {}

Dsphieunhap::~Dsphieunhap() {}

void docfile(Dsphieunhap& ds, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file danh sach phieu nhap: " << filename << endl;
        return;
    }
    
    ds.dsPN.clear();
    string line;
    
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        
        stringstream ss(line);
        string maphieu, ngay, soluong;
        
        getline(ss, maphieu, '|');
        getline(ss, ngay,    '|');
        getline(ss, soluong, '|');
        
        if (maphieu.empty()) continue;
        
        // Tách ngày/tháng/năm từ chuỗi d/m/y
        stringstream ss1(ngay);
        string d, m, y;
        getline(ss1, d, '/');
        getline(ss1, m, '/');
        getline(ss1, y);
        
        Phieunhap temp;
        temp.setmaphieu(maphieu);
        temp.setngay(Date(stoi(d), stoi(m), stoi(y)));
        
        // Nếu trong Phieunhap bạn dùng vector chi tiết riêng, 
        // ở đây có thể bạn đang lưu số lượng dòng chi tiết hoặc tổng số lượng hàng trong file.
        // (Đảm bảo lớp Phieunhap có hàm setsoluong hoặc xử lý tương ứng)
        temp.setsoluong(soluong.empty() ? 0 : stoi(soluong)); 
        
        ds.dsPN.push_back(temp);
    }
    
    ds.soluongphieu = ds.dsPN.size();
    cout << "Doc file danh sach phieu nhap thanh cong! Tong so phieu: " << ds.soluongphieu << endl;
}

void Dsphieunhap::show() const {
    cout << string(50, '=') << endl;
    cout << "DANH SACH PHIEU NHAP (Tong so phieu: " << dsPN.size() << ")" << endl;
    cout << string(50, '-') << endl;
    cout << left
         << setw(12) << "Ma phieu"
         << setw(15) << "Ngay nhap"
         << setw(12) << "So luong" << endl;
    cout << string(50, '-') << endl;

    for (size_t i = 0; i < this->dsPN.size(); i++) {
        cout << left
             << setw(12) << this->dsPN[i].getmaphieu()
             << setw(15) << this->dsPN[i].getngay()
             << setw(12) << this->dsPN[i].getsoluong() << endl;
    }
    cout << string(50, '=') << endl;
}