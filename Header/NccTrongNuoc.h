#pragma once
#include "Ncc.h"
#include <string>

class NccTrongNuoc : public Ncc {
public:
    NccTrongNuoc();
    NccTrongNuoc(const std::string& ma, const std::string& ten, const std::string& sdt, const std::string& dc, const std::string& mst);
    void show() const override; // Thêm const ở đây
};