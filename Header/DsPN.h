#pragma once
#include <iostream>
#include <string>
#include "Dsphieunhap.h"
#include "menu.h"

using namespace std;

inline void DsPN_function(Dsphieunhap &ds, Kho &kho, qlncc &ncc, int &choice4)
{
    int subchoice = -1;
    switch (choice4)
    {
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
        ds.update();
        break;
    }
    case 4:
        while (true)
        {
            clear_display();
            menu_DSPN_Sort();
            if (!readInt("Nhập lựa chọn sắp xếp: ", subchoice))
            {
                stop_display();
                continue;
            }
            int n = static_cast<int>(ds.getdsPN().size()) - 1;

            switch (subchoice)
            {
            case 1:
                ds.sortByMaPhieu(ds.getdsPN(), 0, n);
                break;
            case 2:
                ds.sortBySoLuong(ds.getdsPN(), 0, n);
                break;
            case 0:
                return;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ\n";
                return;
            }
            clear_display();
            cout << "[OK] Sắp xếp thành công!\n\n";
            ds.show();
            break;
        }
        break;
    case 5:
    {
        string ma;
        clear_display();
        cout << "Nhập mã phiếu cần tìm: ";
        cin.ignore();
        getline(cin, ma);
        ds.searchByMaPhieu(ma);
        break;
    }
    case 6:
    {
        string ma;
        clear_display();
        cout << "Nhập mã phiếu cần xóa: ";
        getline(cin, ma);
        ds.deleteByMaPhieu(ma);
        break;
    }
    case 7:
        luufile(ds, "Data\\dspn.txt");
        break;
    default:
    {
        clear_display();
        cout << "[Lỗi] Lựa chọn không hợp lệ." << endl;
        break;
    }
    }
}