#include "Ncc.h"
#include "../Header/transfer.h"

using namespace std;

Ncc::Ncc() : loaincc(""), mancc(""), tenncc(""), sdtncc(""), diachincc(""), masothue("") {}

Ncc::~Ncc() {}

Ncc::Ncc(const string &ma, const string &ten, const string &sdt, const string &dc)
    : loaincc(""), mancc(ma), tenncc(ten), sdtncc(sdt), diachincc(dc), masothue("") {}

// GETTER
string Ncc::getloai() const { return loaincc; }
string Ncc::getmancc() const { return mancc; }
string Ncc::gettenncc() const { return tenncc; }
string Ncc::getsdtncc() const { return sdtncc; }
string Ncc::getdiachincc() const { return diachincc; }
string Ncc::getmasothue() const { return masothue; }

// SETTER
void Ncc::setloaincc(const string &loai) { loaincc = loai; }
void Ncc::setmancc(const string &ma) { mancc = ma; }
void Ncc::settenncc(const string &ten) { tenncc = ten; }
void Ncc::setsdtncc(const string &sdt) { sdtncc = sdt; }
void Ncc::setdiachincc(const string &dc) { diachincc = dc; }
void Ncc::setmasothue(const string &mst) { masothue = mst; }

void Ncc::nhap_thong_tin()
{
    cout << "Nhập tên nhà cung cấp: ";
    getline(cin, this->tenncc);

    cout << "Nhập địa chỉ: ";
    getline(cin, this->diachincc);

    cout << "Nhập số điện thoại: ";
    getline(cin, this->sdtncc);
}

void Ncc::nhap()
{
    cout << "Nhập mã nhà cung cấp: ";
    getline(cin, this->mancc);
    this->mancc = toUpperString(this->mancc);
    this->nhap_thong_tin();
}