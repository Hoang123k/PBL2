#include "qlncc.h"
#include "NccTrongNuoc.h"
#include "NccQuocTe.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

qlncc::qlncc() : soluong_ncc(0) {}
qlncc::~qlncc() {}

void docfile(qlncc& ql, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file ncc: " << filename << endl;
        return;
    }
    
    ql.ql_ncc.clear();
    string line;
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        
        stringstream ss(line);
        string loai, ma, ten, sdt, dc, mathue, extra;
        
        getline(ss, loai, '|');
        getline(ss, ma,   '|');
        getline(ss, ten,  '|');
        getline(ss, sdt,  '|');
        getline(ss, dc,   '|');
        getline(ss, mathue, '|');
        getline(ss, extra, '|');
        
        if (loai == "TN") {
            ql.ql_ncc.push_back(make_unique<NccTrongNuoc>(ma, ten, sdt, dc, mathue));
        } else if (loai == "QT") {
            ql.ql_ncc.push_back(make_unique<NccQuocTe>(ma, ten, sdt, dc, mathue, extra));
        }
    }
    ql.soluong_ncc = ql.ql_ncc.size();
    cout << "Doc file NCC thanh cong!" << endl;
}

void qlncc::show() const {
    cout << "So luong nha cung cap: " << this->soluong_ncc << endl;
    cout << string(75, '-') << endl;
    cout << left
         << setw(8)  << "Loai"
         << setw(12) << "Ma NCC"
         << setw(28) << "Ten NCC"
         << setw(15) << "SDT"
         << setw(15) << "Dia Chi" << endl;
    cout << string(75, '-') << endl;
    for (size_t i = 0; i < ql_ncc.size(); i++) {
        ql_ncc[i]->show();
    }
    cout << string(75, '=') << endl;
}