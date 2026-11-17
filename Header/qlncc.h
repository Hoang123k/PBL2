#pragma once
#include "Ncc.h"
#include <vector>
#include <memory>
#include <string>

class qlncc
{
    int soluong_ncc;
    std::vector<std::unique_ptr<Ncc>> ql_ncc;
public:

    qlncc();
    ~qlncc();

    friend void docfile(qlncc &ql, const std::string &filename);
    friend void luufile(qlncc &ql, const std::string &filename);
    void show() const;

    // Getter
    int& getsoluongncc();
    std::vector<std::unique_ptr<Ncc>>& getql_ncc();

    // Setter
    void setsoluongncc(const int& sl);

    int get_index_mancc(const std::string& ma) const ;
    // Them
    void add(const std::string&);

    // Update
    void update();

    // sort
    void sortByMaNCC(std::vector<std::unique_ptr<Ncc>> &list_ncc, int low, int high);
    void sortByTenNCC(std::vector<std::unique_ptr<Ncc>> &list_ncc, int low, int high);
    void sortByLoaiNCC(std::vector<std::unique_ptr<Ncc>> &list_ncc, int low, int high);
    // search
    int searchByMaNCC(const std::string &ma) const;
    void searchByTenNCC(const std::string &ten) const;
    void searchByLoaiNCC(const std::string &loai) const;
    // delete
    void deleteByMaNCC(const std::string &ma);


  
};