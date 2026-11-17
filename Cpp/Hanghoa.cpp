#include "Hanghoa.h"
#include <iomanip>
#include <string>
#include "../Header/transfer.h"
using namespace std;

Hanghoa::Hanghoa() : soluong(0), dongia(0) {}

Hanghoa::~Hanghoa() {}

Hanghoa::Hanghoa(const string &mahang, const string &tenhang,
                 const string &loaihang, const string &donvitinh,
                 long long soluong, long long dongia)
    : mahang(mahang), tenhang(tenhang), loaihang(loaihang),
      donvitinh(donvitinh), soluong(soluong), dongia(dongia) {}

// GETTER
string Hanghoa::getmahang() const
{
    return this->mahang;
}
string Hanghoa::gettenhang() const
{
    return this->tenhang;
}
string Hanghoa::getloaihang() const
{
    return this->loaihang;
}
string Hanghoa::getdonvitinh() const
{
    return this->donvitinh;
}
long long Hanghoa::getsoluong() const
{
    return this->soluong;
}
long long Hanghoa::getdongia() const
{
    return this->dongia;
}

// SETTER
void Hanghoa::setmahang(const string &mahang)
{
    this->mahang = mahang;
}
void Hanghoa::settenhang(const string &tenhang)
{
    this->tenhang = tenhang;
}
void Hanghoa::setloaihang(const string &loaihang)
{
    this->loaihang = loaihang;
}
void Hanghoa::setdonvitinh(const string &donvitinh)
{
    this->donvitinh = donvitinh;
}
void Hanghoa::setsoluong(long long soluong)
{
    this->soluong = soluong;
}
void Hanghoa::setdongia(long long dongia)
{
    this->dongia = dongia;
}

void Hanghoa::nhap_thong_tin()
{
    while (true)
    {
        cout << "Nhập tên hàng: ";
        getline(cin, this->tenhang);
        if (!this->tenhang.empty())
            break;
        cout << "[Lỗi] Tên hàng rỗng" << endl;
    }

    while (true)
    {

        cout << "Nhập đơn vị tính: ";
        getline(cin, this->donvitinh);
        if (!this->donvitinh.empty())
            break;
        cout << "[Lỗi] Đơn vị tính rỗng" << endl;
    }
    string gia_str;
    while (true)
    {
        cout << "Nhập đơn giá bán: ";
        getline(cin, gia_str);
        try
        {
            long long gia = stringToLL(gia_str);
            if (gia <= 0)
            {
                cout << "[Lỗi] Đơn giá phải lớn hơn 0.\n";
                continue;
            }
            this->dongia = gia;
            break;
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }
}

void Hanghoa::nhap()
{
    while(true){
        
    cout << "Nhập mã hàng: ";
    getline(cin, this->mahang);
    if(!this->mahang.empty()) break;
    cout << "[Lỗi] Mã hàng rỗng" << endl;
    }
    this->mahang = toUpperString(this->mahang);
    this->nhap_thong_tin();

    string sl_str;
    while (true)
    {
        cout << "Nhập số lượng tồn: ";
        getline(cin, sl_str);
        try
        {
            long long sl = stringToLL(sl_str);
            if (sl < 0)
            {
                cout << "[Lỗi] Số lượng không được âm.\n";
                continue;
            }
            this->soluong = sl;
            break;
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }
}