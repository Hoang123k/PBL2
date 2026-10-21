#include "qlncc.h"
#include<fstream>
#include<sstream>
#include<iomanip>

qlncc::qlncc(){}
qlncc::~qlncc(){}

void docfile(qlncc& ql,const string& filename){
    ifstream file(filename);
    string line;
    while(getline(file,line)){
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        stringstream ss(line);
        string ma, ten, sdt, dc;
        getline(ss, ma,   '|');
        getline(ss, ten,  '|');
        getline(ss, sdt, '|');
        getline(ss, dc,  '|');
        if (ma.empty()) continue;
        Ncc n;
        n.setmancc(ma);
        n.settenncc(ten);
        n.setsdtncc(sdt);
        n.setdiachincc(dc);
        ql.ql_ncc.push_back(n);
    }
    ql.soluong_ncc = ql.ql_ncc.size();
    printf("Doc file nha cung cap thanh cong\n");
}

void qlncc::show(){
    cout << "So luong nha cung cap: " << this->soluong_ncc << endl;
    cout << left
        << setw(12) << "Ma NCC"
        << setw(28) << "Ten NCC"
        << setw(15) << "SDT"
        << "Dia chi" << endl;
    cout << string(75, '-') << endl;              
    for (size_t i = 0; i < ql_ncc.size(); i++) {
        cout << left
            << setw(12) << ql_ncc[i].getmancc()
            << setw(28) << ql_ncc[i].gettenncc()
            << setw(15) << ql_ncc[i].getsdtncc()
            << ql_ncc[i].getdiachincc() << endl;
    }
}