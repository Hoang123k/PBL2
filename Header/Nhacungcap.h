#pragma once

#include <iostream>
#include <string>
#include "qlncc.h"
#include "menu.h"

inline void NCC_function(qlncc& ncc, int choice1) {
    int subChoice = -1;

    switch (choice1) {
    case 1:
        ncc.show();
        break;

    case 2:
        ncc.add();
        break;

    case 3:
        ncc.update();
        break;

    case 4:
        menu_HH_Sort();
        if (!readInt("Nhap lua chon sap xep: ", subChoice)) {
            return;
        }

        switch (subChoice) {
        case 1:
            ncc.sortByMaHang(ncc.ql_ncc, 0,
                              static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 2:
            ncc.sortByTenHang(ncc.ql_ncc, 0,
                               static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 3:
            ncc.sortByLoaiHang(ncc.ql_ncc, 0,
                                static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 4:
            ncc.sortByDonViTinh(ncc.ql_ncc, 0,
                                 static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 5:
            ncc.sortBySoLuong(ncc.ql_ncc, 0,
                               static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 6:
            ncc.sortByDonGia(ncc.ql_ncc, 0,
                              static_cast<int>(ncc.ql_ncc.size()) - 1);
            break;
        case 0:
            return;
        default:
            std::cout << "Lua chon sap xep ql_nccng hop le.\n";
            return;
        }

        ncc.show();
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

            int index = ncc.searchByMaHang(mahang);
            if (index >= 0) {
                ncc.ql_ncc[index]->show();
            }
            break;
        }
        case 2: {
            std::string tenhang;
            std::cout << "Nhap ten hang hoa can tim: ";
            std::getline(std::cin, tenhang);
            ncc.searchByTenHang(tenhang);
            break;
        }
        case 3: {
            std::string loaihang;
            std::cout << "Nhap loai hang hoa can tim: ";
            std::getline(std::cin, loaihang);
            ncc.searchByLoaiHang(loaihang);
            break;
        }
        case 4: {
            std::string donvitinh;
            std::cout << "Nhap don vi tinh can tim: ";
            std::getline(std::cin, donvitinh);
            ncc.searchByDonViTinh(donvitinh);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Lua chon tim kiem ql_nccng hop le.\n";
            return;
        }
        break;

    case 6: {
        std::string mahang;
        std::cout << "Nhap ma hang hoa can xoa: ";
        std::getline(std::cin, mahang);
        ncc.deleteByMaHang(mahang);
        break;
    }

    case 0:
        return;

    default:
        std::cout << "Lua chon ql_nccng hop le.\n";
        break;
    }
}