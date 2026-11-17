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
        if (toUpperString(maphieu) == pn.getmaphieu())
        {
            Chitietphieunhap temp;
            temp.setmahang(toUpperString(mahang));
            temp.setmancc(toUpperString(mancc));
            temp.setsoluongnhap(soluong);
            temp.setdongianhap(dongia);
            pn.PN.push_back(temp);
        }
    }
    f.close();
}

void luufile(Phieunhap &pn, const string &filename)
{
    ofstream file(filename);
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
long long cost_PN(Phieunhap &pn)
{
    long long cost = 0;
    for (int i = 0; i < pn.getsoluong(); i++)
    {
        cost += pn.getPN()[i].thanhtien();
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
    long long soluong = 0, dongia = 0;

    while (true)
    {
        while (true)
        {
            cout << "Nhập mã hàng: ";
            getline(cin, mahang);
            mahang = toUpperString(mahang);
            if (mahang.empty())
            {
                cout << "[Lỗi] Mã hàng không được để trống.\n";
                continue;
            }

            if (kho.check_ma(mahang) == false)
            {
                break;
            }
            else
            {
                cout << "[!] Mã hàng \"" << mahang << "\" chưa có trong kho.\n";
                cout << "Bạn có muốn thêm mặt hàng mới này vào kho luôn không? (Y/y để thêm - phím khác để nhập lại mã): ";
                string chon;
                getline(cin, chon);
                if (chon == "Y" || chon == "y")
                {
                    kho.add(mahang);
                    break;
                }
            }
        }
        while (true)
        {
            cout << "Nhập mã nhà cung cấp: ";
            getline(cin, mancc);
            mancc = toUpperString(mancc);
            if (mancc.empty())
            {
                cout << "[Lỗi] Mã nhà cung cấp không được để trống.\n";
                continue;
            }

            if (ncc.get_index_mancc(mancc) != -1)
            {
                break;
            }
            else
            {
                cout << "[!] Mã nhà cung cấp \"" << mancc << "\" chưa có trong hệ thống.\n";
                cout << "Bạn có muốn thêm nhà cung cấp mới này luôn không? (Y/y để thêm - phím khác để nhập lại mã): ";
                string chon;
                getline(cin, chon);
                if (chon == "Y" || chon == "y")
                {
                    ncc.add(mancc);
                    break;
                }
            }
        }

        int idx_hh_kho = kho.searchByMaHang(mahang);
        int index = check_mahang_ncc(mahang, mancc);
        if (index != -1)
        {
            cout << "[!] Mặt hàng " << mahang << " của NCC " << mancc << " đã có trong phiếu!\n";
            cout << "    -> Hiện tại: SL = " << this->PN[index].getsoluongnhap()
                 << " | Đơn giá = " << this->PN[index].getdongianhap() << " VND\n";
            cout << "Chọn hướng xử lý:\n";
            cout << "  1. Điều chỉnh số lượng (giữ nguyên đơn giá cũ)\n";
            cout << "  2. Sửa lại đơn giá của dòng này (nếu nhập nhầm giá)\n";
            cout << "  3. Thêm dòng mới với đơn giá khác (nhập lô mới)\n";
            cout << "  0. Nhập lại mã hàng và NCC khác\n";

            string chon_xl;
            cout << "Lựa chọn của bạn: ";
            getline(cin, chon_xl);

            if (chon_xl == "1")
            {
                while (true)
                {
                    cout << "Nhập số lượng tăng (+x), giảm (-x) hoặc thay đổi (không dấu): ";
                    string sl_nhap;
                    getline(cin, sl_nhap);

                    if (sl_nhap.empty())
                    {
                        cout << "[Lỗi] Không được để trống.\n";
                        continue;
                    }

                    try
                    {
                        long long val = stringToLL(sl_nhap);
                        long long sl_cu = this->PN[index].getsoluongnhap();
                        long long sl_moi = (sl_nhap[0] == '-' || sl_nhap[0] == '+') ? (sl_cu + val) : val;

                        if (sl_moi <= 0)
                        {
                            cout << "[Lỗi] Số lượng sau điều chỉnh phải lớn hơn 0. Xin hãy nhập lại.\n";
                            continue;
                        }

                        this->PN[index].setsoluongnhap(sl_moi);
                        if (idx_hh_kho != -1)
                        {
                            long long chenh_lech = sl_moi - sl_cu;
                            long long ton_hien_tai = kho.getkho()[idx_hh_kho]->getsoluong();
                            kho.getkho()[idx_hh_kho]->setsoluong(ton_hien_tai + chenh_lech);
                        }

                        cout << "[OK] Cập nhật số lượng thành công.\n";
                        return false;
                    }
                    catch (const exception &e)
                    {
                        cout << "[Lỗi] Vui lòng chỉ nhập số nguyên hợp lệ.\n";
                    }
                }
            }
            else if (chon_xl == "2")
            {
                while (true)
                {
                    cout << "Nhập đơn giá mới: ";
                    string gia_moi_str;
                    getline(cin, gia_moi_str);
                    try
                    {
                        long long gia_moi = stringToLL(gia_moi_str);
                        if (gia_moi <= 0)
                        {
                            cout << "[Lỗi] Đơn giá phải lớn hơn 0. Xin hãy nhập lại.\n";
                            continue;
                        }

                        this->PN[index].setdongianhap(gia_moi);
                        cout << "[OK] Cập nhật đơn giá thành công.\n";
                        return false; // Không làm thay đổi tồn kho và không thêm dòng mới
                    }
                    catch (const exception &e)
                    {
                        cout << "[Lỗi] Định dạng không hợp lệ! Vui lòng chỉ nhập số nguyên.\n";
                    }
                }
            }
            else if (chon_xl == "3") // 3. Thêm dòng mới với đơn giá khác
            {
                cout << "-> Tiến hành nhập số lượng và đơn giá mới cho lô hàng này:\n";
                // Rơi tự nhiên xuống Bước 4 & Bước 5 để tạo phần tử Chitietphieunhap mới
            }
            else // Chọn 0 hoặc phím khác -> Quay lại Bước 1
            {
                continue;
            }
        }

        // =====================================================================
        // BƯỚC 4: NHẬP SỐ LƯỢNG NHẬP
        // =====================================================================
        while (true)
        {
            cout << "Nhập số lượng nhập: ";
            getline(cin, sl);
            try
            {
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
                cout << "[Lỗi] Định dạng không hợp lệ! Vui lòng chỉ nhập số nguyên.\n";
            }
        }

        // =====================================================================
        // BƯỚC 5: NHẬP ĐƠN GIÁ NHẬP
        // =====================================================================
        while (true)
        {
            cout << "Nhập đơn giá nhập: ";
            getline(cin, gia);
            try
            {
                dongia = stringToLL(gia);
                if (dongia <= 0)
                {
                    cout << "[Lỗi] Đơn giá phải lớn hơn 0. Xin hãy nhập lại.\n";
                    continue;
                }
                break;
            }
            catch (const exception &e)
            {
                cout << "[Lỗi] Định dạng không hợp lệ! Vui lòng chỉ nhập số nguyên.\n";
            }
        }

        // =====================================================================
        // BƯỚC 6: LƯU CHI TIẾT PHIẾU, CỘNG TỒN KHO & ĐỒNG BỘ DANH SÁCH PHIẾU
        // =====================================================================
        this->PN.push_back(Chitietphieunhap(mahang, mancc, soluong, dongia));
        this->soluonghh = static_cast<int>(this->PN.size());

        if (idx_hh_kho != -1)
        {
            long long ton_hien_tai = kho.getkho()[idx_hh_kho]->getsoluong();
            kho.getkho()[idx_hh_kho]->setsoluong(ton_hien_tai + soluong);
        }

        if (ds != nullptr)
        {
            int index_1 = ds->get_index_maphieu(this->getmaphieu());
            if (index_1 != -1)
            {
                ds->getdsPN()[index_1].setsoluong(static_cast<int>(this->PN.size()));
            }
        }

        cout << "[OK] Thêm hàng hóa mới vào phiếu nhập " << this->getmaphieu() << " thành công.\n";
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
void Phieunhap::sortByMaNCC(vector<Chitietphieunhap> &PN, int low, int high)
{
    if (low < high)
    {
        string pivot = PN[high].getmancc();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (PN[j].getmancc() < pivot)
            {
                i++;
                swap(PN[i], PN[j]);
            }
        }
        swap(PN[i + 1], PN[high]);
        int pi = i + 1;
        sortByMaNCC(PN, low, pi - 1);
        sortByMaNCC(PN, pi + 1, high);
    }
}
void Phieunhap::sortBySoLuong(vector<Chitietphieunhap> &PN, int low, int high)
{
    if (low < high)
    {
        long long pivot = PN[high].getsoluongnhap();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (PN[j].getsoluongnhap() < pivot)
            {
                i++;
                swap(PN[i], PN[j]);
            }
        }
        swap(PN[i + 1], PN[high]);
        int pi = i + 1;
        sortBySoLuong(PN, low, pi - 1);
        sortBySoLuong(PN, pi + 1, high);
    }
}
void Phieunhap::sortByDonGia(vector<Chitietphieunhap> &PN, int low, int high)
{
    if (low < high)
    {
        long long pivot = PN[high].getdongianhap();
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (PN[j].getdongianhap() < pivot)
            {
                i++;
                swap(PN[i], PN[j]);
            }
        }
        swap(PN[i + 1], PN[high]);
        int pi = i + 1;
        sortByDonGia(PN, low, pi - 1);
        sortByDonGia(PN, pi + 1, high);
    }
}
void Phieunhap::update(Kho &kho)
{
    if (this->PN.empty())
    {
        cout << "[Lỗi] Phiếu nhập rỗng." << endl;
        return;
    }

    string mahang;
    cout << "Nhập mã hàng cần cập nhật: ";
    getline(cin, mahang);
    mahang = toUpperString(mahang);

    // Tìm các dòng có mã hàng trùng khớp trong phiếu
    vector<size_t> ds_index;
    for (size_t i = 0; i < this->PN.size(); i++)
    {
        if (this->PN[i].getmahang() == mahang)
        {
            ds_index.push_back(i);
        }
    }

    if (ds_index.empty())
    {
        cout << "[Lỗi] Không tìm thấy hàng hóa với mã: " << mahang << endl;
        return;
    }

    size_t index = ds_index[0];
    // Nếu trong phiếu có từ 2 lô cùng mã hàng (khác NCC hoặc khác giá), chọn dòng cụ thể
    if (ds_index.size() > 1)
    {
        cout << "[!] Tìm thấy " << ds_index.size() << " dòng của mã hàng " << mahang << ":\n";
        for (size_t k = 0; k < ds_index.size(); k++)
        {
            size_t idx = ds_index[k];
            cout << "  " << k + 1 << ". Mã NCC: " << this->PN[idx].getmancc()
                 << " | Số lượng: " << this->PN[idx].getsoluongnhap()
                 << " | Đơn giá: " << this->PN[idx].getdongianhap() << endl;
        }
        while (true)
        {
            cout << "Chọn dòng cần cập nhật (1 - " << ds_index.size() << "): ";
            string chon;
            getline(cin, chon);
            try
            {
                long long stt = stringToLL(chon);
                if (stt >= 1 && stt <= static_cast<long long>(ds_index.size()))
                {
                    index = ds_index[stt - 1];
                    break;
                }
                cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
            }
            catch (const exception &)
            {
                cout << "[Lỗi] Vui lòng chỉ nhập số nguyên.\n";
            }
        }
    }

    auto &chitiet = this->PN[index];
    long long sl_cu = chitiet.getsoluongnhap();
    long long gia_cu = chitiet.getdongianhap();

    cout << "Nhập thông tin mới cho hàng hóa trong phiếu (để trống để giữ nguyên):" << endl;
    string mancc, sl_str, gia_str;

    cout << "Mã NCC (" << chitiet.getmancc() << "): ";
    getline(cin, mancc);

    cout << "Nhập +/- để tăng/giảm số lượng hoặc nhập số bình thường để cập nhật số lượng mới" << endl;
    cout << "Số lượng nhập (" << sl_cu << "): ";
    getline(cin, sl_str);

    cout << "Nhập +/- để tăng/giảm đơn giá hoặc nhập số bình thường để cập nhật đơn giá mới" << endl;
    cout << "Đơn giá nhập (" << gia_cu << "): ";
    getline(cin, gia_str);

    // 1. Xử lý cập nhật số lượng và đồng bộ Kho trước (nếu có nhập)
    if (!sl_str.empty())
    {
        try
        {
            long long sl_moi = 0;
            if (sl_str[0] == '-' || sl_str[0] == '+')
            {
                sl_moi = sl_cu + stringToLL(sl_str);
            }
            else
            {
                sl_moi = stringToLL(sl_str);
            }

            if (sl_moi <= 0)
            {
                cout << "[Lỗi] Số lượng nhập mới phải lớn hơn 0. Hủy cập nhật số lượng!" << endl;
                return;
            }

            // Đồng bộ phần chênh lệch vào tồn kho của Kho
            long long chenh_lech = sl_moi - sl_cu;
            int idx_kho = kho.searchByMaHang(mahang);
            if (idx_kho != -1)
            {
                long long ton_hien_tai = kho.getkho()[idx_kho]->getsoluong();
                if (ton_hien_tai + chenh_lech < 0)
                {
                    cout << "[Lỗi] Tồn kho hiện tại (" << ton_hien_tai << ") không đủ để giảm bớt " << -chenh_lech << "." << endl;
                    return;
                }
                kho.getkho()[idx_kho]->setsoluong(ton_hien_tai + chenh_lech);
            }

            chitiet.setsoluongnhap(sl_moi);
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Định dạng số lượng không hợp lệ!" << endl;
            return;
        }
    }

    // 2. Xử lý cập nhật đơn giá (nếu có nhập)
    if (!gia_str.empty())
    {
        try
        {
            long long gia_moi = 0;
            if (gia_str[0] == '-' || gia_str[0] == '+')
            {
                gia_moi = gia_cu + stringToLL(gia_str);
            }
            else
            {
                gia_moi = stringToLL(gia_str);
            }

            if (gia_moi <= 0)
            {
                cout << "[Lỗi] Đơn giá nhập mới phải lớn hơn 0. Hủy cập nhật đơn giá!" << endl;
                return;
            }

            chitiet.setdongianhap(gia_moi);
        }
        catch (const exception &)
        {
            cout << "[Lỗi] Định dạng đơn giá không hợp lệ!" << endl;
            return;
        }
    }

    // 3. Xử lý cập nhật mã NCC (nếu có nhập)
    if (!mancc.empty())
    {
        chitiet.setmancc(toUpperString(mancc));
    }

    cout << "[OK] Cập nhật hàng hóa trong phiếu nhập thành công!" << endl;
}

void Phieunhap::deleteByMaHang(const string &mahang, Kho &kho)
{
    try
    {
        if (this->PN.empty())
        {
            throw runtime_error("[Lỗi] Phiếu nhập rỗng.");
        }

        string ma_upper = toUpperString(mahang);
        vector<size_t> ds_index;
        for (size_t i = 0; i < this->PN.size(); i++)
        {
            if (this->PN[i].getmahang() == ma_upper)
            {
                ds_index.push_back(i);
            }
        }

        if (ds_index.empty())
        {
            throw runtime_error("[Lỗi] Không tìm thấy hàng hóa với mã: " + ma_upper);
        }

        size_t index = ds_index[0];
        if (ds_index.size() > 1)
        {
            cout << "[!] Tìm thấy " << ds_index.size() << " dòng của mã hàng " << ma_upper << ":\n";
            for (size_t k = 0; k < ds_index.size(); k++)
            {
                size_t idx = ds_index[k];
                cout << "  " << k + 1 << ". Mã NCC: " << this->PN[idx].getmancc()
                     << " | Số lượng: " << this->PN[idx].getsoluongnhap()
                     << " | Đơn giá: " << this->PN[idx].getdongianhap() << endl;
            }
            while (true)
            {
                cout << "Chọn dòng cần xóa (1 - " << ds_index.size() << "): ";
                string chon;
                getline(cin, chon);
                try
                {
                    long long stt = stringToLL(chon);
                    if (stt >= 1 && stt <= static_cast<long long>(ds_index.size()))
                    {
                        index = ds_index[stt - 1];
                        break;
                    }
                    cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
                }
                catch (const exception &)
                {
                    cout << "[Lỗi] Vui lòng chỉ nhập số nguyên.\n";
                }
            }
        }

        // Trừ số lượng của dòng bị xóa khỏi tồn kho trong Kho
        long long sl_xoa = this->PN[index].getsoluongnhap();
        int idx_kho = kho.searchByMaHang(ma_upper);
        if (idx_kho != -1)
        {
            long long ton_hien_tai = kho.getkho()[idx_kho]->getsoluong();
            long long ton_moi = (ton_hien_tai - sl_xoa < 0) ? 0 : (ton_hien_tai - sl_xoa);
            kho.getkho()[idx_kho]->setsoluong(ton_moi);
        }

        this->PN.erase(this->PN.begin() + index);
        this->soluonghh = static_cast<int>(this->PN.size());
        cout << "[OK] Đã xóa hàng hóa với mã: " << ma_upper << endl;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}
static string toLowerCase_PN(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

void Phieunhap::searchByMaHang(const string &ma) const
{
    bool found = false;
    string searchMa = toLowerCase_PN(ma);

    for (size_t i = 0; i < this->PN.size(); i++)
    {
        string currentMa = toLowerCase_PN(this->PN[i].getmahang());

        if (currentMa.find(searchMa) != string::npos)
        {
            if (!found)
            {
                cout << left
                     << setw(12) << "Ma Hang"
                     << setw(12) << "Ma NCC"
                     << setw(15) << "So Luong"
                     << setw(15) << "Don Gia" << endl;
                cout << string(65, '-') << endl;
            }
            this->PN[i].show();
            found = true;
        }
    }

    if (!found)
    {
        cout << "[Lỗi] Không tìm thấy hàng hóa có mã chứa từ khóa: " << ma << endl;
    }
    else
    {
        cout << string(65, '=') << endl;
    }
}
