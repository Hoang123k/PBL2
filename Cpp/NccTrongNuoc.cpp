#include "NccTrongNuoc.h"
#include <iomanip>
#include <iostream>

using namespace std;

NccTrongNuoc::NccTrongNuoc() : Ncc() { loaincc = "TN"; }

NccTrongNuoc::NccTrongNuoc(const string &ma, const string &ten, const string &sdt, const string &dc, const string &mst)
    : Ncc(ma, ten, sdt, dc)
{
    loaincc = "TN";
    masothue = mst;
}

void NccTrongNuoc::show() const
{
    
    cout << left
         << setw(6) << "TN"
         << setw(10) << this->mancc
         << setw(32) << this->tenncc
         << setw(15) << this->sdtncc
         << setw(25) << this->diachincc
         << setw(15) << this->masothue << endl;
}
string NccTrongNuoc::getmasothue() const
{
    return masothue;
}