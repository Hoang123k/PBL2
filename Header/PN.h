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
        cout << "Tổng tiền của phiếu: " << cost_PN(pn) << "VND" << endl;
        break;
    case 2:
        while (true)
        {
            clear_display();
            menu_add_PN();
            if (!readInt("Nhập lựa chọn thêm hàng hóa vào phiếu: ", subchoice))
            {
                stop_display();
                continue;
            }
            switch (subchoice)
            {
            case 0:
                return;
            case 1:
                pn.add_1hh(kho, ncc, ds);
                break;
            case 2:
                while (true)
                {
                    int sl_hh;
                    if (!readInt("Nhập số lượng hàng hóa: ", sl_hh))
                    {
                        stop_display();
                        continue;
                    }
                    pn.add_nhh(sl_hh, kho, ncc, ds);
                    break;
                }
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
                return;
            }
            break;
        }
        break;
    case 3:
        clear_display();
        pn.update(kho, ncc);
        break;
    case 4:
        while (true)
        {
            int sort_subchoice = -1;
            clear_display();
            menu_PN_Sort();
            if (!readInt("Nhập lựa chọn sắp xếp: ", sort_subchoice))
            {
                stop_display();
                continue;
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
                cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
                return;
            }
            clear_display();
            cout << "[OK] Sắp xếp danh sách thành công!\n\n";
            pn.show();
            break;
        }
        break;
    case 5:
    {
        string ma;
        clear_display();
        cout << "Nhập mã hàng cần tìm trong phiếu: ";
        cin.ignore();
        getline(cin, ma);
        pn.searchByMaHang(ma);
        break;
    }
    case 6:
    {
        string ma;
        cout << "Nhap ma hang can xoa khoi phieu: ";
        getline(cin, ma);
        pn.deleteByMaHang(ma, kho, *ds);
        break;
    }
    case 7: // Thay số 7 bằng đúng số case "Lưu file" trong menu của bạn
    {
        // Đồng bộ dữ liệu vào ds
        int idx = ds->get_index_maphieu(pn.getmaphieu());
        if (idx != -1)
        {
            ds->getdsPN()[idx] = pn;
        }

        // Dùng con trỏ *ds để gọi hàm lưu toàn bộ
        luuphieunhap(*ds, "Data\\phieunhap.txt");
        pn.save_PN = 1;
        break;
    }
    case 0:
    {
        char luu;
        cout << "Ban co muon luu nhung thay doi vao file truoc khi thoat? (Y/N): ";
        cin >> luu;
        cin.ignore();
        if (toupper(luu) == 'Y')
        {
            luufile(pn, "Data\\phieunhap.txt");
        }
        return;
    }
    default:
    {
        clear_display();
        cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
        break;
    }
    }
}
