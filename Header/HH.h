#pragma once

#include <iostream>
#include <string>
#include "Kho.h"
#include "menu.h"

inline void HH_function(Kho &kho1, int choice1)
{
    int subChoice = -1;

    switch (choice1)
    {
    case 1:
        clear_display();
        kho1.show();
        break;

        // case 2:
        //     clear_display();
        //     kho1.add();
        //     break;

    case 3:
        clear_display();
        kho1.update();
        break;
    case 4:
        while (true)
        {
            clear_display();
            menu_HH_Sort();
            if (!readInt("Nhập lựa chọn sắp xếp: ", subChoice))
            {
                stop_display();
                continue;
            }

            switch (subChoice)
            {
            case 1:
                kho1.sortByMaHang(kho1.getkho(), 0,
                                  static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 2:
                kho1.sortByTenHang(kho1.getkho(), 0,
                                   static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 3:
                kho1.sortByLoaiHang(kho1.getkho(), 0,
                                    static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 4:
                kho1.sortByDonViTinh(kho1.getkho(), 0,
                                     static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 5:
                kho1.sortBySoLuong(kho1.getkho(), 0,
                                   static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 6:
                kho1.sortByDonGia(kho1.getkho(), 0,
                                  static_cast<int>(kho1.getkho().size()) - 1);
                break;
            case 0:
                return;
            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
                return;
            }
            clear_display();
            kho1.show();
            break;
        }
        break;
    case 5:
        while (true)
        {
            clear_display();
            menu_HH_Search();
            if (!readInt("Nhập lựa chọn tìm kiếm: ", subChoice))
            {
                stop_display();
                continue;
            }

            switch (subChoice)
            {
            case 1:
            {
                clear_display();
                string mahang;
                cout << "Nhập mã hàng cần tìm: ";
                getline(cin, mahang);

                int index = kho1.searchByMaHang(mahang);
                if (index >= 0)
                {
                    kho1.getkho()[index]->show();
                }
                break;
            }
            case 2:
            {
                clear_display();
                string tenhang;
                cout << "Nhập từ khóa cần tìm: ";
                getline(cin, tenhang);
                kho1.searchByTenHang(tenhang);
                break;
            }
            case 3:
            {
                clear_display();
                string loaihang;
                cout << "Nhập từ khóa cần tìm: ";
                getline(cin, loaihang);
                kho1.searchByLoaiHang(loaihang);
                break;
            }
            case 4:
            {
                clear_display();
                string donvitinh;
                cout << "Nhập từ khóa cần tìm: ";
                getline(cin, donvitinh);
                kho1.searchByDonViTinh(donvitinh);
                break;
            }
            case 0:
                return;

            default:
                cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
                return;
            }
            break;
        }
        break;
    // case 6:
    // {
    //      string mahang;
    //      cout << "Nhập mã hàng cần xóa: ";
    //      getline( cin, mahang);
    //     kho1.deleteByMaHang(mahang);
    //     break;
    // }
    case 7:
        clear_display();
        kho1.thanhtien();
        break;
    case 8:
        clear_display();
        luufile(kho1, "Data\\kho.txt");
        kho1.save_kho = 1;
        break;
    case 0:
        return;

    default:
        clear_display();
        cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
        break;
    }
}