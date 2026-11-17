#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Dsphieunhap.h"
#include "transfer.h"

using namespace std;

Dsphieunhap::Dsphieunhap() : soluongphieu(0) {}

Dsphieunhap::~Dsphieunhap() {}

// getter
int &Dsphieunhap::getsoluongphieu()
{
    return this->soluongphieu;
}
vector<Phieunhap> &Dsphieunhap::getdsPN()
{
    return this->dsPN;
}

// setter
void Dsphieunhap::setsoluongphieu(const int &sl)
{
    this->soluongphieu = sl;
}
void Dsphieunhap::setdsPN(const vector<Phieunhap> &ds)
{
    this->dsPN = ds;
}

void docfile(Dsphieunhap &ds, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Khong the mo file danh sach phieu nhap: " << filename << endl;
        return;
    }

    ds.dsPN.clear();
    string line;

    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;

        stringstream ss(line);
        string maphieu, ngay, soluong;

        getline(ss, maphieu, '|');
        getline(ss, ngay, '|');
        getline(ss, soluong, '|');

        if (maphieu.empty())
            continue;
        stringstream ss1(ngay);
        string d, m, y;
        getline(ss1, d, '/');
        getline(ss1, m, '/');
        getline(ss1, y);

        Phieunhap temp;
        temp.setmaphieu(toUpperString(maphieu));
        temp.setngay(Date(stoi(d), stoi(m), stoi(y)));
        temp.setsoluong(soluong.empty() ? 0 : stoll(soluong));
        docfile(temp, "Data\\phieunhap.txt");

        ds.dsPN.push_back(temp);
    }

    ds.soluongphieu = ds.dsPN.size();
    cout << "Doc file danh sach phieu nhap thanh cong! Tong so phieu: " << ds.soluongphieu << endl;
}
void luuphieunhap(Dsphieunhap &ds, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "[Lỗi] Không thể mở file chi tiết phiếu nhập để lưu!" << endl;
        return;
    }
    for (int i = 0; i < ds.getsoluongphieu(); i++)
    {
        Phieunhap &pn = ds.getdsPN()[i];
        string maphieu = pn.getmaphieu();
        vector<Chitietphieunhap> &chitietList = pn.getPN();
        for (size_t j = 0; j < chitietList.size(); j++)
        {
            file << maphieu << "|"
                 << chitietList[j].getmahang() << "|"
                 << chitietList[j].getmancc() << "|"
                 << chitietList[j].getsoluongnhap() << "|"
                 << chitietList[j].getdongianhap() << endl;
        }
    }

    file.close();
    cout << "[OK] Lưu toàn bộ chi tiết phiếu nhập thành công!" << endl;
}

void luufile(Dsphieunhap &ds, const string &filename)
{
    ofstream file(filename, std::ios::app);
    for (int i = 0; i < ds.getsoluongphieu(); i++)
    {
        file << toUpperString(ds.getdsPN()[i].getmaphieu()) << "|"
             << ds.getdsPN()[i].getngay() << "|"
             << ds.getdsPN()[i].getsoluong() << endl;
    }
    file.close();
}

void Dsphieunhap::show() const
{
    cout << string(50, '=') << endl;
    cout << "DANH SACH PHIEU NHAP (Tong so phieu: " << dsPN.size() << ")" << endl;
    cout << string(50, '-') << endl;
    cout << left
         << setw(12) << "Ma phieu"
         << setw(15) << "Ngay nhap"
         << setw(12) << "So luong" << endl;
    cout << string(50, '-') << endl;

    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        cout << left
             << setw(12) << this->dsPN[i].getmaphieu()
             << setw(15) << this->dsPN[i].getngay()
             << setw(12) << this->dsPN[i].getsoluong() << endl;
    }
    cout << string(50, '=') << endl;
}

// thêm

bool Dsphieunhap::check_date(const Date &date)
{
    return 1;
}
int Dsphieunhap::get_index_maphieu(string ma)
{
    ma = toUpperString(ma);
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        if (this->dsPN[i].getmaphieu() == ma)
            return i;
    }
    return -1;
}

void Dsphieunhap::add(Kho &kho, qlncc &ncc)
{
    cout << "\n================ THÊM PHIẾU NHẬP MỚI ================" << endl;
    string maphieu, sl;
    Date date;
    long long soluong;
    string key;
    cin.clear();
    while (true)
    {
        cout << "Nhập mã phiếu mới: ";
        getline(cin, maphieu);
        if (maphieu.empty())
        {
            cout << "[Lỗi] Mã phiếu trống." << endl;
            continue;
        }
        if (get_index_maphieu(maphieu) == -1)
            break;
        cout << "[Lỗi] Mã phiếu đã tồn tại." << endl;
    }
    cin >> date;
    while (true)
    {
        cout << "Nhập số lượng hàng hóa của phiếu: ";
        getline(cin, sl);
        try
        {
            if (sl.empty())
            {
                throw invalid_argument("[Lỗi] Vui lòng chỉ nhập số nguyên hợp lệ.");
            }
            soluong = stringToLL(sl);
            if (soluong <= 0)
            {
                cout << "[Lỗi] Số lượng phải lớn hơn 0. Xin hãy nhập lại.\n";
                continue;
            }
            break;
        }
        catch (const exception &e)
        {
            cout << "[Lỗi] Vui lòng chỉ nhập số nguyên hợp lệ.\n";
        }
    }
    Phieunhap temp(maphieu, date, soluong);
    for (int i = 0; i < soluong; i++)
    {
        cout << "Nhập thông tin hàng hóa thứ " << i + 1 << endl;
        temp.add_1hh(kho, ncc, this);
    }
    this->dsPN.push_back(temp);
    soluongphieu++;
    cout << "[OK] Thêm phiếu nhập " << temp.getmaphieu() << " thành công." << endl;
}
// update
void Dsphieunhap::update()
{
    string ma;
    cout << "Nhap ma phieu can cap nhat: ";
    getline(cin, ma);

    int index = -1;
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        if (this->dsPN[i].getmaphieu() == ma)
        {
            index = i;
            break;
        }
    }

    if (index >= 0)
    {
        int d, m, y;
        cout << "Nhap ngay moi: ";
        cin >> d;
        cout << "Nhap thang moi: ";
        cin >> m;
        cout << "Nhap nam moi: ";
        cin >> y;
        cin.ignore();

        Date newDate(d, m, y);
        this->dsPN[index].setngay(newDate);

        cout << "[OK] Cap nhat thong tin phieu nhap thanh cong!\n";
    }
    else
    {
        cout << "[Lỗi] Khong tim thay phieu nhap ma '" << ma << "'!\n";
    }
}
// sort
void Dsphieunhap::sortByMaPhieu(vector<Phieunhap> &ds, int low, int high)
{
    if (low < high)
    {
        string pivot = ds[high].getmaphieu();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (ds[j].getmaphieu() < pivot)
            {
                i++;
                swap(ds[i], ds[j]);
            }
        }
        swap(ds[i + 1], ds[high]);
        int pi = i + 1;
        sortByMaPhieu(ds, low, pi - 1);
        sortByMaPhieu(ds, pi + 1, high);
    }
}
static string toLowerCase_DS(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}
void Dsphieunhap::sortBySoLuong(vector<Phieunhap> &ds, int low, int high)
{
    if (low < high)
    {
        int pivot = ds[high].getsoluong();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (ds[j].getsoluong() < pivot)
            {
                i++;
                swap(ds[i], ds[j]);
            }
        }
        swap(ds[i + 1], ds[high]);
        int pi = i + 1;
        sortBySoLuong(ds, low, pi - 1);
        sortBySoLuong(ds, pi + 1, high);
    }
}
void Dsphieunhap::searchByMaPhieu(const string &ma) const
{
    bool found = false;
    string searchMa = toLowerCase_DS(ma);
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        string currentMa = toLowerCase_DS(this->dsPN[i].getmaphieu());
        if (currentMa.find(searchMa) != string::npos)
        {
            if (!found)
            {
                cout << left << setw(15) << "Ma Phieu" << setw(15) << "Ngay Nhap" << setw(15) << "So Luong" << endl;
                cout << string(45, '-') << endl;
            }
            this->dsPN[i].show();
            found = true;
        }
    }
    if (!found)
        cout << "[Lỗi] Không tìm thấy phiếu nhập chứa mã: " << ma << endl;
}
void Dsphieunhap::deleteByMaPhieu(const string &ma)
{
    bool found = false;
    for (auto it = this->dsPN.begin(); it != this->dsPN.end();)
    {
        if (it->getmaphieu() == ma)
        {
            it = this->dsPN.erase(it);
            found = true;
            cout << "[OK] Đã xóa phiếu nhập mã '" << ma << "' thành công!\n";
            break;
        }
        else
        {
            ++it;
        }
    }
    if (!found)
        cout << "[Lỗi] Không tìm thấy phiếu nhập mã '" << ma << "'!\n";
}