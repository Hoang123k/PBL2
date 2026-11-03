#include "NccQuocTe.h"
#include <iomanip>
#include <iostream>

using namespace std;

NccQuocTe::NccQuocTe() : Ncc(), quocgia("") { loaincc = "QT"; }

NccQuocTe::NccQuocTe(const string& ma, const string& ten, const string& sdt, const string& dc, const string& mst, const string& qg)
    : Ncc(ma, ten, sdt, dc), quocgia(qg) {
    loaincc = "QT";
    masothue = mst;
}

void NccQuocTe::show() const { // Thêm const
    cout << left
         << setw(8)  << loaincc
         << setw(12) << mancc 
         << setw(28) << tenncc
         << setw(15) << sdtncc 
         << setw(15) << diachincc
         << setw(15) << masothue
         << setw(15) << quocgia << endl;
}