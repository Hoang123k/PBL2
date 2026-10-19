#include "Date.h"
using namespace std;
Date::Date(){}
Date::Date(int d, int m, int y) : d(d),m(m),y(y){}
Date::~Date(){}
int Date::month(int m){
    return (m==4 || m==6 || m==9 || m==11) ? 1 : ((m==2) ? 0 : -1);
}
int Date::year(int y){
    return (y%4 == 0) ? 1 : 0;
}
Date& Date::operator++(){
    if(!month(this->m)){
        if(year(this->y)){
            if(this->d < 29) this->d++;
            else {this->d = 1; this->m =3;}
        }
        else{
            if(this->d < 28) this->d++;
            else {this->d = 1; this->m =3;}
        }
    }
    else if (month(this->m)==1)
    {
        if(this->d < 30) this->d++;
        else {this->d = 1; this->m++;}
    }
    else if (month(this->m)==-1)
    {
        if(this->d < 31) this->d++;
        else {
            if(this->m == 12){
                this->d =1; this->m = 1; this->y++;
            }
        }
    }    
    return *(this);
}
Date& Date::operator--(){
    if(!month(this->m)){
        if(this->d > 1) this->d--;
        else {this->d = 31; this->m =1;}
    }
    else if (month(this->m)==1)
    {
        if(this->d > 1) this->d--;
        else {this->d = 31; this->m--;}
    }
    else if (month(this->m)==-1)
    {
        if(this->d > 1) this->d--;
        else {
            if(this->m == 3){
                if(year(this->y)){
                    this->d =29; this->m = 2;
                }
                else {this->d =28; this->m = 2;}
            }
            else if (this->m ==1)
            {
                this->d = 31; this->m = 12; this->y--;
            }
        }
    }    
    return *this;
}


int Date::getd(){
    return this->d;
}

int Date::getm(){
    return this->m;
}

int Date::gety(){
    return this->y;
}
ostream& operator<< (ostream& o, Date& p){
    o << p.getd() << "/" << p.getm() << "/" << p.gety(); 
    return o;
}

void Date::setd(int& x){
    this->d = x;
}
void Date::setm(int& y){
    this->m = y;
}

void Date::sety(int& y){
    this->y = y;
}

istream& operator>> (istream& i, Date& p) {
    int d, m, y;
    
    cout << "Ngay=";
    i >> d;
    cout << "Thang=";
    i >> m;
    cout << "Nam=";
    i >> y;
    p.setd(d);
    p.setm(m);
    p.sety(y);
    return i;
}

 const Date& Date::operator+=(const int t){
    int temp =t;
    if(!temp) return *this;
    if(temp>0){
        while(temp){
            ++*(this);
            temp--;
        }
    }
    if(temp<0){
        while(temp){
            --*this;
            temp++;
        }
    }
    return *this;
}

const Date Date::operator++(int){
    Date temp = *this;
    ++*this;
    return temp;
}

const Date Date::operator--(int){
    Date temp = *this;
    --*this;
    return temp;
}