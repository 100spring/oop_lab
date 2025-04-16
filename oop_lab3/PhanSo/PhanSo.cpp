#include "PhanSo.h"

int ucln(int a, int b){
    a = abs(a);
    b = abs(b);
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

PhanSo::PhanSo(){

}

PhanSo::PhanSo(int x, int y){
    tu = x; mau = y;
}

PhanSo::~PhanSo(){

}

void PhanSo::Nhap(){
    cin >> tu >> mau;
}

void PhanSo::Xuat(){
    cout << tu << "/" << mau;
}

int PhanSo::getTu(){
    return tu;
}

int PhanSo::getMau(){
    return mau;
}

PhanSo PhanSo::Cong(PhanSo a){
    PhanSo temp;
    temp.tu = tu*a.mau + mau*a.tu;
    temp.mau = mau*a.mau;
    return temp;
}

void PhanSo::RutGon(){
    if(mau < 0){
        tu = -tu;
        mau = -mau;
    }
    int d = ucln(tu, mau);
    tu /= d;
    mau /= d;
}

bool PhanSo::SoSanhLonHon(PhanSo a){
    if((tu*a.mau - mau*a.tu) > 0)
        return true;
    return false;
}