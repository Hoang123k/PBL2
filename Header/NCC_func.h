#pragma once

#include <iostream>
#include <string>
#include "qlncc.h"
#include "menu.h"

inline void NCC_function(qlncc &ql, int choice)
{
    int subChoice = -1;

    switch (choice)
    {
    case 1:
        ql.show();
        break;

    case 2:
        ql.add();
        break;

    case 3:
        ql.update();
        break;

    case 4:
        menu_NCC_Sort();
        if (!readInt("Nhap lua chon sap xep: ", subChoice))
        {
            return;
        }

        switch (subChoice)
        {
        case 1:
            ql.sortByMaNCC(ql.getql_ncc(), 0, static_cast<int>(ql.getql_ncc().size()) - 1);
            break;
        case 2:
            ql.sortByTenNCC(ql.getql_ncc(), 0, static_cast<int>(ql.getql_ncc().size()) - 1);
            break;
        case 0:
            return;
        default:
            std::cout << "Lua chon sap xep khong hop le.\n";
            return;
        }
        ql.show();
        break;

    case 5:
        menu_NCC_Search();
        if (!readInt("Nhap lua chon tim kiem: ", subChoice))
        {
            return;
        }

        switch (subChoice)
        {
        case 1:
        {
            std::string ma;
            std::cout << "Nhap ma Nha cung cap can tim: ";
            std::getline(std::cin, ma);
            ql.searchByMaNCC(ma);
            break;
        }
        case 2:
        {
            std::string ten;
            std::cout << "Nhap ten Nha cung cap can tim: ";
            std::getline(std::cin, ten);
            ql.searchByTenNCC(ten);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Lua chon tim kiem khong hop le.\n";
            return;
        }
        break;

    case 6:
    {
        std::string ma;
        std::cout << "Nhap ma Nha cung cap can xoa: ";
        std::getline(std::cin, ma);
        ql.deleteByMaNCC(ma);
        break;
    }

    case 0:
    {
        char luu;
        std::cout << "Ban co muon luu nhung thay doi vao file truoc khi thoat? (Y/N): ";
        std::cin >> luu;
        std::cin.ignore();
        if (toupper(luu) == 'Y')
        {
            luufile(ql, "Data\\ncc.txt");
        }
        return;
    }
    default:
        std::cout << "Lua chon khong hop le.\n";
        break;
    }
}