#include "Hanghoa.h"
#include <iomanip>
#include <string> 
#include "../Header/transfer.h"
using namespace std;

Hanghoa::Hanghoa() : soluong(0), dongia(0) {}

Hanghoa::~Hanghoa() {}

Hanghoa::Hanghoa(const std::string& mahang, const std::string& tenhang, 
                 const std::string& loaihang, const std::string& donvitinh,
                 long long soluong, long long dongia) 
    : mahang(mahang), tenhang(tenhang), loaihang(loaihang),
      donvitinh(donvitinh), soluong(soluong), dongia(dongia) {}

// GETTER
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

// SETTER
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

void Hanghoa::nhap_thong_tin()
{
    std::cout << "Nhập tên hàng: ";
    std::getline(std::cin, this->tenhang);

    std::cout << "Nhập đơn vị tính: ";
    std::getline(std::cin, this->donvitinh);

    std::string gia_str;
    while (true)
    {
        std::cout << "Nhập đơn giá bán: ";
        std::getline(std::cin, gia_str);
        try
        {
            long long gia = stringToLL(gia_str);
            if (gia <= 0)
            {
                std::cout << "[Lỗi] Đơn giá phải lớn hơn 0.\n";
                continue;
            }
            this->dongia = gia;
            break;
        }
        catch (const std::exception &)
        {
            std::cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }
}

void Hanghoa::nhap()
{
    std::cout << "Nhập mã hàng: ";
    std::getline(std::cin, this->mahang);
    this->mahang = toUpperString(this->mahang);
    this->nhap_thong_tin();

    std::string sl_str;
    while (true)
    {
        std::cout << "Nhập số lượng tồn: ";
        std::getline(std::cin, sl_str);
        try
        {
            long long sl = stringToLL(sl_str);
            if (sl < 0)
            {
                std::cout << "[Lỗi] Số lượng không được âm.\n";
                continue;
            }
            this->soluong = sl;
            break;
        }
        catch (const std::exception &)
        {
            std::cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }
}