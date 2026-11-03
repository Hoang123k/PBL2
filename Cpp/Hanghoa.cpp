#include "Hanghoa.h"
#include <iomanip>
#include <string> // Sửa lại thành thư viện chuẩn C++ cho string
using namespace std;

Hanghoa::Hanghoa() : soluong(0), dongia(0) {}

Hanghoa::~Hanghoa() {}

Hanghoa::Hanghoa(const std::string& mahang, const std::string& tenhang, 
                 const std::string& loaihang, const std::string& donvitinh,
                 long long soluong, long long dongia) 
    : mahang(mahang), tenhang(tenhang), loaihang(loaihang),
      donvitinh(donvitinh), soluong(soluong), dongia(dongia) {}

// GETTER (Thêm const ở cuối)
std::string Hanghoa::getmahang() const {
    return this->mahang;
}
std::string Hanghoa::gettenhang() const {
    return this->tenhang;
}
std::string Hanghoa::getloaihang() const {
    return this->loaihang;
}
std::string Hanghoa::getdonvitinh() const {
    return this->donvitinh;
}
long long Hanghoa::getsoluong() const {
    return this->soluong;
}
long long Hanghoa::getdongia() const {
    return this->dongia;
}

// SETTER (Dùng const std::string&)
void Hanghoa::setmahang(const std::string& mahang) {
    this->mahang = mahang;
}
void Hanghoa::settenhang(const std::string& tenhang) {
    this->tenhang = tenhang;
}
void Hanghoa::setloaihang(const std::string& loaihang) {
    this->loaihang = loaihang;
}
void Hanghoa::setdonvitinh(const std::string& donvitinh) {
    this->donvitinh = donvitinh;
}
void Hanghoa::setsoluong(long long soluong) {
    this->soluong = soluong;
}
void Hanghoa::setdongia(long long dongia) {
    this->dongia = dongia;
}
