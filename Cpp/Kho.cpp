#include "Kho.h"
#include "ThucPham.h"
#include "VatTu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../Header/menu.h"
#include "../Header/sorting.h"

using namespace std;

Kho::Kho() : soluonghang(0) {}
Kho::~Kho() {}

void Kho::show() const
{
    cout << "So luong hang hoa hien tai trong kho: " << this->soluonghang << endl;
    cout << left
         << setw(10) << "Ma Hang"
         << setw(22) << "Ten Hang"
         << setw(20) << "Loai Hang"
         << setw(15) << "Don Vi Tinh"
         << setw(12) << "So Luong"
         << setw(10) << "Don Gia"
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
        cout << "Khong the mo file: " << filename << endl;
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
            k.kho.push_back(make_unique<ThucPham>(mahang, tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
        else if (loaihang == "VT" || loaihang == "vt")
        {
            k.kho.push_back(make_unique<VatTu>(mahang, tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
    }
    k.soluonghang = k.kho.size();
    cout << "Doc file Kho thanh cong!" << endl;
}
bool Kho::check_ma(const string ma){
    for(size_t i=0;i<kho.size();i++){
        if(ma == kho[i]->getmahang()){
            return false;
        }
    }
    return true;
}
bool Kho::check_ten(const string ten){
    for(size_t i=0;i<kho.size();i++){
        if(ten == kho[i]->gettenhang()){
            return false;
        }
    }
    return true;
}
void Kho::add()
{
    cout << "\n================ THÊM MẶT HÀNG MỚI ================" << endl;
    string phanloai, mahang, tenhang, donvitinh, sl, gia, thuoctinh;

    do
    {
        cout << "Nhập phân loại(Thực phẩm: TP/tp - Vật tư: VT/vt ): ";
        cin >> phanloai;
        cin.ignore();
        if (phanloai != "TP" && phanloai != "tp" && phanloai != "VT" && phanloai != "vt")
        {
            cout << "Phân loại hàng không hợp lệ! Xin nhập VT/vt hoặc TP/tp.\n";
            continue;
        }
        cout << "Nhập mã hàng: ";
        getline(cin, mahang);
        while(check_ma(mahang) == false){
            cout << "Mã hàng đã tồn tại. Xin nhập lại mã hàng!" << endl;
            cout << "Nhập mã hàng: ";
            getline(cin, mahang);

        }
        cout << "Nhập tên hàng: ";
        getline(cin, tenhang);
        while(check_ten(tenhang) == false){
            cout << "Tên hàng đã tồn tại. Xin nhập lại tên hàng!" << endl;
            cout << "Nhập tên hàng: ";
            getline(cin, tenhang);

        }
        cout << "Nhập đơn vị tính: ";
        getline(cin, donvitinh);
        cout << "Nhập số lượng: ";
        getline(cin, sl);
        while(stoll(sl)<=0){
            cout << "Lỗi số lượng! Xin hãy nhập lại." << endl;
            cout << "Nhập số lượng: ";
            getline(cin, sl);
        }
        cout << "Nhập đơn giá: ";
        getline(cin, gia);
        while(stoll(gia)<=0){
            cout << "Lỗi đơn giá! Xin hãy nhập lại." << endl;
            cout << "Nhập đơn giá: ";
            getline(cin, sl);
        }
        cout << "Nhập thuộc tính(NSX hoặc đặc điểm): ";
        getline(cin, thuoctinh);

        int soluong = sl.empty() ? 0 : stoll(sl);
        int dongia = gia.empty() ? 0 : stoll(gia);

        if (phanloai == "TP" || phanloai == "tp")
        {
            this->kho.push_back(make_unique<ThucPham>(mahang, tenhang, "TP", donvitinh, soluong, dongia, thuoctinh));
            cout << "[OK] Them Thuc Pham thanh cong!\n";
            break;
        }
        else if (phanloai == "VT" || phanloai == "vt")
        {
            this->kho.push_back(make_unique<VatTu>(mahang, tenhang, "VT", donvitinh, soluong, dongia, thuoctinh));
            cout << "[OK] Them Vat Tu thanh cong!\n";
            break;
        }
    } while (true);

    this->soluonghang = this->kho.size();
}

// sort

void Kho::sortByMaHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getmahang() < b->getmahang();
                      });
}
void Kho::sortByTenHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->gettenhang() < b->gettenhang();
                      });
}
void Kho::sortByLoaiHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getloaihang() < b->getloaihang();
                      });
}
void Kho::sortByDonViTinh(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getdonvitinh() < b->getdonvitinh();
                      });
}
void Kho::sortBySoLuong(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getsoluong() < b->getsoluong();
                      });
}
void Kho::sortByDonGia(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getdongia() < b->getdongia();
                      });
}

// Search
int Kho::searchByMaHang(const string &ma) const
{
    if (kho.empty())
    {
        cout << "Kho hang hoa rong. Khong co hang hoa de tim kiem." << endl;
        return -1;
    }
    try
    {
        for (size_t i = 0; i < kho.size(); ++i)
        {
            if (kho[i]->getmahang() == ma)
            {
                return i;
            }
        }
        throw runtime_error("Khong tim thay hang hoa voi ma: " + ma);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return -1;
}
void Kho::searchByTenHang(const string& ten) const {
    if (kho.empty()) {
        cout << "Kho hang hoa rong. Khong co hang hoa de tim kiem." << endl;
        return ;
    }
     bool found = false;
    try {
        for (const auto& hang : kho) {
            if (hang->gettenhang().find(ten) != string::npos) {
                hang->show();
                found = true;
            }
        }
        if (!found) {
            throw runtime_error("Khong tim thay hang hoa voi tên: " + ten);
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::searchByLoaiHang(const string& loai) const {
    if (kho.empty()) {
        cout << "Kho hang hoa rong. Khong co hang hoa de tim kiem." << endl;
        return;
    }
    bool found = false;
    try {
        for (const auto& hang : kho) {
            if (hang->getloaihang().find(loai) != string::npos) {
                hang->show();
                found = true;
            }
        }
        if (!found) {
            throw runtime_error("Khong tim thay hang hoa voi loai: " + loai);
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::searchByDonViTinh(const string& donvitinh) const {
    if (kho.empty()) {
        cout << "Kho hang hoa rong. Khong co hang hoa de tim kiem." << endl;
        return;
    }
    bool found = false;
    try {
        for (const auto& hang : kho) {
            if (hang->getdonvitinh().find(donvitinh) != string::npos) {
                hang->show();
                found = true;
            }
        }
        if (!found) {
            throw runtime_error("Khong tim thay hang hoa voi don vi tinh: " + donvitinh);
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
// Delete
void Kho::deleteByMaHang(const string& mahang) {
    try{
        if (kho.empty()) {
            throw runtime_error("Kho hang hoa rong. Khong co hang hoa de xoa.");
        }
        if(searchByMaHang(mahang) == -1){
            throw runtime_error("Khong tim thay hang hoa voi ma: " + mahang);
        }
        if(searchByMaHang(mahang) != -1){
            kho.erase(kho.begin() + searchByMaHang(mahang));
            soluonghang = kho.size();
            cout << "[OK] Da xoa hang hoa voi ma: " << mahang << endl;
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::update() {
    if (kho.empty()) {
        cout << "Kho hang hoa rong. Khong co hang hoa de cap nhat." << endl;
        return;
    }
    string mahang;
    cout << "Nhap ma hang hoa can cap nhat: ";
    cin >> mahang;
    cin.ignore();

    int index = searchByMaHang(mahang);
    if (index == -1) {
        cout << "[!] Khong tim thay hang hoa voi ma: " << mahang << endl;
        return;
    }

    auto& hanghoa = kho[index];

    cout << "Nhap thong tin moi cho hang hoa (de trong de giu nguyen):" << endl;
    string tenhang, loaihang, donvitinh, sl_str, gia_str, thuoctinh;

    cout << "Ten hang (" << hanghoa->gettenhang() << "): ";
    getline(cin, tenhang);
    cout << "Loai hang (" << hanghoa->getloaihang() << "): ";
    getline(cin, loaihang);
    cout << "Don vi tinh (" << hanghoa->getdonvitinh() << "): ";
    getline(cin, donvitinh);
    cout << "Nhập +/- để tăng/giảm số lượng hoặc nhập số bình thường để cập nhật số lượng mới" << endl;
    cout << "So luong (" << hanghoa->getsoluong() << "): ";
    getline(cin, sl_str);
    cout << "Nhập +/- để tăng/giảm đơn giá hoặc nhập số bình thường để cập nhật đơn giá mới" << endl;
    cout << "Don gia (" << hanghoa->getdongia() << "): ";
    getline(cin, gia_str);
    cout << "Thuoc tinh (" << hanghoa->getthuoctinh() << "): ";
    getline(cin, thuoctinh);

    if (!tenhang.empty()) hanghoa->settenhang(tenhang);
    if (!loaihang.empty()) hanghoa->setloaihang(loaihang);
    if (!donvitinh.empty()) hanghoa->setdonvitinh(donvitinh);
    if (!sl_str.empty()){
        if(sl_str[0] == '-' || sl_str[0] == '+'){
            hanghoa->setsoluong(hanghoa->getsoluong()+stoll(sl_str));
        }
        else{
            hanghoa->setsoluong(stoll(sl_str));
        }
    } 
    if (!gia_str.empty()){
        if(gia_str[0] == '-' || gia_str[0] == '+'){
            hanghoa->setdongia(hanghoa->getdongia()+stoll(gia_str));
        }
        else{
            hanghoa->setdongia(stoll(gia_str));
        }
    }

    if (loaihang == "TP" || loaihang == "tp") {
        ThucPham* tp = dynamic_cast<ThucPham*>(hanghoa.get());
        if (tp) {
            if (!thuoctinh.empty()) tp->setthuoctinh(thuoctinh);
        }
    } else if (loaihang == "VT" || loaihang == "vt") {
        VatTu* vt = dynamic_cast<VatTu*>(hanghoa.get());
        if (vt) {
            if (!thuoctinh.empty()) vt->setthuoctinh(thuoctinh);
        }
    }

    cout << "Cap nhat hang hoa thanh cong!" << endl;

}
