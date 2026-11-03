#pragma once

#include <iostream>
#include <string>
#include "Kho.h"
#include "menu.h"

inline void HH_function(Kho& kho1, int choice1) {
    int subChoice = -1;

    switch (choice1) {
    case 1:
        kho1.show();
        break;

    case 2:
        kho1.add();
        break;

    case 3:
        kho1.update();
        break;

    case 4:
        menu_HH_Sort();
        if (!readInt("Nhap lua chon sap xep: ", subChoice)) {
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
            std::cout << "Lua chon sap xep khong hop le.\n";
            return;
        }

        kho1.show();
        break;

    case 5:
        menu_HH_Search();
        if (!readInt("Nhap lua chon tim kiem: ", subChoice)) {
            return;
        }

        switch (subChoice) {
        case 1: {
            std::string mahang;
            std::cout << "Nhap ma hang hoa can tim: ";
            std::getline(std::cin, mahang);

            int index = kho1.searchByMaHang(mahang);
            if (index >= 0) {
                kho1.kho[index]->show();
            }
            break;
        }
        case 2: {
            std::string tenhang;
            std::cout << "Nhap ten hang hoa can tim: ";
            std::getline(std::cin, tenhang);
            kho1.searchByTenHang(tenhang);
            break;
        }
        case 3: {
            std::string loaihang;
            std::cout << "Nhap loai hang hoa can tim: ";
            std::getline(std::cin, loaihang);
            kho1.searchByLoaiHang(loaihang);
            break;
        }
        case 4: {
            std::string donvitinh;
            std::cout << "Nhap don vi tinh can tim: ";
            std::getline(std::cin, donvitinh);
            kho1.searchByDonViTinh(donvitinh);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Lua chon tim kiem khong hop le.\n";
            return;
        }
        break;

    case 6: {
        std::string mahang;
        std::cout << "Nhap ma hang hoa can xoa: ";
        std::getline(std::cin, mahang);
        kho1.deleteByMaHang(mahang);
        break;
    }

    case 0:
        return;

    default:
        std::cout << "Lua chon khong hop le.\n";
        break;
    }
}