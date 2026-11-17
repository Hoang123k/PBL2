#pragma once
#include <iostream>
#include "Phieunhap.h"
#include "Dsphieunhap.h"
#include "menu.h"

using namespace std;

inline void PN_function(Phieunhap &pn, Kho &kho, qlncc &ncc, Dsphieunhap *ds, int choice3)
{
    int subchoice = -1;
    switch (choice3)
    {
    case 1:
        clear_display();
        pn.show();
        break;
    case 2:
        clear_display();
        menu_add_PN();
        if (!readInt("Nhập lựa chọn thêm hàng hóa vào phiếu: ", subchoice))
        {
            return;
        }
        switch (subchoice)
        {
        case 0:
            return;
        case 1:
            pn.add_1hh(kho, ncc, ds);
            break;
        case 2:
            int sl_hh;
            if (!readInt("Nhập số lượng hàng hóa: ", sl_hh))
            {
                return;
            }
            pn.add_nhh(sl_hh, kho, ncc, ds);
            break;
        default:
            std::cout << "[Lỗi] 2Lựa chọn không hợp lệ.\n";
            return;
        }
        break;
    case 3:
        clear_display();
        pn.update(kho);
        std::cout << "\nNhan Enter de tiep tuc...";
        std::cin.get();
        break;
    case 4:
    {
        int sort_subchoice = -1;
        clear_display();
        menu_PN_Sort();
        if (!readInt("Nhập lựa chọn sắp xếp: ", sort_subchoice))
        {
            return;
        }
        int n = static_cast<int>(pn.getPN().size()) - 1;
        switch (sort_subchoice)
        {
        case 0:
            return;
        case 1:
            pn.sortByMaHang(pn.getPN(), 0, n);
            break;
        case 2:
            pn.sortByMaNCC(pn.getPN(), 0, n);
            break;
        case 3:
            pn.sortBySoLuong(pn.getPN(), 0, n);
            break;
        case 4:
            pn.sortByDonGia(pn.getPN(), 0, n);
            break;
        default:
            std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
            return;
        }
        clear_display();
        std::cout << "[OK] Sắp xếp danh sách thành công!\n\n";
        pn.show();
        break;
    }
    case 5:
    {
        std::string ma;
        clear_display();
        std::cout << "Nhập mã hàng cần tìm trong phiếu: ";
        std::cin.ignore();
        std::getline(std::cin, ma);
        pn.searchByMaHang(ma);
        break;
    }
    case 6:
    {
        std::string ma;
        std::cout << "Nhap ma hang can xoa khoi phieu: ";
        std::getline(std::cin, ma);
        pn.deleteByMaHang(ma,kho);
        break;
    }
    case 7:
        luufile(pn, "Data\\phieunhap.txt");
        break;
    case 0:
    {
        char luu;
        std::cout << "Ban co muon luu nhung thay doi vao file truoc khi thoat? (Y/N): ";
        std::cin >> luu;
        std::cin.ignore();
        if (toupper(luu) == 'Y')
        {
            luufile(pn, "Data\\phieunhap.txt");
        }
        return;
    }
    default:
    {
        clear_display();
        std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
        break;
    }
    }
}
