#pragma once
#include "Hanghoa.h"
#include <vector>
#include <memory>
#include <string>

class Kho {
public:
    int soluonghang;
    std::vector<std::unique_ptr<Hanghoa>> kho;

    Kho();
    ~Kho();
    
    friend void docfile(Kho& k, const std::string& filename);
    void show() const;
    // Them
    void add();
    // update
    void update();
    // sort
    void sortByMaHang(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    void sortByTenHang(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    void sortByLoaiHang(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    void sortByDonViTinh(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    void sortBySoLuong(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    void sortByDonGia(std::vector<std::unique_ptr<Hanghoa>>& kho, int low, int high);
    // search
    int  searchByMaHang(const std::string& ma) const;
    void searchByTenHang(const std::string& ten) const;
    void searchByLoaiHang(const std::string& loai) const;
    void searchByDonViTinh(const std::string& donvitinh) const;
    // delete
    void deleteByMaHang(const std::string& mahang);
};