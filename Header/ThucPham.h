#pragma once
#include "Hanghoa.h"
#include <string>

class ThucPham : public Hanghoa {
private:
    std::string ngayhethan;

public:
    ThucPham();
    ThucPham(const std::string& ma, const std::string& ten, 
             const std::string& loai, const std::string& dvt, 
             int sl, int gia, const std::string& hsd);
    
    
    
    std::string getthuoctinh() const override;
    void setthuoctinh(const std::string&) override;
    void show() override;
};