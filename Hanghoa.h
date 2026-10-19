#pragma once
#include<iostream>
using namespace std;
class Hanghoa{
    private:
        string mahang;
        string tenhang;
        string loaihang;
        string donvitinh;
        int soluong;
        int dongia;
    public:
        Hanghoa();
        ~Hanghoa();
        Hanghoa(const string, const string, 
            const string, const string,
            const int,const int);
        
        string getmahang();
        string gettenhang();
        string getloaihang();
        string getdonvitinh();
        int getsoluong();
        int getdongia();

        void setmahang(string);
        void settenhang(string);
        void setloaihang(string);
        void setdonvitinh(string);
        void setsoluong(int);
        void setdongia(int);

        void show();
};