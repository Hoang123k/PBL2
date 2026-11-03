#pragma once
#include <string>

class Ncc {
protected:
    std::string loaincc;
    std::string mancc;
    std::string tenncc;
    std::string sdtncc;
    std::string diachincc;
    std::string masothue;

public:
    Ncc();
    virtual ~Ncc();
    Ncc(const std::string& ma, const std::string& ten, const std::string& sdt, const std::string& dc);

    // GETTER
    std::string getloai() const;
    std::string getmancc() const;
    std::string gettenncc() const;
    std::string getsdtncc() const;
    std::string getdiachincc() const;
    std::string getmasothue() const;

    // SETTER
    void setloaincc(const std::string& loai);
    void setmancc(const std::string& ma);
    void settenncc(const std::string& ten);
    void setsdtncc(const std::string& sdt);
    void setdiachincc(const std::string& dc);
    void setmasothue(const std::string& mst);

    virtual void show() const = 0; // Bắt buộc phải có const
};