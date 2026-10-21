#include "Kho.h"
#include "Dsphieunhap.h"
#include "qlncc.h"
void menu();
int main(){
    qlncc n1;
    Kho kho1;
    Phieunhap pn1;
    Dsphieunhap ds1; 
    kho1.soluonghang = 2;
    docfile(kho1,"kho.txt");
    kho1.show();
    docfile(n1,"ncc.txt");
    n1.show();
    docfile(pn1,"phieunhap.txt");
    pn1.show();
    docfile(ds1,"dspn.txt");
    ds1.show();
    return 0;
}
void menu(){
    cout << "Show 1 hang hoa" << endl
         << "Show file hang hoa" << endl
         << "Show 1 nha cung cap" << endl
         << "Show file nha cung cap" << endl
         << "Show 1 san pham trong 1 phieu nhap" << endl
         << "Show san pham trong phieu nhap" << endl
         << "Show toan bo phieu nhap"<< endl;
}