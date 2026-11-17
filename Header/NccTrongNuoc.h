#pragma once
#include "Ncc.h"
#include <string>

class NccTrongNuoc : public Ncc
{
    std::string tinhthanh;

public:
    NccTrongNuoc();
    NccTrongNuoc(const std::string &ma, const std::string &ten, const std::string &sdt, const std::string &dc, const std::string &mst);
    void show() const override;
    std::string getmasothue() const;
    std::string gettinhthanh() const;
    void nhap_thong_tin() override;
};
