#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Dsphieunhap.h"
#include "transfer.h"
#include "ThucPham.h"

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
    ds.save_dsPN = 1;
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
    ds.save_dsPN = 1;
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
    for (size_t i = 0; i < ds.dsPN.size(); i++)
    {
        cost += cost_PN(ds.getdsPN()[i]);
    }
    return cost;
}

void Dsphieunhap::max_PN()
{
    if (this->dsPN.size() == 0)
    {
        cout << "Danh sách phiếu nhập rỗng" << endl;
        return;
    }
    long long max = 0;
    Phieunhap p;
    long long temp;
    vector<size_t> ds_index;
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        temp = cost_PN(this->getdsPN()[i]);
        if (max < temp)
        {
            max = temp;
        }
    }
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        if (max == cost_PN(this->dsPN[i]))
            ds_index.push_back(i);
    }
    cout << "Phiếu nhập có giá trị cao nhất: " << this->dsPN[ds_index[0]].getmaphieu();
    if (ds_index.size() == 1)
    {
        cout << endl;
        return;
    }
    else
    {
        for (size_t i = 1; i < ds_index.size(); i++)
        {
            cout << ", " << this->dsPN[ds_index[i]].getmaphieu();
        }
    }
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
    this->save_dsPN = 0;
    cout << "[OK] Thêm phiếu nhập " << temp.getmaphieu() << " thành công." << endl;
}
// update
void Dsphieunhap::update()
{
    string ma;
    while (true)
    {
        cout << "Nhap ma phieu can cap nhat: ";
        getline(cin, ma);
        if (ma.empty())
        {
            cout << "[Lỗi] Mã phiếu rỗng" << endl;
            continue;
        }
        ma = toUpperString(ma);
        if (this->get_index_maphieu(ma) == -1)
        {
            cout << "[Lỗi] Mã phiếu không tồn tại" << endl;
            continue;
        }
        break;
    }
    int index = get_index_maphieu(ma);
    if (index >= 0)
    {
        Date date;
        cin >> date;
        this->dsPN[index].setngay(date);
        this->save_dsPN = 0;
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
        this->save_dsPN = 0;
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
        this->save_dsPN = 0;
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
            this->save_dsPN = 0;
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
    for (size_t i = 0; i < this->dsPN.size(); i++)
    {
        for (size_t j = 0; j < this->dsPN[i].getPN().size(); j++)
        {
            if (this->dsPN[i].getPN()[j].getmancc() == ma)
                gtri += this->dsPN[i].getPN()[j].thanhtien();
        }
    }
    return gtri;
}

void Dsphieunhap::ncc_biggest(qlncc &n)
{

    if (this->dsPN.size() == 0)
    {
        cout << "Danh sách phiếu nhập rỗng" << endl;
        return;
    }
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
    if (index == -1)
    {
        cout << "Không có dữ liệu giao dịch.\n";
        return;
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
        cout << "Giá trị đã giao dịch: " << this->tong_gtri_ncc(n.getql_ncc()[ds_index[0]]->getmancc()) << "VND" << endl;
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
    cout << "Giá trị đã giao dịch: " << this->tong_gtri_ncc(n.getql_ncc()[ds_index[0]]->getmancc()) << "VND" << endl;
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
    for (size_t i = 0; i < n.getql_ncc().size(); i++)
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

void Dsphieunhap::canhbao_hsd(Kho &kho)
{
    if (kho.getkho().empty())
    {
        cout << "[Lỗi] Kho hàng hóa rỗng.\n";
        return;
    }

    Date date;
    cin >> date;

    bool co_canh_bao = false;
    for (size_t i = 0; i < kho.getkho().size(); i++)
    {
        ThucPham *temp = dynamic_cast<ThucPham *>(kho.getkho()[i].get());
        if (temp == nullptr)
            continue;

        string hsd_str = temp->getthuoctinh();
        stringstream ss(hsd_str);
        string d_str, m_str, y_str;

        if (!getline(ss, d_str, '/') || !getline(ss, m_str, '/') || !getline(ss, y_str))
        {
            cout << "[Cảnh báo] Mặt hàng " << temp->getmahang()
                 << " sai định dạng HSD (" << hsd_str << ").\n";
            continue;
        }

        try
        {
            int d = static_cast<int>(stringToLL(d_str));
            int m = static_cast<int>(stringToLL(m_str));
            int y = static_cast<int>(stringToLL(y_str));

            Date hsd;
            hsd.checkdate(d, m, y);
            hsd = Date(d, m, y);

            if (date > hsd)
            {
                cout << "[Hết hạn] " << temp->getmahang() << " - " << temp->gettenhang()
                     << " | HSD: " << hsd << " | Tồn kho: " << temp->getsoluong() << endl;
                co_canh_bao = true;
            }
        }
        catch (const exception &)
        {
            cout << "[Cảnh báo] Mặt hàng " << temp->getmahang()
                 << " có ngày HSD không hợp lệ (" << hsd_str << ").\n";
        }
    }

    if (!co_canh_bao)
    {
        cout << "Không có thực phẩm nào hết hạn.\n";
    }
}