#include <iostream>
#include "Dsphieunhap.h"
#include "Kho.h"
#include "qlncc.h"
#include "menu.h"
using namespace std;

inline void TK_function(Dsphieunhap &ds, Phieunhap &pn, Kho &k, qlncc &n, int &choice5)
{
    int subchoice = -1;
    switch (choice5)
    {
    case 0:
        return;
    case 1:
        clear_display();
        menu_TK_NH();
        if (!readInt("Nhập lựa chọn: ", subchoice))
        {
            return;
        }
        switch (subchoice)
        {
        case 0:
            return;
        case 1:
            clear_display();
            menu_TK_NH_COST();
            int costchoice = -1;
            if (!readInt("Nhập lựa chọn: ", costchoice))
            {
                return;
            }
            switch (costchoice)
            {
            case 0:
                return;
            case 1:
                break;
            case 2:
                cout << "Tổng chi phí nhập hàng trong tháng: " << TK_1thang(ds) << endl;
                break;
            case 3:
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                break;
            }
            break;
        case 2:
            clear_display();
            int maxchoice = -1;
            if (!readInt("Nhập lựa chọn(max - 1 / min - 2 ): ", maxchoice))
            {
                return;
            }
            switch (maxchoice)
            {
            case 0:
                return;
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
                break;
            }
            break;
        case 3:
            break;
        default:
            cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
            break;
        }
        break;

    default:
        cout << "[Lỗi] Lựa chọn không hợp lệ" << endl;
        break;
    }
}