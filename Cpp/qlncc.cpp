#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "qlncc.h"
#include "NccTrongNuoc.h"
#include "NccQuocTe.h"
#include "../Header/transfer.h"
#include "../Header/menu.h"

using namespace std;

qlncc::qlncc() : soluong_ncc(0) {}
qlncc::~qlncc() {}
string toLowerCase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}
void docfile(qlncc &ql, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Khong the mo file ncc: " << filename << endl;
        return;
    }

    ql.ql_ncc.clear();
    string line;
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;

        stringstream ss(line);
        string loai, ma, ten, sdt, dc, mathue, extra;

        getline(ss, loai, '|');
        getline(ss, ma, '|');
        getline(ss, ten, '|');
        getline(ss, sdt, '|');
        getline(ss, dc, '|');
        getline(ss, mathue, '|');
        getline(ss, extra, '|');
        ma = toUpperString(ma);
        if (loai == "TN")
        {
            ql.ql_ncc.push_back(make_unique<NccTrongNuoc>(ma, ten, sdt, dc, mathue));
        }
        else if (loai == "QT")
        {
            ql.ql_ncc.push_back(make_unique<NccQuocTe>(ma, ten, sdt, dc, mathue, extra));
        }
    }
    ql.soluong_ncc = ql.ql_ncc.size();
    cout << "Doc file NCC thanh cong!" << endl;
}

void qlncc::show() const
{
    cout << "So luong nha cung cap: " << this->soluong_ncc << endl;
    cout << string(110, '-') << endl;
    cout << left
         << setw(6) << "Loại"
         << setw(10) << "Mã NCC"
         << setw(32) << "Tên NCC"
         << setw(15) << "SDT"
         << setw(25) << "Địa chỉ"
         << setw(15) << "Thông tin thêm" << endl;
    cout << string(110, '-') << endl;
    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        ql_ncc[i]->show();
    }
    cout << string(110, '=') << endl;
}
void qlncc::add(const string &mancc)
{
    int loai = 0;
    while (true)
    {
        if (readInt("Chọn loại nhà cung cấp mới (1. Trong nước / 2. Quốc tế): ", loai) && (loai == 1 || loai == 2))
        {
            break;
        }
        cout << "[Lỗi] Vui lòng chỉ chọn 1 hoặc 2.\n";
    }

    unique_ptr<Ncc> ncc_moi;
    if (loai == 1)
    {
        ncc_moi = make_unique<NccTrongNuoc>();
    }
    else
    {
        ncc_moi = make_unique<NccQuocTe>();
    }

    ncc_moi->setmancc(mancc);
    ncc_moi->nhap_thong_tin();

    this->ql_ncc.push_back(move(ncc_moi));
    this->soluong_ncc = static_cast<int>(this->ql_ncc.size());
    this->save_Ncc = 0;
    cout << "[OK] Đã tạo nhà cung cấp \"" << mancc << "\" vào hệ thống.\n";
}
void qlncc::update()
{
    string ma;
    cout << "Nhap ma NCC can cap nhat : ";
    getline(cin, ma);
    ma = toUpperString(ma);
    int index = -1;
    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        if (ql_ncc[i]->getmancc() == ma)
        {
            index = static_cast<int>(i);
            break;
        }
    }
    if (index >= 0)
    {
        string ten, sdt, dc;
        cout << "Nhap ten NCC moi: ";
        getline(cin, ten);
        cout << "Nhap SDT moi: ";
        getline(cin, sdt);
        cout << "Nhap dia chi moi: ";
        getline(cin, dc);

        if (!ten.empty())
            ql_ncc[index]->settenncc(ten);
        if (!sdt.empty())
            ql_ncc[index]->setsdtncc(sdt);
        if (!dc.empty())
            ql_ncc[index]->setdiachincc(dc);
        this->save_Ncc = 0;
        cout << "[OK] Cap nhat thanh cong!\n";
    }
    else
    {
        cout << "Khong tim thay nha cung cap co ma: " << ma << endl;
    }
}

void qlncc::sortByMaNCC(vector<unique_ptr<Ncc>> &list_ncc, int low, int high)
{
    if (low < high)
    {
        string pivot = list_ncc[high]->getmancc();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (list_ncc[j]->getmancc() < pivot)
            {
                i++;
                swap(list_ncc[i], list_ncc[j]);
            }
        }
        swap(list_ncc[i + 1], list_ncc[high]);
        int pi = i + 1;
        sortByMaNCC(list_ncc, low, pi - 1);
        sortByMaNCC(list_ncc, pi + 1, high);
        this->save_Ncc = 0;
    }
}

void qlncc::sortByTenNCC(vector<unique_ptr<Ncc>> &list_ncc, int low, int high)
{
    if (low < high)
    {
        string pivot = list_ncc[high]->gettenncc();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (list_ncc[j]->gettenncc() < pivot)
            {
                i++;
                swap(list_ncc[i], list_ncc[j]);
            }
        }
        swap(list_ncc[i + 1], list_ncc[high]);
        int pi = i + 1;
        sortByTenNCC(list_ncc, low, pi - 1);
        sortByTenNCC(list_ncc, pi + 1, high);
        this->save_Ncc = 0;
    }
}
void qlncc::sortByLoaiNCC(vector<unique_ptr<Ncc>> &list_ncc, int low, int high)
{
    if (low < high)
    {
        string pivot = list_ncc[high]->getloai();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (list_ncc[j]->getloai() < pivot)
            {
                i++;
                swap(list_ncc[i], list_ncc[j]);
            }
        }
        swap(list_ncc[i + 1], list_ncc[high]);
        int pi = i + 1;
        sortByLoaiNCC(list_ncc, low, pi - 1);
        sortByLoaiNCC(list_ncc, pi + 1, high);
        this->save_Ncc = 0;
    }
}
int qlncc::searchByMaNCC(const string &ma) const
{
    string searchMa = toLowerCase(ma);

    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        string currentMa = toLowerCase(ql_ncc[i]->getmancc());
        if (currentMa.find(searchMa) != string::npos)
        {
            cout << string(95, '-') << endl;
            cout << left << setw(8) << "Loai" << setw(12) << "Ma NCC"
                 << setw(28) << "Ten NCC" << setw(15) << "SDT" << setw(15) << "Dia Chi"
                 << setw(15) << "Thong tin them" << endl;
            cout << string(95, '-') << endl;
            ql_ncc[i]->show();
            return i;
        }
    }
    cout << "Khong tim thay nha cung cap co ma chua tu khoa: " << ma << endl;
    return -1;
}

void qlncc::searchByLoaiNCC(const string &loai) const
{
    bool found = false;
    string searchloai = toLowerCase(loai);

    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        string currentloai = toLowerCase(ql_ncc[i]->getloai());
        if (currentloai.find(searchloai) != string::npos)
        {
            if (!found)
            {
                cout << string(95, '-') << endl;
                cout << left << setw(8) << "Loai" << setw(12) << "Ma NCC"
                     << setw(28) << "loai NCC" << setw(15) << "SDT" << setw(15) << "Dia Chi"
                     << setw(15) << "Thong tin them" << endl;
                cout << string(95, '-') << endl;
            }
            ql_ncc[i]->show();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay nha cung cap co loai chua tu khoa: " << loai << endl;
    }
    else
    {
        cout << string(95, '=') << endl;
    }
}
void qlncc::searchByTenNCC(const string &ten) const
{
    bool found = false;
    string searchTen = toLowerCase(ten);

    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        string currentTen = toLowerCase(ql_ncc[i]->gettenncc());
        if (currentTen.find(searchTen) != string::npos)
        {
            if (!found)
            {
                cout << string(95, '-') << endl;
                cout << left << setw(8) << "Loai" << setw(12) << "Ma NCC"
                     << setw(28) << "Ten NCC" << setw(15) << "SDT" << setw(15) << "Dia Chi"
                     << setw(15) << "Thong tin them" << endl;
                cout << string(95, '-') << endl;
            }
            ql_ncc[i]->show();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay nha cung cap co ten chua tu khoa: " << ten << endl;
    }
    else
    {
        cout << string(95, '=') << endl;
    }
}

void qlncc::deleteByMaNCC(const string &ma)
{
    for (auto it = ql_ncc.begin(); it != ql_ncc.end(); ++it)
    {
        if ((*it)->getmancc() == toUpperString(ma))
        {
            ql_ncc.erase(it);
            soluong_ncc = ql_ncc.size();
            this->save_Ncc = 0;
            cout << "Xoa nha cung cap thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nha cung cap co ma: " << ma << endl;
}
void luufile(qlncc &ql, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Khong the mo file de ghi: " << filename << endl;
        return;
    }
    for (const auto &ncc : ql.ql_ncc)
    {
        NccTrongNuoc *tn = dynamic_cast<NccTrongNuoc *>(ncc.get());
        if (tn != nullptr)
        {
            file << "TN|" << tn->getmancc() << "|" << tn->gettenncc() << "|"
                 << tn->getsdtncc() << "|" << tn->getdiachincc() << "|"
                 << tn->getmasothue() << tn->gettinhthanh() << "\n";
        }
        else
        {
            NccQuocTe *qt = dynamic_cast<NccQuocTe *>(ncc.get());
            if (qt != nullptr)
            {
                file << "QT|" << qt->getmancc() << "|" << qt->gettenncc() << "|"
                     << qt->getsdtncc() << "|" << qt->getdiachincc() << "|"
                     << qt->getmasothue() << "|" << qt->getquocgia() << "\n";
            }
        }
    }
    ql.save_Ncc = 1;
    cout << "Luu file thanh cong!\n";
}

int qlncc::get_index_mancc(const string &ma) const
{
    for (int i = 0; i < this->soluong_ncc; i++)
    {
        if (this->ql_ncc[i]->getmancc() == toUpperString(ma))
            return i;
    }
    return -1;
}
// Getter
int &qlncc::getsoluongncc()
{
    return this->soluong_ncc;
}
vector<unique_ptr<Ncc>> &qlncc::getql_ncc()
{
    return this->ql_ncc;
}

// Setter
void qlncc::setsoluongncc(const int &sl)
{
    this->soluong_ncc = sl;
}
