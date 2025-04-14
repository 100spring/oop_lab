#include "SoPhuc.h"

void soPhuc::Nhap(){
    cout << "Nhập phần thực: "; cin >> iThuc;
    cout << "Nhập phần ảo: "; cin >> iAo;
}

void soPhuc::Xuat(){
    if(iAo > 0)
        cout << iThuc << " + " << iAo << "i" << endl;
    else if(iAo < 0)
        cout << iThuc << " - " << abs(iAo) << "i" << endl;
    else
        cout << iThuc << endl;
}

soPhuc soPhuc::Tong(soPhuc a, soPhuc b){
    soPhuc temp;
    temp.iThuc = a.iThuc + b.iThuc;
    temp.iAo = a.iAo + b.iAo;
    return temp;
}

soPhuc soPhuc::Hieu(soPhuc a, soPhuc b){
    soPhuc temp;
    temp.iThuc = a.iThuc - b.iThuc;
    temp.iAo = a.iAo - b.iAo;
    return temp;
}

soPhuc soPhuc::Tich(soPhuc a, soPhuc b){
    soPhuc temp;
    temp.iThuc = a.iThuc*b.iThuc - a.iAo*b.iAo;
    temp.iAo = a.iThuc*b.iAo + b.iThuc*a.iAo;
    return temp;
}

soPhuc soPhuc::Thuong(soPhuc a, soPhuc b){
    soPhuc temp;
    temp.iThuc = (a.iThuc*b.iThuc + a.iAo*b.iAo) / (pow(a.iAo, 2)+pow(b.iAo, 2));
    temp.iAo = (a.iAo*b.iThuc - a.iThuc*b.iAo) / (pow(a.iAo, 2)+pow(b.iAo, 2));
    return temp;
}