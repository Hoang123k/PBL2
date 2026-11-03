#pragma once
#include <iostream>
#include <string>

class Hanghoa
{
protected:
    std::string mahang, tenhang, loaihang, donvitinh;
    long long soluong, dongia;

public:
    Hanghoa();
    virtual ~Hanghoa();
    Hanghoa(const std::string&, const std::string&,
            const std::string&, const std::string&,
            long long, long long);

    std::string getmahang() const;
    std::string gettenhang() const;
    std::string getloaihang() const;
    std::string getdonvitinh() const;
    long long getsoluong() const;
    long long getdongia() const;
    virtual std::string getthuoctinh() const = 0;

    void setmahang(const std::string&);
    void settenhang(const std::string&);
    void setloaihang(const std::string&);
    void setdonvitinh(const std::string&);
    void setsoluong(long long);
    void setdongia(long long);
    virtual void setthuoctinh(const std::string&) = 0;

    virtual void show() = 0;
};