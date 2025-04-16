#include "DonThuc.h"

DonThuc::DonThuc() : bac(0), heso(0) {}
DonThuc::DonThuc(int b, double h) {bac = b; heso = h;}
DonThuc::~DonThuc(){}

void DonThuc::Nhap(){
    cout << "Nhập bậc: "; cin >> bac;
    cout << "Nhập hệ số: "; cin >> heso;
}

void DonThuc::Xuat(){
    if(heso < 0)
        cout << "(" << heso << ")x^" << bac;
    else if(heso > 0)
        cout << heso << "x^" << bac;
    else    
        return;
}

int DonThuc::getBac(){
    return bac;
}

double DonThuc::getHeSo(){
    return heso;
}

void DonThuc::setBac(int b){
    bac = b;
}

void DonThuc::setHeSo(double h){
    heso = h;
}