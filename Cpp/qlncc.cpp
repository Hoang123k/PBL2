#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "qlncc.h"
#include "NccTrongNuoc.h"
#include "NccQuocTe.h"
#include "../Header/transfer.h"

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
         << setw(6) << "Loai"
         << setw(10) << "Ma NCC"
         << setw(32) << "Ten NCC"
         << setw(15) << "SDT"
         << setw(25) << "Dia Chi"
         << setw(15) << "Thong tin them" << endl;
    cout << string(110, '-') << endl;
    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        ql_ncc[i]->show();
    }
    cout << string(110, '=') << endl;
}

void qlncc::add()
{
    string loai, ma, ten, sdt, dc, extra;
    cout << "Nhap loai NCC (TN - Trong nuoc / QT - Quoc te): ";
    getline(cin, loai);
    for (char &c : loai)
    {
        c = toupper(c);
    }
    if (loai != "TN" && loai != "QT")
    {
        cout << "Loai NCC khong hop le!\n";
        return;
    }

    cout << "Nhap ma NCC: ";
    getline(cin, ma);
    for (const auto &ncc : ql_ncc)
    {
        if (ncc->getmancc() == ma)
        {
            cout << "Loi: Ma NCC '" << ma << "' da ton tai! Vui long them lai voi ma khac.\n";
            return;
        }
    }
    cout << "Nhap ten NCC: ";
    getline(cin, ten);
    cout << "Nhap SDT: ";
    getline(cin, sdt);
    cout << "Nhap dia chi: ";
    getline(cin, dc);

    if (loai == "TN")
    {
        cout << "Nhap ma so thue: ";
        getline(cin, extra);
        ql_ncc.push_back(make_unique<NccTrongNuoc>(ma, ten, sdt, dc, extra));
        soluong_ncc++;
        cout << "Them NCC trong nuoc thanh cong!\n";
    }
    else if (loai == "QT")
    {
        string mst;
        cout << "Nhap ma so thue: ";
        getline(cin, mst);
        cout << "Nhap quoc gia: ";
        getline(cin, extra);
        ql_ncc.push_back(make_unique<NccQuocTe>(ma, ten, sdt, dc, mst, extra));
        soluong_ncc++;
        cout << "Them NCC Quoc te thanh cong!\n";
    }
}

void qlncc::update()
{
    string ma;
    cout << "Nhap ma NCC can cap nhat (nhap chinh xac): ";
    getline(cin, ma);
    int index = -1;
    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        if (ql_ncc[i]->getmancc() == ma)
        {
            index = i;
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

        ql_ncc[index]->settenncc(ten);
        ql_ncc[index]->setsdtncc(sdt);
        ql_ncc[index]->setdiachincc(dc);
        cout << "Cap nhat thanh cong!\n";
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
    }
}

void qlncc::searchByMaNCC(const string &ma) const
{
    bool found = false;
    string searchMa = toLowerCase(ma);

    for (size_t i = 0; i < ql_ncc.size(); i++)
    {
        string currentMa = toLowerCase(ql_ncc[i]->getmancc());
        if (currentMa.find(searchMa) != string::npos)
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
        cout << "Khong tim thay nha cung cap co ma chua tu khoa: " << ma << endl;
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
        if ((*it)->getmancc() == ma)
        {
            ql_ncc.erase(it);
            soluong_ncc = ql_ncc.size();
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
                 << tn->getmasothue() << "\n";
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
    cout << "Luu file thanh cong!\n";
}