#include "Kho.h"
#include "Dsphieunhap.h"
#include "Ncc.h"
#include "Chitietphieunhap.h"
int main(){
    Ncc n1;
    Kho kho1;
    kho1.soluonghang = 2;
    Hanghoa h1("HH01","Banh mi","Thuc pham","O",20,30000);
    kho1.kho.push_back(h1);
    Hanghoa h2("HH02","Mi tom","Thuc pham","Goi",10,8000);
    kho1.kho.push_back(h2);
    kho1.show();
    return 0;
}