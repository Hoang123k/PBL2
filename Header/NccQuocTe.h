#pragma once
#include "Ncc.h"
#include <string>

class NccQuocTe : public Ncc {
private:
    std::string quocgia;
public:
    NccQuocTe();
    NccQuocTe(const std::string& ma, const std::string& ten, const std::string& sdt, const std::string& dc, const std::string& mst, const std::string& qg);
    void show() const override; // Thêm const ở đây
};