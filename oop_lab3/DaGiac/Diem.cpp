#include "Diem.h"

Diem::Diem(){

}

Diem::~Diem(){
    
}

void Diem::Nhap(){
    cin >> dx >> dy;
}

void Diem::Xuat(){
    cout << dx << " " << dy;
}

double Diem::KhoangCach(Diem a){
    return sqrt(pow((dx - a.dx), 2) + pow((dy-a.dy), 2));
}

void Diem::TinhTien(double x, double y){
    dx += x;
    dy += y;
}

double Diem::getX(){
    return dx;
}

double Diem::getY(){
    return dy;
}