#pragma once
#include "Ncc.h"
#include <vector>
#include <memory>
#include <string>

class qlncc
{
public:
    int soluong_ncc;
    std::vector<std::unique_ptr<Ncc>> ql_ncc;

    qlncc();
    ~qlncc();

    friend void docfile(qlncc &ql, const std::string &filename);
    void show() const;

    // Them
    void add();

    // Update
    void update();

    // sort
    void sortByMaNCC(std::vector<std::unique_ptr<Ncc>> &list_ncc, int low, int high);
    void sortByTenNCC(std::vector<std::unique_ptr<Ncc>> &list_ncc, int low, int high);

    // search
    void searchByMaNCC(const std::string &ma) const;
    void searchByTenNCC(const std::string &ten) const;

    // delete
    void deleteByMaNCC(const std::string &ma);
};