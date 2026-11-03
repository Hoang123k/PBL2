#include "Ncc.h"

Ncc::Ncc() : loaincc(""), mancc(""), tenncc(""), sdtncc(""), diachincc(""), masothue("") {}

Ncc::~Ncc() {}

Ncc::Ncc(const std::string& ma, const std::string& ten, const std::string& sdt, const std::string& dc)
    : loaincc(""), mancc(ma), tenncc(ten), sdtncc(sdt), diachincc(dc), masothue("") {}

// GETTER
std::string Ncc::getloai() const { return loaincc; }
std::string Ncc::getmancc() const { return mancc; }
std::string Ncc::gettenncc() const { return tenncc; }
std::string Ncc::getsdtncc() const { return sdtncc; }
std::string Ncc::getdiachincc() const { return diachincc; }
std::string Ncc::getmasothue() const { return masothue; }

// SETTER
void Ncc::setloaincc(const std::string& loai) { loaincc = loai; }
void Ncc::setmancc(const std::string& ma) { mancc = ma; }
void Ncc::settenncc(const std::string& ten) { tenncc = ten; }
void Ncc::setsdtncc(const std::string& sdt) { sdtncc = sdt; }
void Ncc::setdiachincc(const std::string& dc) { diachincc = dc; }
void Ncc::setmasothue(const std::string& mst) { masothue = mst; }