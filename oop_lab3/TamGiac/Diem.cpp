#include "Diem.h"

Diem::Diem(){
    dx = 0; dy = 0;
}

Diem::~Diem(){
    cout << endl;
}

Diem::Diem(double x, double y){
    dx = x; dy = y;
}

void Diem::Nhap(){
    cin >> dx >> dy;
}

void Diem::Xuat(){
    cout << dx << "; " << dy << endl;
}

void Diem::TinhTien(double x, double y){
    dx += x; dy += y;
}

double Diem::KhoangCach(Diem A){
    return sqrt(pow((A.dx - dx), 2) + pow((A.dy - dy), 2));
}

double Diem::xTrongTam(Diem a, Diem b, Diem c){
    return (a.dx + b.dx + c.dx) / 3;
}

double Diem::yTrongTam(Diem a, Diem b, Diem c){
    return (a.dy + b.dy + c.dy) / 3;
}

double Diem::getX(){
    return dx;
}

double Diem::getY(){
    return dy;
}