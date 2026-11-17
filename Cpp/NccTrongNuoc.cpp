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
         << setw(15) << this->masothue
         << setw(20) << this->tinhthanh << endl;
}
string NccTrongNuoc::getmasothue() const
{
    return masothue;
}
string NccTrongNuoc::gettinhthanh() const
{
    return this->tinhthanh;
}
void NccTrongNuoc::nhap_thong_tin()
{
    Ncc::nhap_thong_tin();
    while (true)
    {
        cout << "Nhập tỉnh/thành phố: ";
        getline(cin, this->tinhthanh);
        if (!this->tinhthanh.empty())
            break;
        cout << "[Lỗi] Tỉnh thành rỗng" << endl;
    }
}