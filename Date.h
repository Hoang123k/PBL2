#pragma once
#include<iostream>
class Date{
    private:
        int d,m,y;
    public:
        Date();
        Date(int, int, int);
        ~Date();
        int month(int);
        int year(int);

        Date& operator++();
        const Date operator++(int);
        Date& operator--();
        const Date operator--(int);
        const Date& operator+=(const int);
        int getd();
        int getm();
        int gety();
        void  setd(int&);
        void  setm(int&);
        void  sety(int&);

        friend std::ostream& operator<<(std::ostream&, Date&);
        friend std::istream& operator>>(std::istream&, Date&);
};