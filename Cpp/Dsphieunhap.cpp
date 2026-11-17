#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Dsphieunhap.h"
#include "transfer.h"
#include "menu.h"
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
    ofstream file(filename);
    for (int i = 0; i < ds.getsoluongphieu(); i++)
    {
        file << toUpperString(ds.getdsPN()[i].getmaphieu()) << "|"
             << ds.getdsPN()[i].getngay() << "|"
             << ds.getdsPN()[i].getsoluong() << endl;
    }
    file.close();
}

// long long TK_1ngay(Dsphieunhap& ds)
// {
//     Date date;
//     cin >> date;

// }
long long TK_1thang(Dsphieunhap &ds)
{
    long long cost = 0;
    for (int i = 0; i < ds.getsoluongphieu(); i++)
    {
        cost += cost_PN(ds.getdsPN()[i]);
    }
    return cost;
}

Phieunhap Dsphieunhap::max_PN()
{
    long long max = 0;
    Phieunhap p;
    long long temp;
    for (int i = 0; i < this->getsoluongphieu(); i++)
    {
        temp = cost_PN(this->getdsPN()[i]);
        if (max < temp)
        {
            max = temp;
            p = this->getdsPN()[i];
        }
    }
    if (max)
        return p;
    cout << "Danh sách phiếu nhập rỗng" << endl;
    return p;
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
        maphieu = toUpperString(maphieu);
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
    temp.add_nhh(soluong, kho, ncc, this);
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
    ma = toUpperString(ma);
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

void Dsphieunhap::searchByNgayNhap(Date &ngay) const
{
    bool found = false;
    string searchNgay = Date_to_string(ngay);
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        string currentNgay = Date_to_string(this->dsPN[i].getngay());
        if (currentNgay.find(searchNgay) != string::npos)
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
        cout << "[Lỗi] Không tìm thấy phiếu nhập chứa ngày: " << ngay << endl;
}

void Dsphieunhap::deleteByMaPhieu(const string &ma)
{
    bool found = false;
    string ma_upper = toUpperString(ma);
    for (auto it = this->dsPN.begin(); it != this->dsPN.end();)
    {
        if (it->getmaphieu() == ma_upper)
        {
            it = this->dsPN.erase(it);
            this->soluongphieu = static_cast<int>(this->dsPN.size());
            found = true;
            cout << "[OK] Đã xóa phiếu nhập mã '" << ma_upper << "' thành công!\n";
            break;
        }
        else
        {
            ++it;
        }
    }
    if (!found)
        cout << "[Lỗi] Không tìm thấy phiếu nhập mã '" << ma_upper << "'!\n";
}

// TK_Ncc
long long Dsphieunhap::tong_gtri_ncc(const string &ma)
{
    long long gtri = 0;
    for (int i = 0; i < this->soluongphieu; i++)
    {
        for (int j = 0; j < this->dsPN[i].getsoluong(); j++)
        {
            if (this->dsPN[i].getPN()[j].getmancc() == ma)
                gtri += this->dsPN[i].getPN()[j].thanhtien();
        }
    }
    return gtri;
}

void Dsphieunhap::ncc_biggest(qlncc &n)
{
    vector<int> ds_index;
    long long max = 0;
    int index = -1;
    for (int i = 0; i < n.getsoluongncc(); i++)
    {
        if (this->tong_gtri_ncc(n.getql_ncc()[i]->getmancc()) > max)
        {
            max = this->tong_gtri_ncc(n.getql_ncc()[i]->getmancc());
            index = i;
        }
    }
    ds_index.push_back(index);
    for (int i = 0; i < n.getsoluongncc(); i++)
    {
        if (max == this->tong_gtri_ncc(n.getql_ncc()[i]->getmancc()) && i != index)
            ds_index.push_back(i);
    }
    if (ds_index.size() == 1)
    {
        cout << "Nhà cung cấp lớn nhất: " << endl;
        cout << left << setw(10) << "Mã NCC: "
             << setw(32) << "Tên NCC: "
             << setw(15) << "Mã số thuế: " << endl;

        cout << left << setw(10) << n.getql_ncc()[ds_index[0]]->getmancc()
             << setw(32) << n.getql_ncc()[ds_index[0]]->gettenncc()
             << setw(15) << n.getql_ncc()[ds_index[0]]->getmasothue() << endl;
        return;
    }
    cout << "Danh sách các nhà cung cấp lớn nhất: " << endl;
    cout << left << setw(10) << "Mã NCC: "
         << setw(32) << "Tên NCC: "
         << setw(15) << "Mã số thuế: " << endl;
    for (size_t i = 0; i < ds_index.size(); i++)
    {
        cout << left << setw(10) << n.getql_ncc()[ds_index[i]]->getmancc()
             << setw(32) << n.getql_ncc()[ds_index[i]]->gettenncc()
             << setw(15) << n.getql_ncc()[ds_index[i]]->getmasothue() << endl;
    }
    cout << endl;
}

void Dsphieunhap::Tyle_Ncc(qlncc &n)
{
    if (!n.getsoluongncc())
    {
        cout << "Không có NCC nào" << endl;
        return;
    }
    int TN = 0, QT = 0;
    long long gtri_TN = 0, gtri_QT = 0;
    for (int i = 0; i < n.getsoluongncc(); i++)
    {
        if (n.getql_ncc()[i]->getloai() == "TN")
        {
            TN++;
            gtri_TN += this->tong_gtri_ncc(n.getql_ncc()[i]->getmancc());
        }
        else
        {
            QT++;
            gtri_QT += this->tong_gtri_ncc(n.getql_ncc()[i]->getmancc());
        }
    }

    cout << "Số lượng NCC trong nước: " << TN << " - Tổng giá trị : " << gtri_TN << "VND" << endl
         << "Số lượng NCC quốc tế: " << QT << " - Tổng giá trị: " << gtri_QT << "VND" << endl;
}
// tk nhap hang
void Dsphieunhap::tk_ChiPhiNhap()
{
    int choice = -1;
    while (true)
    {
        clear_display();
        cout << string(60, '=') << "\n";
        cout << setw(38) << right << "CHI PHI NHAP HANG\n";
        cout << string(60, '=') << "\n";
        cout << "1. Theo ngay\n2. Trong thang\n3. Khoang thoi gian\n0. Quay ve man hinh chinh\n";
        cout << string(60, '=') << "\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 0)
            return;

        long long total = 0;
        if (choice == 1)
        {
            int d, m, y;
            cout << "Nhap ngay, thang, nam (cach nhau boi khoang trang): ";
            cin >> d >> m >> y;
            for (size_t i = 0; i < dsPN.size(); i++)
            {
                Date date = dsPN[i].getngay();
                if (date.getd() == d && date.getm() == m && date.gety() == y)
                {
                    for (size_t j = 0; j < dsPN[i].getPN().size(); j++)
                    {
                        total += dsPN[i].getPN()[j].getsoluongnhap() * dsPN[i].getPN()[j].getdongianhap();
                    }
                }
            }
            cout << "Tong chi phi nhap hang trong ngay " << d << "/" << m << "/" << y << ": " << total << "VND\n";
        }
        else if (choice == 2)
        {
            int m, y;
            cout << "Nhap thang, nam (cach nhau boi khoang trang): ";
            cin >> m >> y;
            for (size_t i = 0; i < dsPN.size(); i++)
            {
                Date date = dsPN[i].getngay();
                if (date.getm() == m && date.gety() == y)
                {
                    for (size_t j = 0; j < dsPN[i].getPN().size(); j++)
                    {
                        total += dsPN[i].getPN()[j].getsoluongnhap() * dsPN[i].getPN()[j].getdongianhap();
                    }
                }
            }
            cout << "Tong chi phi nhap hang trong thang " << m << "/" << y << ": " << total << "VND\n";
        }
        else if (choice == 3)
        {
            int d1, m1, y1, d2, m2, y2;
            cout << "Tu ngay, thang, nam: ";
            cin >> d1 >> m1 >> y1;
            cout << "Den ngay, thang, nam: ";
            cin >> d2 >> m2 >> y2;

            int date1 = y1 * 10000 + m1 * 100 + d1;
            int date2 = y2 * 10000 + m2 * 100 + d2;

            for (size_t i = 0; i < dsPN.size(); i++)
            {
                Date date = dsPN[i].getngay();
                int curDate = date.gety() * 10000 + date.getm() * 100 + date.getd();
                if (curDate >= date1 && curDate <= date2)
                {
                    for (size_t j = 0; j < dsPN[i].getPN().size(); j++)
                    {
                        total += dsPN[i].getPN()[j].getsoluongnhap() * dsPN[i].getPN()[j].getdongianhap();
                    }
                }
            }
            cout << "Tong chi phi nhap hang tu " << d1 << "/" << m1 << "/" << y1
                 << " den " << d2 << "/" << m2 << "/" << y2 << ": " << total << "VND\n";
        }

        cout << "Press any key to continue . . .";
        cin.ignore();
        cin.get();
    }
}

void Dsphieunhap::tk_PhieuNhapMinMax()
{
    int type;
    cout << "Nhap lua chon (max - 1 / min - 2 / quay lai - 0): ";
    cin >> type;
    if (type == 0)
        return;

    long long targetVal = (type == 1) ? -1 : 999999999999999LL;
    int targetIdx = -1;

    for (size_t i = 0; i < dsPN.size(); i++)
    {
        long long sum = 0;
        for (size_t j = 0; j < dsPN[i].getPN().size(); j++)
        {
            sum += dsPN[i].getPN()[j].getsoluongnhap() * dsPN[i].getPN()[j].getdongianhap();
        }

        if (type == 1 && sum > targetVal)
        {
            targetVal = sum;
            targetIdx = i;
        }
        if (type == 2 && sum > 0 && sum < targetVal)
        {
            targetVal = sum;
            targetIdx = i;
        }
    }

    if (targetIdx != -1)
    {
        cout << "\n=> Phieu nhap co gia tri " << (type == 1 ? "CAO NHAT" : "THAP NHAT")
             << " la Phieu: " << dsPN[targetIdx].getmaphieu()
             << " (Tong tien: " << targetVal << " VND)\n";

        dsPN[targetIdx].show();
    }
    else
    {
        cout << "\n[!] Khong co du lieu phieu nhap phu hop!\n";
    }
}

struct ThongKeMH
{
    string mahang;
    int soLanNhap;
    long long tongSoLuong;
    long long tongTien;
};

void Dsphieunhap::tk_TanSuatVaGiaTB()
{
    vector<ThongKeMH> listTK;

    for (size_t i = 0; i < dsPN.size(); i++)
    {
        for (size_t j = 0; j < dsPN[i].getPN().size(); j++)
        {
            string ma = dsPN[i].getPN()[j].getmahang();
            long long sl = dsPN[i].getPN()[j].getsoluongnhap();
            long long gia = dsPN[i].getPN()[j].getdongianhap();

            bool found = false;
            for (size_t k = 0; k < listTK.size(); k++)
            {
                if (listTK[k].mahang == ma)
                {
                    listTK[k].soLanNhap++;
                    listTK[k].tongSoLuong += sl;
                    listTK[k].tongTien += (sl * gia);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                listTK.push_back({ma, 1, sl, sl * gia});
            }
        }
    }

    clear_display();
    cout << string(75, '=') << "\n";
    cout << left << setw(15) << "Ma Hang"
         << setw(20) << "Tan suat nhap"
         << setw(20) << "Tong SL nhap"
         << setw(20) << "Gia nhap TB" << "\n";
    cout << string(75, '-') << "\n";

    for (size_t k = 0; k < listTK.size(); k++)
    {
        long long giaTB = 0;
        if (listTK[k].tongSoLuong > 0)
        {
            giaTB = listTK[k].tongTien / listTK[k].tongSoLuong;
        }
        cout << left << setw(15) << listTK[k].mahang
             << setw(20) << listTK[k].soLanNhap
             << setw(20) << listTK[k].tongSoLuong
             << setw(20) << giaTB << "\n";
    }
    cout << string(75, '=') << "\n";
}