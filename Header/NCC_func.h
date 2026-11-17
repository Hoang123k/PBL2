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

        // case 2:
        //     ql.add();
        //     break;

    case 3:
        ql.update();
        break;

    case 4:
        while (true)
        {
            menu_NCC_Sort();
            if (!readInt("Nhap lua chon sap xep: ", subChoice))
            {
                stop_display();
                continue;
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
                cout << "Lua chon sap xep khong hop le.\n";
                return;
            }
            ql.show();
            break;
        }
        break;

    case 5:
        while (true)
        {
            menu_NCC_Sort();
            if (!readInt("Nhap lua chon sap xep: ", subChoice))
            {
                stop_display();
                continue;
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
                cout << "Lua chon sap xep khong hop le.\n";
                return;
            }
            ql.show();
            break;
        }
        break;

        // case 6:
        // {
        //      string ma;
        //      cout << "Nhap ma Nha cung cap can xoa: ";
        //      getline( cin, ma);
        //     ql.deleteByMaNCC(ma);
        //     break;
        // }

    case 0:
    {
        char luu;
        cout << "Ban co muon luu nhung thay doi vao file truoc khi thoat? (Y/N): ";
        cin >> luu;
        cin.ignore();
        if (toupper(luu) == 'Y')
        {
            luufile(ql, "Data\\ncc.txt");
        }
        return;
    }
    default:
        cout << "Lua chon khong hop le.\n";
        break;
    }
}