#include "Kho.h"
#include "ThucPham.h"
#include "VatTu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../Header/menu.h"
#include "../Header/transfer.h"

using namespace std;
Kho::Kho() : soluonghang(0) {}
Kho::~Kho() {}

void Kho::show() const
{
    cout << "Số lượng hàng hóa hiện tại trong kho: " << this->soluonghang << endl;
    cout << left
         << setw(10) << "Mã hàng"
         << setw(22) << "Tên hàng"
         << setw(20) << "Loại hàng"
         << setw(15) << "Đơn vị tính"
         << setw(12) << "Số lượng"
         << setw(10) << "Đơn giá"
         << setw(15) << "Thuộc tính" << endl;
    cout << string(99, '-') << endl;
    for (size_t i = 0; i < this->kho.size(); i++)
    {
        this->kho[i]->show();
    }
}

void docfile(Kho &k, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "[Lỗi] Không thể mở file: " << filename << endl;
        return;
    }

    k.kho.clear();
    string line;
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;

        stringstream ss(line);
        string mahang, tenhang, loaihang, donvitinh, sl_str, gia_str, thuoctinh;

        getline(ss, mahang, '|');
        getline(ss, tenhang, '|');
        getline(ss, loaihang, '|');
        getline(ss, donvitinh, '|');
        getline(ss, sl_str, '|');
        getline(ss, gia_str, '|');
        getline(ss, thuoctinh, '|');

        int soluong = sl_str.empty() ? 0 : stoll(sl_str);
        int dongia = gia_str.empty() ? 0 : stoll(gia_str);

        if (loaihang == "TP" || loaihang == "tp")
        {
            k.kho.push_back(make_unique<ThucPham>(toUpperString(mahang), tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
        else if (loaihang == "VT" || loaihang == "vt")
        {
            k.kho.push_back(make_unique<VatTu>(toUpperString(mahang), tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
    }
    k.soluonghang = k.kho.size();
    cout << "Đọc file hàng hóa thành công!" << endl;
}
void luufile(Kho &k, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "[Lỗi]Không thể mở file: " << filename << endl;
        return;
    }
    for (size_t i = 0; i < k.kho.size(); i++)
    {
        file << toUpperString(k.kho[i]->getmahang()) << "|"
             << k.kho[i]->gettenhang() << "|"
             << k.kho[i]->getloaihang() << "|"
             << k.kho[i]->getdonvitinh() << "|"
             << k.kho[i]->getsoluong() << "|"
             << k.kho[i]->getdongia() << "|"
             << k.kho[i]->getthuoctinh() << endl;
    }
    k.save_kho = 1;
    file.close();
    cout << "[OK] Lưu file thành công!" << endl;
}

bool Kho::check_ma(const string ma)
{
    for (size_t i = 0; i < this->kho.size(); i++)
    {
        if (toUpperString(ma) == this->kho[i]->getmahang())
        {
            return false;
        }
    }
    return true;
}
bool Kho::check_ten(const string ten)
{
    for (size_t i = 0; i < kho.size(); i++)
    {
        if (ten == kho[i]->gettenhang())
        {
            return false;
        }
    }
    return true;
}
void Kho::add(const string &mahang)
{
    int loai = 0;
    while (true)
    {
        if (readInt("Chọn loại hàng hóa mới (1. Thực phẩm / 2. Vật tư): ", loai) && (loai == 1 || loai == 2))
        {
            break;
        }
        cout << "[Lỗi] Vui lòng chỉ chọn 1 hoặc 2.\n";
    }

    unique_ptr<Hanghoa> hh;
    if (loai == 1)
    {
        hh = make_unique<ThucPham>();
    }
    else
    {
        hh = make_unique<VatTu>();
    }

    hh->setmahang(mahang);
    hh->nhap_thong_tin();
    hh->setsoluong(0);
    hh->setloaihang(loai == 1 ? "TP" : "VT");
    this->kho.push_back(move(hh));
    this->soluonghang = static_cast<int>(this->kho.size());
    this->save_kho = 0;
    cout << "[OK] Đã tạo mặt hàng \"" << mahang << "\" trong kho.\n";
}
// sort

void Kho::sortByMaHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        string pivot = kho[high]->getmahang();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->getmahang() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortByMaHang(kho, low, pi - 1);
        sortByMaHang(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
void Kho::sortByTenHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        string pivot = kho[high]->gettenhang();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->gettenhang() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortByTenHang(kho, low, pi - 1);
        sortByTenHang(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
void Kho::sortByLoaiHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        string pivot = kho[high]->getloaihang();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->getloaihang() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortByLoaiHang(kho, low, pi - 1);
        sortByLoaiHang(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
void Kho::sortByDonViTinh(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        string pivot = kho[high]->getdonvitinh();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->getdonvitinh() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortByDonViTinh(kho, low, pi - 1);
        sortByDonViTinh(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
void Kho::sortBySoLuong(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        long long pivot = kho[high]->getsoluong();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->getsoluong() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortBySoLuong(kho, low, pi - 1);
        sortBySoLuong(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
void Kho::sortByDonGia(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    if (low < high)
    {
        long long pivot = kho[high]->getdongia();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (kho[j]->getdongia() < pivot)
            {
                i++;
                swap(kho[i], kho[j]);
            }
        }
        swap(kho[i + 1], kho[high]);
        int pi = i + 1;
        sortByDonGia(kho, low, pi - 1);
        sortByDonGia(kho, pi + 1, high);
    }
    this->save_kho = 0;
}
// Search
int Kho::searchByMaHang(const string &ma) const
{
    if (kho.empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return -1;
    }
    try
    {
        for (size_t i = 0; i < kho.size(); ++i)
        {
            if (kho[i]->getmahang() == toUpperString(ma))
            {
                return static_cast<int>(i);
            }
        }
        throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với mã: " + ma);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return -1;
}
void Kho::searchByTenHang(const string &ten) const
{
    if (kho.empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return;
    }
    bool found = false;
    try
    {
        for (int i = 0; i < this->soluonghang; i++)
        {
            if (this->kho[i]->gettenhang().find(ten) != string::npos)
            {
                this->kho[i]->show();
                found = true;
            }
        }
        if (!found)
        {
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với tên: " + ten);
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}

void Kho::searchByLoaiHang(const string &loai) const
{
    if (kho.empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return;
    }
    bool found = false;
    try
    {
        for (int i = 0; i < this->soluonghang; i++)
        {
            if (this->kho[i]->getloaihang().find(loai) != string::npos)
            {
                this->kho[i]->show();
                found = true;
            }
        }
        if (!found)
        {
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với loại: " + loai);
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}

void Kho::searchByDonViTinh(const string &donvitinh) const
{
    if (kho.empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return;
    }
    bool found = false;
    try
    {
        for (int i = 0; i < this->soluonghang; i++)
        {
            if (this->kho[i]->getdonvitinh().find(donvitinh) != string::npos)
            {
                this->kho[i]->show();
                found = true;
            }
        }
        if (!found)
        {
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với đơn vị tính: " + donvitinh);
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}
// Delete
void Kho::deleteByMaHang(const string &mahang)
{
    try
    {
        if (kho.empty())
        {
            throw runtime_error("[Lỗi] Kho hàng hóa rỗng.");
        }
        int index = searchByMaHang(mahang);
        if (index != -1)
        {
            kho.erase(kho.begin() + index);
            soluonghang = kho.size();
            cout << "[OK] Đã xóa hàng hóa với mã: " << mahang << endl;
            this->save_kho = 0;
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}
void Kho::update()
{
    if (kho.empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return;
    }

    string mahang;
    int index = -1;
    while (true)
    {
        cout << "Nhập mã hàng cần cập nhật: ";
        getline(cin, mahang);
        mahang = toUpperString(mahang);
        if (mahang.empty())
        {
            cout << "[Lỗi] Mã hàng không được để trống.\n";
            continue;
        }
        index = searchByMaHang(mahang);
        if (index != -1)
            break;
    }

    auto &hanghoa = kho[index];
    cout << "Nhập thông tin mới cho hàng hóa (để trống để giữ nguyên):" << endl;

    string tenhang, donvitinh, sl_str, gia_str, thuoctinh;
    long long sl_moi = hanghoa->getsoluong();
    long long gia_moi = hanghoa->getdongia();

    cout << "Tên hàng (" << hanghoa->gettenhang() << "): ";
    getline(cin, tenhang);

    cout << "Đơn vị tính (" << hanghoa->getdonvitinh() << "): ";
    getline(cin, donvitinh);

    while (true)
    {
        cout << "Nhập +/- để tăng/giảm số lượng hoặc nhập số mới để thay thế\n";
        cout << "Số lượng (" << hanghoa->getsoluong() << "): ";
        getline(cin, sl_str);
        if (sl_str.empty())
            break;
        try
        {
            long long val = stringToLL(sl_str);
            long long temp = (sl_str[0] == '+' || sl_str[0] == '-')
                                 ? (hanghoa->getsoluong() + val)
                                 : val;
            if (temp < 0)
            {
                cout << "[Lỗi] Số lượng tồn sau cập nhật không được âm.\n";
                continue;
            }
            sl_moi = temp;
            break;
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }

    while (true)
    {
        cout << "Nhập +/- để tăng/giảm đơn giá hoặc nhập số mới để thay thế\n";
        cout << "Đơn giá (" << hanghoa->getdongia() << "): ";
        getline(cin, gia_str);
        if (gia_str.empty())
            break;
        try
        {
            long long val = stringToLL(gia_str);
            long long temp = (gia_str[0] == '+' || gia_str[0] == '-')
                                 ? (hanghoa->getdongia() + val)
                                 : val;
            if (temp <= 0)
            {
                cout << "[Lỗi] Đơn giá phải lớn hơn 0.\n";
                continue;
            }
            gia_moi = temp;
            break;
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Vui lòng nhập số nguyên hợp lệ.\n";
        }
    }

    cout << "Thuộc tính (" << hanghoa->getthuoctinh() << "): ";
    getline(cin, thuoctinh);

    if (!tenhang.empty())
        hanghoa->settenhang(tenhang);
    if (!donvitinh.empty())
        hanghoa->setdonvitinh(donvitinh);
    if (!sl_str.empty())
        hanghoa->setsoluong(sl_moi);
    if (!gia_str.empty())
        hanghoa->setdongia(gia_moi);
    if (!thuoctinh.empty())
        hanghoa->setthuoctinh(thuoctinh);

    cout << "[OK] Cập nhật hàng hóa thành công!" << endl;
    this->save_kho = 0;
}
void Kho::thanhtien()
{
    for (size_t i = 0; i < this->kho.size(); i++)
    {
        cout << left << setw(10) << this->kho[i]->getmahang()
             << setw(22) << this->kho[i]->gettenhang()
             << setw(30) << this->kho[i]->getsoluong() * this->kho[i]->getdongia() << endl;
    }
}
long long Kho::tongtien() const
{
    long long sum = 0;
    for (int i = 0; i < this->soluonghang; i++)
    {
        sum += this->kho[i]->getdongia() * this->kho[i]->getsoluong();
    }
    return sum;
}
// Canh bao
void Kho::canhbao_sl()
{
    bool check = 0;
    for (int i = 0; i < this->soluonghang; i++)
    {
        if (this->kho[i]->getsoluong() < 10)
        {
            cout << "Mặt hàng " << this->kho[i]->gettenhang() << " sắp hết!" << endl;
            check = 1;
        }
    }
    if (!check)
        cout << "Không có mặt hàng nào sắp hết" << endl;
}

// GETTER
int &Kho::getsoluonghang()
{
    return this->soluonghang;
}
vector<unique_ptr<Hanghoa>> &Kho::getkho()
{
    return this->kho;
}
// Setter
void Kho::setsoluonghang(const int &sl)
{
    this->soluonghang = sl;
}
