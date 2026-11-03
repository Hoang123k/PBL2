#include "NccTrongNuoc.h"
#include <iomanip>
#include <iostream>

using namespace std;

NccTrongNuoc::NccTrongNuoc() : Ncc() { loaincc = "TN"; }

NccTrongNuoc::NccTrongNuoc(const string& ma, const string& ten, const string& sdt, const string& dc, const string& mst)
    : Ncc(ma, ten, sdt, dc) {
    loaincc = "TN";
    masothue = mst;
}

void NccTrongNuoc::show() const { // Thêm const
    cout << left
         << setw(8)  << loaincc
         << setw(12) << mancc 
         << setw(28) << tenncc
         << setw(15) << sdtncc 
         << setw(15) << diachincc
         << setw(15) << masothue << endl;
}