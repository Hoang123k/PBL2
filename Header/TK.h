#pragma once
#include <iostream>
#include "Dsphieunhap.h"
#include "Kho.h"
#include "qlncc.h"
#include "menu.h"

using namespace std;
inline void TK_function(Dsphieunhap &ds, Kho &k, qlncc &n, int &choice5)
{
    switch (choice5)
    {
    case 0:
        return;
    case 1:
    {
        int subchoice = -1;
        while (subchoice != 0)
        {
            clear_display();
            menu_TK_NH();
            if (!readInt("Nhập lựa chọn: ", subchoice))
            {
                break;
            }
            switch (subchoice)
            {
            case 0:
                break;
            case 1:
            {
                int costchoice = -1;
                while (costchoice != 0)
                {
                    clear_display();
                    menu_TK_NH_COST();
                    if (!readInt("Nhập lựa chọn: ", costchoice))
                    {
                        return;
                    }
                    switch (costchoice)
                    {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        cout << "Tổng chi phí nhập hàng trong tháng: " << TK_1thang(ds) << "VND" << endl;
                        system("pause");
                        break;
                    case 3:
                        break;
                    default:
                        cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                int maxchoice = -1;
                while (maxchoice != 0)
                {
                    clear_display();
                    if (!readInt("Nhập lựa chọn (max - 1 / min - 2 / quay lại - 0): ", maxchoice))
                    {
                        break;
                    }
                    switch (maxchoice)
                    {
                    case 0:
                        break;
                    case 1:
                        ds.max_PN().show();
                        system("pause");
                        break;
                    case 2:
                        break;
                    default:
                        cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 3:
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                system("pause");
                break;
            }
        }
        break;
    }

    case 2:
    {
        int subchoice = -1;
        while (subchoice != 0)
        {
            clear_display();
            menu_TK_Kho();
            if (!readInt("Nhập lựa chọn: ", subchoice))
            {
                return;
            }
            switch (subchoice)
            {
            case 0:
                break;
            case 1:
                cout << "Tổng số tiền các mặt hàng trong kho: " << k.tongtien() << "VND"<< endl;
                system("pause");
                break;
            case 2:
                k.canhbao_sl();
                system("pause");
                break;
            case 3:
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                system("pause");
                break;
            }
        }
        break;
    }

    case 3:
    {
        int subchoice = -1;
        while (subchoice != 0)
        {
            clear_display();
            menu_TK_NCC();
            if (!readInt("Nhập lựa chọn: ", subchoice))
            {
                return;
            }
            switch (subchoice)
            {
            case 0:
                break;
            case 1:
                clear_display();
                ds.Tyle_Ncc(n);
                stop_display();
                break;
            case 2:
            {
                string ma;
                cout << "Nhập mã nhà cung cấp: ";
                getline(cin, ma);
                if(n.get_index_mancc(ma) == -1)
                {
                    cout << "[Lỗi] Mã nhà cung cấp không tồn tại" << endl;
                    stop_display();
                    break;
                }
                cout << "Tổng giá trị nhà cung cấp " << ma << " giao dịch: "<<ds.tong_gtri_ncc(ma) << "VND" << endl;
                stop_display();
                break;
            }
            case 3:
                clear_display();
                ds.ncc_biggest(n);
                stop_display();
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                system("pause");
                break;
            }
        }
        break;
    }

    default:
        cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
        break;
    }
}