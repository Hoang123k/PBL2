#pragma once
#include "Hanghoa.h"
#include <string>

class VatTu : public Hanghoa {
private:
    std::string chatlieu;

public:
    VatTu();
    VatTu(const std::string& ma, const std::string& ten, 
          const std::string& loai, const std::string& dvt, 
          int sl, int gia, const std::string& cl);

    std::string getthuoctinh() const override;
    void setthuoctinh(const std::string&) override;
    void show() override;
};