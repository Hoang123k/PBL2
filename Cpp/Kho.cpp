#include "Kho.h"
#include "ThucPham.h"
#include "VatTu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../Header/menu.h"
#include "../Header/sorting.h"
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
            k.kho.push_back(make_unique<ThucPham>(mahang, tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
        else if (loaihang == "VT" || loaihang == "vt")
        {
            k.kho.push_back(make_unique<VatTu>(mahang, tenhang, loaihang, donvitinh, soluong, dongia, thuoctinh));
        }
    }
    k.soluonghang = k.kho.size();
    cout << "Đọc file hàng hóa thành công!" << endl;
}
void luufile(Kho& k, const string& filename){
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "[Lỗi]Không thể mở file: " << filename << endl;
        return;
    }
    for(size_t i=0;i<k.kho.size();i++){
        file << k.kho[i]->getmahang() << "|" 
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
    long long soluong, dongia;
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
        while(true){
            cout << "Nhập mã hàng: ";
            getline(cin, mahang);
            if(check_ma(mahang) == true) break;
            else{
                cout << "Mã hàng đã tồn tại! Xin nhập lại mã hàng!" << endl;
            }

        }

        while(true){
            cout << "Nhập tên hàng: ";
            getline(cin, tenhang);
            if(check_ten(tenhang) == true) break;
            else{
                cout << "Tên hàng đã tồn tại. Xin nhập lại tên hàng!" << endl;
            }
        }
        cout << "Nhập đơn vị tính: ";
        getline(cin, donvitinh);
        while (true) {
            cout << "Nhập số lượng: ";
            getline(cin, sl);

            try {
                soluong = stringToLL(sl);
                if (soluong <= 0) {
                    cout << "Lỗi: Số lượng phải lớn hơn 0. Xin hãy nhập lại.\n";
                    continue;
                }
                break;
            } 
            catch (const exception& e) {
                cout << "Lỗi định dạng! Vui lòng chỉ nhập số nguyên hợp lệ.\n";
            }
        }
        while (true) {
            cout << "Nhập đơn giá: ";
            getline(cin, gia);

            try {
                dongia = stringToLL(gia);
                if (dongia <= 0) {
                    cout << "Lỗi: Đơn giá phải lớn hơn 0. Xin hãy nhập lại.\n";
                    continue;
                }
                break;
            } 
            catch (const exception& e) {
                cout << "Lỗi định dạng! Vui lòng chỉ nhập số nguyên hợp lệ.\n";
            }
        }
        cout << "Nhập thuộc tính(NSX hoặc đặc điểm): ";
        getline(cin, thuoctinh);

        if (phanloai == "TP" || phanloai == "tp")
        {
            this->kho.push_back(make_unique<ThucPham>(mahang, tenhang, "TP", donvitinh, soluong, dongia, thuoctinh));
            cout << "[OK] Thêm thực phẩm thành công!\n";
            this->save_kho = 0;
            break;
        }
        else if (phanloai == "VT" || phanloai == "vt")
        {
            this->kho.push_back(make_unique<VatTu>(mahang, tenhang, "VT", donvitinh, soluong, dongia, thuoctinh));
            cout << "[OK] Thêm vật tư thành công!\n";
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
    this->save_kho = 0;
}
void Kho::sortByTenHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->gettenhang() < b->gettenhang();
                      });
    this->save_kho = 0;
}
void Kho::sortByLoaiHang(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getloaihang() < b->getloaihang();
                      });
    this->save_kho = 0;
}
void Kho::sortByDonViTinh(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getdonvitinh() < b->getdonvitinh();
                      });
    this->save_kho = 0;
}
void Kho::sortBySoLuong(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getsoluong() < b->getsoluong();
                      });
    this->save_kho = 0;
}
void Kho::sortByDonGia(vector<unique_ptr<Hanghoa>> &kho, int low, int high)
{
    quickSortTemplate(kho, low, high,
                      [](const unique_ptr<Hanghoa> &a,
                         const unique_ptr<Hanghoa> &b)
                      {
                          return a->getdongia() < b->getdongia();
                      });
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
            if (kho[i]->getmahang() == ma)
            {
                return i;
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
void Kho::searchByTenHang(const string& ten) const {
    if (kho.empty()) {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
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
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với tên: " + ten);
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::searchByLoaiHang(const string& loai) const {
    if (kho.empty()) {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
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
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với loại: " + loai);
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::searchByDonViTinh(const string& donvitinh) const {
    if (kho.empty()) {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
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
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với đơn vị tính: " + donvitinh);
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
            throw runtime_error("[Lỗi] Kho hàng hóa rỗng.");
        }
        int index = searchByMaHang(mahang);
        if(index == -1){
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với mã: " + mahang);
        }
        if(index != -1){
            kho.erase(kho.begin() + index);
            soluonghang = kho.size();
            cout << "[OK] Đã xóa hàng hóa với mã: " << mahang << endl;
            this->save_kho = 0;
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Kho::update() {
    if (kho.empty()) {
        cout << "[Lỗi] Kho hàng hóa rỗng." << endl;
        return;
    }
    string mahang;
    cout << "Nhập mã hàng cần cập nhật: ";
    cin >> mahang;
    cin.ignore();

    int index = searchByMaHang(mahang);
    if (index == -1) {
        cout << "[Lỗi] Không tìm thấy hàng hóa với mã: " << mahang << endl;
        return;
    }

    auto& hanghoa = kho[index];

    cout << "Nhập thông tin mới cho hàng hóa(để trống để giữ nguyên):" << endl;
    string tenhang, loaihang, donvitinh, sl_str, gia_str, thuoctinh;

    cout << "Tên hàng (" << hanghoa->gettenhang() << "): ";
    getline(cin, tenhang);
    cout << "Loại hàng (" << hanghoa->getloaihang() << "): ";
    getline(cin, loaihang);
    cout << "Đơn vị tính (" << hanghoa->getdonvitinh() << "): ";
    getline(cin, donvitinh);
    cout << "Nhập +/- để tăng/giảm số lượng hoặc nhập số bình thường để cập nhật số lượng mới" << endl;
    cout << "So luong (" << hanghoa->getsoluong() << "): ";
    getline(cin, sl_str);
    cout << "Nhập +/- để tăng/giảm đơn giá hoặc nhập số bình thường để cập nhật đơn giá mới" << endl;
    cout << "Đơn giá (" << hanghoa->getdongia() << "): ";
    getline(cin, gia_str);
    cout << "Thuộc tính (" << hanghoa->getthuoctinh() << "): ";
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

    cout << "[OK] Cập nhật hàng hóa thành công!" << endl;
    this->save_kho = 0;

}


void Kho::thanhtien(){
    for(size_t i=0;i<this->kho.size();i++){
        cout << setw(10) << this->kho[i]->getmahang() 
             << setw(22) << this->kho[i]->gettenhang()
             << setw(30) << this->kho[i]->getsoluong() * this->kho[i]->getdongia() << endl;
    } 
}