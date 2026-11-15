#pragma once
#include <iostream>
#include "Phieunhap.h"
#include "Dsphieunhap.h"
#include "menu.h"

using namespace std;

inline void PN_function(Phieunhap &pn, Kho &kho, qlncc &ncc, Dsphieunhap* ds, int choice3)
{
    int subchoice = -1;
    switch (choice3)
    {
    case 0:
        return;
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
            pn.add_1hh(kho, ncc,ds);
            break;
        case 2:
            int sl_hh;
            if (!readInt("Nhập số lượng hàng hóa: ", sl_hh))
            {
                return;
            }
            pn.add_nhh(sl_hh, kho, ncc,ds);
            break;
        default:
            std::cout << "[Lỗi] 2Lựa chọn không hợp lệ.\n";
            return;
        }
        break;

    case 3:
    {
        int sort_subchoice = -1;
        clear_display();
        menu_PN_Sort();
        if (!readInt("Nhập lựa chọn sắp xếp: ", sort_subchoice))
        {
            return;
        }

        switch (sort_subchoice)
        {
        case 0:
            return;
        case 1:
        {
            pn.sortByMaHang(pn.getPN(), 0,
                            static_cast<int>(pn.getPN().size()) - 1);
            break;
        }
        default:
            std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
            break;
        }
        clear_display();
        pn.show();
        break;
    }
    case 7:
        luufile(pn, "Data\\phieunhap.txt");
        break;

    default:
    {
        clear_display();
        std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
        break;
    }
    }
}
