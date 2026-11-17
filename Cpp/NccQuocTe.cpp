#include "NccQuocTe.h"
#include <iomanip>
#include <iostream>

using namespace std;

NccQuocTe::NccQuocTe() : Ncc(), quocgia("") { loaincc = "QT"; }

NccQuocTe::NccQuocTe(const string &ma, const string &ten, const string &sdt, const string &dc, const string &mst, const string &qg)
    : Ncc(ma, ten, sdt, dc), quocgia(qg)
{
    loaincc = "QT";
    masothue = mst;
}

void NccQuocTe::show() const
{
    cout << left
         << setw(6) << "QT"
         << setw(10) << this->mancc
         << setw(32) << this->tenncc
         << setw(15) << this->sdtncc
         << setw(25) << this->diachincc
         << setw(15) << this->quocgia << endl;
}
string NccQuocTe::getmasothue() const
{
    return masothue;
}

string NccQuocTe::getquocgia() const
{
    return quocgia;
}

void NccQuocTe::nhap_thong_tin()
{
    Ncc::nhap_thong_tin();
    std::cout << "Nhập quốc gia: ";
    std::getline(std::cin, this->quocgia);
}