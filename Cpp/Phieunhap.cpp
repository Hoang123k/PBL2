#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Phieunhap.h"
#include "Dsphieunhap.h"
#include "../Header/transfer.h"

using namespace std;

Phieunhap::Phieunhap() : soluonghh(0) {}

Phieunhap::~Phieunhap() {}

Phieunhap::Phieunhap(const string &maphieu, const Date &ngay, int soluong)
    : maphieu(maphieu), ngaynhap(ngay), soluonghh(soluong) {}

string Phieunhap::getmaphieu() const
{
    return this->maphieu;
}

Date Phieunhap::getngay() const
{
    return this->ngaynhap;
}

int Phieunhap::getsoluong() const
{
    return this->soluonghh;
}
vector<Chitietphieunhap> &Phieunhap::getPN()
{
    return this->PN;
}

void Phieunhap::setmaphieu(const string &maphieu)
{
    this->maphieu = maphieu;
}
void Phieunhap::setngay(const Date &ngay)
{
    this->ngaynhap = ngay;
}

void Phieunhap::setsoluong(int soluong)
{
    this->soluonghh = soluong;
}
void Phieunhap::setPN(const vector<Chitietphieunhap> &PN)
{
    this->PN = PN;
}

void docfile(Phieunhap &pn, const string &chitiet)
{
    ifstream f(chitiet);
    if (!f.is_open())
    {
        cout << "[Lỗi] Không thể mở file chi tiết: " << chitiet << endl;
        return;
    }

    pn.PN.clear();

    string line;
    while (getline(f, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;

        stringstream ss(line);
        string maphieu, mahang, mancc, sl, gia;
        long long soluong, dongia;
        getline(ss, maphieu, '|');
        getline(ss, mahang, '|');
        getline(ss, mancc, '|');
        getline(ss, sl, '|');
        getline(ss, gia, '|');
        soluong = stoll(sl);
        dongia = stoll(gia);
        if (maphieu == pn.getmaphieu())
        {
            Chitietphieunhap temp;
            temp.setmahang(toUpperString(mahang));
            temp.setmancc(mancc);
            temp.setsoluongnhap(soluong);
            temp.setdongianhap(dongia);
            pn.PN.push_back(temp);
        }
    }
    f.close();
}

void luufile(Phieunhap &pn, const string &filename)
{
    ofstream file(filename, std::ios::app);
    if (!file.is_open())
    {
        cout << "[Lỗi] Không thể mở file" << endl;
        return;
    }
    for (int i = 0; i < pn.getsoluong(); i++)
    {
        file << toUpperString(pn.getmaphieu()) << "|"
             << toUpperString(pn.PN[i].getmahang()) << "|"
             << pn.PN[i].getmancc() << "|"
             << pn.PN[i].getsoluongnhap() << "|"
             << pn.PN[i].getdongianhap() << endl;
    }
    cout << "[OK] Lưu file thành công" << endl;
    file.close();
}

// cost
long long cost_PN(Phieunhap& pn)
{
    long long cost=0;
    for(int i=0;i<pn.getsoluong();i++)
    {
        cost+= pn.getPN()[i].getdongianhap();
    }
    return cost;
}

void Phieunhap::show() const
{
    cout << left
         << setw(12) << "Ma Hang"
         << setw(12) << "Ma NCC"
         << setw(15) << "So Luong"
         << setw(15) << "Don Gia" << endl;
    cout << string(65, '-') << endl;

    for (size_t i = 0; i < this->PN.size(); i++)
    {
        this->PN[i].show();
    }
    cout << string(65, '=') << endl;
}

// them
int Phieunhap::check_mahang_ncc(const string mahang, const string mancc)
{
    for (size_t i = 0; i < this->PN.size(); i++)
    {
        if (this->PN[i].getmahang() == mahang && this->PN[i].getmancc() == mancc)
            return i;
    }
    return -1;
}

bool Phieunhap::add_1hh(Kho &kho, qlncc &ncc, Dsphieunhap *ds)
{
    string mahang, mancc, sl, gia;
    long long soluong, dongia;
    while (true)
    {
        while (true)
        {
            cout << "Nhập mã hàng: ";
            getline(cin, mahang);
            if (kho.check_ma(mahang) == false)
                break;
            else
                cout << "[Lỗi] Mã hàng không tồn tại" << endl;
        }
        // while(true){
        //     cout << "Nhập mã nhà cung cấp: ";
        //     getline(cin,mancc);
        //     if(Ncc.check_ma(mancc) == true) break;
        //     cout << "[Lỗi] Mã nhà cung cấp không tồn tại" << endl;
        // }
        cout << "Nhập mã nhà cung cấp: ";
        getline(cin, mancc);
        int index = check_mahang_ncc(mahang, mancc);
        if (index != -1)
        {
            cout << "[!]Hàng hóa của nhà cung cấp này đã có trong phiếu nhập trước đó!" << endl;
            cout << "Thêm số lượng hàng(Y/y) - Nhập lại mã hàng và nhà cung cấp(phím bất kỳ): ";
            string yes;
            getline(cin, yes);
            if (yes == "Y" || yes == "y")
            {
                while (true)
                {
                    cout << "Nhập số lượng hàng tăng(+) - giảm(-) - Thay đổi(không dấu): ";
                    string sl_nhap;
                    getline(cin, sl_nhap);
                    long long soluong_nhap;
                    try
                    {
                        soluong_nhap = stringToLL(sl_nhap);
                        if (!sl_nhap.empty())
                        {
                            if (sl_nhap[0] == '-' || sl_nhap[0] == '+')
                            {
                                if (this->PN[index].getsoluongnhap() + soluong_nhap <= 0)
                                    cout << "[Lỗi] Số lượng nhập phải lớn hơn 0. Xin hãy nhập lại.\n";
                                else
                                {
                                    this->PN[index].setsoluongnhap(this->PN[index].getsoluongnhap() + soluong_nhap);
                                }
                            }
                            else
                            {
                                if (soluong_nhap <= 0)
                                {
                                    cout << "[Lỗi] Số lượng phải lớn hơn 0. Xin hãy nhập lại.\n";
                                    continue;
                                }
                                this->PN[index].setsoluongnhap(soluong_nhap);
                            }
                        }
                        cout << "[OK] Cập nhật số lượng thành công" << endl;
                        return false;
                    }
                    catch (const exception &e)
                    {
                        cout << "[Lỗi] Vui lòng chỉ nhập số nguyên hợp lệ.\n";
                    }
                }
            }
            else
            {
                continue;
            }
        }
        while (true)
        {
            cout << "Nhập số lượng: ";
            getline(cin, sl);

            try
            {
                soluong = stringToLL(sl);
                if (soluong <= 0)
                {
                    cout << "Lỗi: Số lượng phải lớn hơn 0. Xin hãy nhập lại.\n";
                    continue;
                }
                break;
            }
            catch (const exception &e)
            {
                cout << "Lỗi định dạng! Vui lòng chỉ nhập số nguyên hợp lệ.\n";
            }
        }
        dongia = kho.getkho()[kho.searchByMaHang(mahang)]->getdongia();
        this->PN.push_back(Chitietphieunhap(mahang, mancc, soluong, dongia));
        cout << "[OK] Thêm hàng hóa mới vào phiếu nhập " << this->getmaphieu() << " thành công." << endl;
        long long index_1 = ds->get_index_maphieu(this->getmaphieu());
        if (index_1 != -1)
        {
            int current_sl = ds->getdsPN()[index_1].getsoluong();
            ds->getdsPN()[index_1].setsoluong(current_sl + 1);
        }
        break;
    }
    return true;
}

void Phieunhap::add_nhh(const int &n, Kho &kho, qlncc &ncc, Dsphieunhap *ds)
{
    for (int i = 0; i < n; i++)
    {
        if (this->add_1hh(kho, ncc, ds) == false)
            i--;
    }
    cout << "[OK] Thêm " << n << " hàng hóa vào phiếu nhập " << this->getmaphieu() << " thành công" << endl;
}

void Phieunhap::sortByMaHang(vector<Chitietphieunhap> &PN, int low, int high)
{
    if (low < high)
    {
        string pivot = PN[high].getmahang();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (PN[j].getmahang() < pivot)
            {
                i++;
                swap(PN[i], PN[j]);
            }
        }
        swap(PN[i + 1], PN[high]);
        int pi = i + 1;
        sortByMaHang(PN, low, pi - 1);
        sortByMaHang(PN, pi + 1, high);
    }
}