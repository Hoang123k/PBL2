#pragma once
#include "Ncc.h"
#include <vector>
#include <memory>
#include <string>

class qlncc {
public:
    int soluong_ncc;
    std::vector<std::unique_ptr<Ncc>> ql_ncc;

    qlncc();
    ~qlncc();

    friend void docfile(qlncc& ql, const std::string& filename);
    void show() const;

    // Them
    void add();
    // update
    void update();
    // sort
    void sortByMaHang(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    void sortByTenHang(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    void sortByLoaiHang(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    void sortByDonViTinh(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    void sortBySoLuong(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    void sortByDonGia(std::vector<std::unique_ptr<Ncc>>& kho, int low, int high);
    // search
    int  searchByMaHang(const std::string& ma) const;
    void searchByTenHang(const std::string& ten) const;
    void searchByLoaiHang(const std::string& loai) const;
    void searchByDonViTinh(const std::string& donvitinh) const;
    // delete
    void deleteByMaHang(const std::string& mahang);
};