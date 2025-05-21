#include "SoPhuc.h"

istream& operator>>(istream& input, SoPhuc& a){
    cout << "Nhập phần thực: "; input >> a.phan_thuc;
    cout << "Nhập phần ảo: "; input >> a.phan_ao;
    return input;
}

ostream& operator<<(ostream& output, SoPhuc& a){
    output << a.phan_thuc;
    if(a.phan_ao >= 0)
        output << " + " << a.phan_ao << "i";
    else 
        output << " - " << -a.phan_ao << "i";
    return output;
}

SoPhuc SoPhuc::operator+(SoPhuc& b){
    SoPhuc temp;
    temp.phan_thuc = phan_thuc + b.phan_thuc;
    temp.phan_ao = phan_ao + b.phan_ao;
    return temp;
}

SoPhuc SoPhuc::operator-(SoPhuc& b){
    SoPhuc temp;
    temp.phan_thuc = phan_thuc - b.phan_thuc;
    temp.phan_ao = phan_ao - b.phan_ao;
    return temp;
}

SoPhuc SoPhuc::operator*(SoPhuc& b){
    SoPhuc temp;
    temp.phan_thuc = phan_thuc*b.phan_thuc - phan_ao*b.phan_ao;
    temp.phan_ao = phan_thuc*b.phan_ao + phan_ao*b.phan_thuc;
    return temp;
}

SoPhuc SoPhuc::operator/(SoPhuc& b){
    SoPhuc temp;
    temp.phan_thuc = (phan_thuc*b.phan_thuc - phan_ao*b.phan_ao) / (pow(b.phan_thuc, 2) + pow(b.phan_ao, 2));
    temp.phan_ao = (phan_ao*b.phan_thuc - phan_thuc*b.phan_ao) / (pow(b.phan_thuc, 2) + pow(b.phan_ao, 2));
    return temp;
}

bool SoPhuc::operator==(SoPhuc& b){
    return phan_thuc = b.phan_thuc && phan_ao == b.phan_ao;
}

bool SoPhuc::operator!=(SoPhuc& b){
    return phan_thuc != b.phan_thuc || phan_ao != b.phan_ao;
}