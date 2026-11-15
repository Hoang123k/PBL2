#include <sstream>
#include "Date.h"
#include "../Header/transfer.h"
using namespace std;
Date::Date() {}
Date::Date(int d, int m, int y) : d(d), m(m), y(y) {}
Date::~Date() {}
int Date::month(int m)
{
    return (m == 4 || m == 6 || m == 9 || m == 11) ? 1 : ((m == 2) ? 0 : -1);
}
int Date::year(int y)
{
    return (y % 4 == 0) ? 1 : 0;
}
Date &Date::operator++()
{
    if (!month(this->m))
    {
        if (year(this->y))
        {
            if (this->d < 29)
                this->d++;
            else
            {
                this->d = 1;
                this->m = 3;
            }
        }
        else
        {
            if (this->d < 28)
                this->d++;
            else
            {
                this->d = 1;
                this->m = 3;
            }
        }
    }
    else if (month(this->m) == 1)
    {
        if (this->d < 30)
            this->d++;
        else
        {
            this->d = 1;
            this->m++;
        }
    }
    else if (month(this->m) == -1)
    {
        if (this->d < 31)
            this->d++;
        else
        {
            if (this->m == 12)
            {
                this->d = 1;
                this->m = 1;
                this->y++;
            }
        }
    }
    return *(this);
}
Date &Date::operator--()
{
    if (!month(this->m))
    {
        if (this->d > 1)
            this->d--;
        else
        {
            this->d = 31;
            this->m = 1;
        }
    }
    else if (month(this->m) == 1)
    {
        if (this->d > 1)
            this->d--;
        else
        {
            this->d = 31;
            this->m--;
        }
    }
    else if (month(this->m) == -1)
    {
        if (this->d > 1)
            this->d--;
        else
        {
            if (this->m == 3)
            {
                if (year(this->y))
                {
                    this->d = 29;
                    this->m = 2;
                }
                else
                {
                    this->d = 28;
                    this->m = 2;
                }
            }
            else if (this->m == 1)
            {
                this->d = 31;
                this->m = 12;
                this->y--;
            }
        }
    }
    return *this;
}

int Date::getd() const
{
    return this->d;
}

int Date::getm() const
{
    return this->m;
}

int Date::gety() const
{
    return this->y;
}
ostream &operator<<(ostream &o, const Date &p)
{   
    string dd,mm;
    (p.d >9 ) ? dd = to_string(p.d) : dd = "0"+to_string(p.d);
    (p.m >9 ) ? mm = to_string(p.m) : mm = "0"+to_string(p.m);
    string s = dd + "/" + mm + "/" + to_string(p.y);

    o << s;
    return o;
}

void Date::setd(int &x)
{
    this->d = x;
}
void Date::setm(int &y)
{
    this->m = y;
}

void Date::sety(int &y)
{
    this->y = y;
}

void Date::checkdate(int& d, int& m, int& y) {
    if (y < 1) {
        throw std::invalid_argument("[Lỗi] Năm phải lớn hơn hoặc bằng 1.");
    }

    if (m < 1 || m > 12) {
        throw std::invalid_argument("[Lỗi] Thắng phải nằm trong khoảng từ 1 đến 12.");
    }

    if (d < 1) {
        throw std::invalid_argument("[Lỗi] Ngày không thể nhỏ hơn 1.");
    }

    if (m == 2) {
        bool isLeap = (year(y) == 1); 
        int maxDay = isLeap ? 29 : 28;
        if (d > maxDay) {
            throw std::invalid_argument("[Lỗi] Tháng 2 năm " + std::to_string(y) + 
                                        " chỉ có tối đa " + std::to_string(maxDay) + " ngày.");
        }
    }
    
    else if (month(m) == 1) {
        if (d > 30) {
            throw std::invalid_argument("[Lỗi] Tháng " + std::to_string(m) + " chỉ có tối đa 30 ngày.");
        }
    }
    
    else if (month(m) == -1) {
        if (d > 31) {
            throw std::invalid_argument("[Lỗi] Tháng " + std::to_string(m) + " chỉ có tối đa 31 ngày.");
        }
    }
}
istream &operator>>(istream &i, Date &p)
{
    string date;
    while (true)
    {
        try
        {
            cout << "Nhập ngày tháng năm (định dạng dd/mm/yyyy): ";
            
            if (!getline(i, date)) {
                break;
            }
            if (date.empty()) continue;

            stringstream ss(date);
            string day, month, year;
            
            if (!getline(ss, day, '/') || !getline(ss, month, '/') || !getline(ss, year)) {
                throw invalid_argument("[Lỗi] Sai định dạng. Vui lòng nhập theo mẫu dd/mm/yyyy.");
            }

            long long ll_d = stringToLL(day);
            long long ll_m = stringToLL(month);
            long long ll_y = stringToLL(year);
            int d = static_cast<int>(ll_d);
            int m = static_cast<int>(ll_m);
            int y = static_cast<int>(ll_y);

            p.checkdate(d, m, y);

            p.setd(d);
            p.setm(m);
            p.sety(y);
            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << " Xin vui lòng nhập lại!\n";
        }
    }
    return i;
}
const Date &Date::operator+=(const int t)
{
    int temp = t;
    if (!temp)
        return *this;
    if (temp > 0)
    {
        while (temp)
        {
            ++*(this);
            temp--;
        }
    }
    if (temp < 0)
    {
        while (temp)
        {
            --*this;
            temp++;
        }
    }
    return *this;
}

const Date Date::operator++(int)
{
    Date temp = *this;
    ++*this;
    return temp;
}

const Date Date::operator--(int)
{
    Date temp = *this;
    --*this;
    return temp;
}

string Date_to_string(Date &date)
{
    string s = "";
    if (date.getd() < 10)
    {
        s += "0";
    }
    s += to_string(date.getd()) + "/";
    if (date.getm() < 10)
    {
        s += "0";
    }
    s += to_string(date.getm()) + "/";
    s += to_string(date.gety());

    return s;
}