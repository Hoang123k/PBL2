#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include "./Header/Kho.h"
#include "./Header/Dsphieunhap.h"
#include "./Header/qlncc.h"
#include "./Header/menu.h"
#include "./Header/HH.h"

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    qlncc n1;
    Kho kho1;
    Phieunhap pn1;
    Dsphieunhap ds1;

    auto loadData = [&]()
    {
        docfile(n1, "Data\\ncc.txt");
        docfile(kho1, "Data\\kho.txt");
        docfile(pn1, "Data\\phieunhap.txt");
        docfile(ds1, "Data\\dspn.txt");
    };

    loadData();

    int choice = -1;

    while (true)
    {
        clear_display();
        menu();

        if (!readInt("Nhap lua chon cua ban: ", choice))
        {
            stop_display();
            continue;
        }

        if (choice == 0)
        {
            cout << "Cam on ban da su dung phan mem. Tam biet!\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int choice1 = -1;
            while (choice1 != 0)
            {
                clear_display();
                menu_HH();

                if (!readInt("Nhap lua chon hang hoa: ", choice1))
                {
                    stop_display();
                    continue;
                }

                if (choice1 == 0)
                {
                    break;
                }

                HH_function(kho1, choice1);
                stop_display();
            }
            break;
        }

        case 2:
            clear_display();
            menu_NCC();
            cout << "\nCac chuc nang nha cung cap chua duoc ket noi.\n";
            stop_display();
            break;

        case 3:
            clear_display();
            menu_PN();
            cout << "\nCac chuc nang chi tiet phieu nhap chua duoc ket noi.\n";
            stop_display();
            break;

        case 4:
            clear_display();
            menu_DSPN();
            cout << "\nCac chuc nang danh sach phieu nhap chua duoc ket noi.\n";
            stop_display();
            break;

        case 5:
            clear_display();
            loadData();
            cout << "Da tai lai du lieu.\n";
            stop_display();
            break;

        default:
            cout << "Lua chon khong hop le. Vui long chon tu 0 den 5.\n";
            stop_display();
            break;
        }
    }

    return 0;
}