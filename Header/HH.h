#pragma once

#include <iostream>
#include <string>
#include "Kho.h"
#include "menu.h"

inline void HH_function(Kho& kho1, int choice1) {
    int subChoice = -1;

    switch (choice1) {
    case 1:
        clear_display();
        kho1.show();
        break;

    case 2:
        clear_display();
        kho1.add();
        break;

    case 3:
        clear_display();
        kho1.update();
        break;
    case 4:
        clear_display();
        menu_HH_Sort();
        if (!readInt("Nhập lựa chọn sắp xếp: ", subChoice)) {
            return;
        }

        switch (subChoice) {
        case 1:
            kho1.sortByMaHang(kho1.kho, 0,
                              static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 2:
            kho1.sortByTenHang(kho1.kho, 0,
                               static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 3:
            kho1.sortByLoaiHang(kho1.kho, 0,
                                static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 4:
            kho1.sortByDonViTinh(kho1.kho, 0,
                                 static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 5:
            kho1.sortBySoLuong(kho1.kho, 0,
                               static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 6:
            kho1.sortByDonGia(kho1.kho, 0,
                              static_cast<int>(kho1.kho.size()) - 1);
            break;
        case 0:
            return;
        default:
            std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
            return;
        }
        clear_display();
        kho1.show();
        break;

    case 5:
        clear_display();
        menu_HH_Search();
        if (!readInt("Nhập lựa chọn tìm kiếm: ", subChoice)) {
            return;
        }

        switch (subChoice) {
        case 1: {
            clear_display();
            std::string mahang;
            std::cout << "Nhập mã hàng cần tìm: ";
            std::getline(std::cin, mahang);

            int index = kho1.searchByMaHang(mahang);
            if (index >= 0) {
                kho1.kho[index]->show();
            }
            break;
        }
        case 2: {
            clear_display();
            std::string tenhang;
            std::cout << "Nhập từ khóa cần tìm: ";
            std::getline(std::cin, tenhang);
            kho1.searchByTenHang(tenhang);
            break;
        }
        case 3: {
            clear_display();
            std::string loaihang;
            std::cout << "Nhập từ khóa cần tìm: ";
            std::getline(std::cin, loaihang);
            kho1.searchByLoaiHang(loaihang);
            break;
        }
        case 4: {
            clear_display();
            std::string donvitinh;
            std::cout << "Nhập từ khóa cần tìm: ";
            std::getline(std::cin, donvitinh);
            kho1.searchByDonViTinh(donvitinh);
            break;
        }
        case 0:
            return;
            
        default:
            std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
            return;
        }
        break;

    case 6: {
        std::string mahang;
        std::cout << "Nhập mã hàng cần xóa: ";
        std::getline(std::cin, mahang);
        kho1.deleteByMaHang(mahang);
        break;
    }
    case 7:
        clear_display();
        kho1.thanhtien();
        break;
    case 8:
        clear_display();
        luufile(kho1,"Data\\kho.txt");
        kho1.save_kho = 1;
        break;
    case 0:
        return;

    default:
    clear_display();
        std::cout << "[Lỗi] Lựa chọn không hợp lệ.\n";
        break;
    }
}