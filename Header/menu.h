#pragma once
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

inline void menu()
{
    cout << "\n==============================================" << endl;
    cout << "          HỆ THỐNG QUẢN LÝ KHO HÀNG           " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Hàng hóa trong kho" << endl;
    cout << " 2. Nhà cung cấp" << endl;
    cout << " 3. Chi tiết phiếu nhập" << endl;
    cout << " 4. Danh sách phiếu nhập" << endl;
    cout << " 5. Lưu vào file" << endl;
    // cout << " 5. Tải lại dữ liệu (Reload từ File)" << endl;
    cout << " 0. Thoát chương trình                        " << endl;
    cout << "==============================================" << endl;
}

inline void menu_HH()
{
    cout << "\n==============================================" << endl;
    cout << "           QUẢN LÝ HÀNG HÓA TRONG KHO         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Xuất danh sách hàng hóa" << endl;
    cout << " 2. Thêm vào kho" << endl;
    cout << " 3. Cập nhật thông tin" << endl;
    cout << " 4. Sắp xếp" << endl;
    cout << " 5. Tìm kiếm" << endl;
    cout << " 6. Xóa" << endl;
    cout << " 7. Tính thành tiền" << endl;
    cout << " 8. Lưu vào file" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_HH_Sort()
{
    cout << "\n==============================================" << endl;
    cout << "           SẮP XẾP HÀNG HÓA TRONG KHO         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Theo mã hàng" << endl;
    cout << " 2. Theo tên hàng" << endl;
    cout << " 3. Theo loại hàng" << endl;
    cout << " 4. Theo đơn vị tính" << endl;
    cout << " 5. Theo số lượng" << endl;
    cout << " 6. Theo đơn giá" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_HH_Search()
{
    cout << "\n==============================================" << endl;
    cout << "           TÌM KIẾM HÀNG HÓA TRONG KHO        " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Theo mã hàng" << endl;
    cout << " 2. Theo tên hàng" << endl;
    cout << " 3. Theo loại hàng" << endl;
    cout << " 4. Theo đơn vị tính" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}

inline void menu_NCC()
{
    cout << "\n==============================================" << endl;
    cout << "           QUẢN LÝ NHÀ CUNG CẤP           " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Xuất danh sách nhà cung cấp" << endl;
    cout << " 2. Thêm nhà cung cấp" << endl;
    cout << " 3. Cập nhật thông tin" << endl;
    cout << " 4. Sắp xếp" << endl;
    cout << " 5. Tìm kiếm" << endl;
    cout << " 6. Xóa" << endl;
    cout << " 0. Quay về menu chính" << endl;
    cout << "==============================================" << endl;
}

inline void menu_NCC_Sort()
{
    cout << "\n==============================================" << endl;
    cout << "           Sắp xếp nhà cung cấp               " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Sắp xếp theo mã NCC" << endl;
    cout << " 2. Sắp xếp theo tên NCC" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}

inline void menu_NCC_Search()
{
    cout << "\n==============================================" << endl;
    cout << "           Tìm kiếm nhà cung cấp              " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Tìm kiếm theo mã NCC" << endl;
    cout << " 2. Tìm kiếm theo tên NCC" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_PN()
{
    cout << "\n==============================================" << endl;
    cout << "      QUẢN LÝ HÀNG HÓA TRONG PHIẾU NHẬP       " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Xuất hàng hóa của phiếu" << endl;
    cout << " 2. Thêm hàng hóa" << endl;
    cout << " 3. Cập nhật thông tin" << endl;
    cout << " 4. Sắp xếp" << endl;
    cout << " 5. Tìm kiếm" << endl;
    cout << " 6. Xóa" << endl;
    cout << " 7. Lưu vào file(pheunhap.txt)" << endl;
    cout << " 0. Quay về menu chính" << endl;
    cout << "==============================================" << endl;
}

inline void menu_add_PN()
{
    cout << "\n==============================================" << endl;
    cout << "           THÊM HÀNG HÓA VÀO PHIẾU NHẬP       " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Một hàng hóa" << endl;
    cout << " 2. Nhiều hàng hóa" << endl;
    cout << " 0. Quay về menu phiếu nhập" << endl;
    cout << "==============================================" << endl;
}
inline void menu_PN_Sort()
{
    cout << "\n==============================================" << endl;
    cout << "           SẮP XẾP HÀNG HÓA TRONG KHO         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Theo mã hàng" << endl;
    cout << " 2. Theo mã NCC" << endl;
    cout << " 3. Theo số lượng" << endl;
    cout << " 4. Theo đơn giá" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}

inline void menu_DSPN()
{
    cout << "\n==============================================" << endl;
    cout << "          QUẢN LÝ DANH SÁCH PHIẾU NHẬP          " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Xuất danh sách phiếu nhập" << endl;
    cout << " 2. Thêm phiếu nhập" << endl;
    cout << " 3. Cập nhật thông tin" << endl;
    cout << " 4. Sắp xếp" << endl;
    cout << " 5. Tìm kiếm" << endl;
    cout << " 6. Xóa" << endl;
    cout << " 7. Lưu vào file(dspn.txt)" << endl;
    cout << " 0. Quay về menu chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_DSPN_Sort()
{
    cout << "\n==============================================" << endl;
    cout << "           SẮP XẾP DANH SÁCH PHIẾU NHẬP         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Theo mã phiếu" << endl;
    cout << " 2. Theo số lượng" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_TK()
{
    cout << "\n==============================================" << endl;
    cout << "           BÁO CÁO VÀ THỐNG KÊ         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Thống kê nhập hàng" << endl;
    cout << " 2. Thống kê tồn kho" << endl;
    cout << " 3. Thống kê nhà cung cấp" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void menu_TK_NH()
{
    cout << "\n==============================================" << endl;
    cout << "           THỐNG KÊ NHẬP HÀNG        " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Tổng chi phí nhập hàng" << endl;
    cout << " 2. Phiếu nhập có giá trị cao nhất/ thấp nhất" << endl;
    cout << " 3. Tần suất nhật" << endl;
    cout << " 4. Giá nhập trung bình của từng mặt hàng" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;   
}
inline void menu_TK_NH_COST()
{
    cout << "\n==============================================" << endl;
    cout << "           CHI PHÍ NHẬP HÀNG        " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Theo ngày" << endl;
    cout << " 2. Trong tháng" << endl;
    cout << " 3. Khoảng thòi gian" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl; 
}
inline void menu_TK_Kho()
{
    cout << "\n==============================================" << endl;
    cout << "           THỐNG KÊ TỒN KHO        " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Tổng giá trị hàng tồn kho" << endl;
    cout << " 2. Cảnh báo mặt hàng sắp hết" << endl;
    cout << " 3. Cảnh báo thực phẩm hết hạn sử dụng" << endl;
    cout << " 0. Quay về màn hình chính" << endl;   
    cout << "==============================================" << endl;
}
inline void menu_TK_NCC()
{
    cout << "\n==============================================" << endl;
    cout << "           THỐNG KÊ NHÀ CUNG CẤP         " << endl;
    cout << "==============================================" << endl;
    cout << " 1. Tỷ lệ nhà cung cấp trong nước và quốc tế" << endl;
    cout << " 2. Tổng giá trị giao dịch của các nhà cung cấp" << endl;
    cout << " 0. Quay về màn hình chính" << endl;
    cout << "==============================================" << endl;
}
inline void clear_display()
{
    system("cls");
}

inline void stop_display()
{
    system("pause");
}
inline bool readInt(const std::string &prompt, int &value)
{
    std::cout << prompt;

    std::string line;
    if (!std::getline(std::cin, line))
    {
        return false;
    }

    std::stringstream input(line);
    char extra;

    if (!(input >> value) || (input >> extra))
    {
        std::cout << "Lua chon khong hop le. Vui long nhap so.\n";
        return false;
    }

    return true;
}