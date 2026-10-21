#pragma once
#include<iostream>
using namespace std;
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
        int getd() const;
        int getm() const;
        int gety() const;
        void  setd(int&);
        void  setm(int&);
        void  sety(int&);
        
        friend std::ostream& operator<<(std::ostream&, const Date&);
        friend std::istream& operator>>(std::istream&, Date&);
};