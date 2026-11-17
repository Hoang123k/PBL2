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
#include "./Header/NCC_func.h"
#include "./Header/PN.h"
#include "./Header/dsPN.h"
#include "./Header/TK.h",

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

    docfile(n1, "Data\\ncc.txt");
    docfile(kho1, "Data\\kho.txt");
    docfile(ds1, "Data\\dspn.txt");
    for (int i = 0; i < ds1.getsoluongphieu(); i++)
    {
        docfile(ds1.getdsPN()[i], "Data\\phieunhap.txt");
    }

    int choice = -1;

    while (true)
    {
        clear_display();
        menu();

        if (!readInt("Nhập lựa chọn của bạn: ", choice))
        {
            stop_display();
            continue;
        }

        if (choice == 0)
        {
            cout << "Cảm ơn vì đã dùng phần mềm. Tạm biệt!\n";
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

                if (!readInt("Nhập lựa chọn hàng hóa: ", choice1))
                {
                    stop_display();
                    continue;
                }

                if (choice1 == 0)
                {
                    if (kho1.save_kho == 0)
                    {
                        cout << "[!] File chưa được lưu." << endl
                             << "Lưu file và thoát(Y/y) - Không lưu (Phím bất kỳ): ";
                        string yes;
                        getline(cin, yes);
                        if (yes == "Y" || yes == "y")
                        {
                            luufile(kho1, "Data\\kho.txt");
                            kho1.save_kho = 1;
                        }
                    }
                    break;
                }

                HH_function(kho1, choice1);
                stop_display();
            }
            break;
        }

        case 2:
        {
            int choice2 = -1;
            while (choice2 != 0)
            {
                clear_display();
                menu_NCC();

                if (!readInt("Nhap lua chon nha cung cap: ", choice2))
                {
                    stop_display();
                    continue;
                }
                NCC_function(n1, choice2);
                if (choice2 == 0)
                {
                    break;
                }
                stop_display();
            }
            break;
        }
        case 3:
        {
            string maphieu;
            while (true)
            {
                cout << "Nhập mã phiếu thao tác: ";
                getline(cin, maphieu);
                int index = ds1.get_index_maphieu(maphieu);
                if (index != -1)
                {
                    pn1 = ds1.getdsPN()[index]; 
                    break;                      
                }
                cout << "[Lỗi] Mã phiếu không tồn tại" << endl;
            }
            int choice3 = -1;
            while (choice3 != 0)
            {
                clear_display();
                menu_PN();

                if (!readInt("Nhập lựa chọn hàng hóa: ", choice3))
                {
                    stop_display();
                    continue;
                }

                if (choice3 == 0)
                {
                    // if (kho1.save_kho == 0)
                    // {
                    //     cout << "[!] File chưa được lưu." << endl
                    //          << "Lưu file và thoát(Y/y) - Không lưu (Phím bất kỳ): ";
                    //     string yes;
                    //     getline(cin, yes);
                    //     if (yes == "Y" || yes == "y")
                    //     {
                    //         luufile(kho1, "Data\\kho.txt");
                    //         kho1.save_kho = 1;
                    //     }
                    // }
                    break;
                }

                PN_function(pn1, kho1, n1, &ds1,choice3);
                stop_display();
            }
            break;
        }

        case 4:
        {
            int choice4 = -1;
            while (choice4 != 0)
            {
                clear_display();
                menu_DSPN();

                if (!readInt("Nhập lựa chọn hàng hóa: ", choice4))
                {
                    stop_display();
                    continue;
                }

                if (choice4 == 0)
                {
                    // if (kho1.save_kho == 0)
                    // {
                    //     cout << "[!] File chưa được lưu." << endl
                    //          << "Lưu file và thoát(Y/y) - Không lưu (Phím bất kỳ): ";
                    //     string yes;
                    //     getline(cin, yes);
                    //     if (yes == "Y" || yes == "y")
                    //     {
                    //         luufile(kho1, "Data\\kho.txt");
                    //         kho1.save_kho = 1;
                    //     }
                    // }
                    break;
                }

                DsPN_function(ds1, kho1, n1, choice4);
                stop_display();
            }
            break;
        }
        case 5:
            int choice5 = -1;
            clear_display();
            menu_TK();
            readInt("Nhập lựa chọn thống kê: ",choice5);
            TK_function(ds1,pn1,kho1,n1,choice5);
            break;
        case 6:
            clear_display();

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