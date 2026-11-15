#pragma once
#include <iostream>
#include <string>
#include "Dsphieunhap.h"
#include "menu.h"

using namespace std;

inline void DsPN_function(Dsphieunhap &ds, Kho &kho, qlncc &ncc, int &choice4)
{
    // int subchoice = -1;
    switch (choice4)
    {
    case 0:
        return;

    case 1:
        clear_display();
        ds.show();
        break;
    case 2:
        clear_display();
        ds.add(kho, ncc);
        break;
    case 3:
    {
        clear_display();
        menu_DSPN_Sort();
        int sort_subchoice = -1;
        if (!readInt("Nhập lựa chọn sắp xếp: ", sort_subchoice))
        {
            return;
        }
        switch (sort_subchoice)
        {
        case 0:
            return;
        case 1:
            ds.sortByMaPhieu(ds.getdsPN(), 0, static_cast<int>(ds.getdsPN().size() - 1));
            break;
        default:
            cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
            break;
        }
        clear_display();
        ds.show();
        break;
    }
    case 7:
        luufile(ds,"Data\\dspn.txt");
        break;
    default:
    {
        clear_display();
        cout << "[Lỗi] Lựa chọn không hợp lệ." << endl;
        break;
    }
    }
}