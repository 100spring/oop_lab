#include "GiaoDichDat.h"

void GiaoDichDat::Nhap(){
    GiaoDich::Nhap();
    cout << "Nhập loại đất(A/B/C): "; 
    cin.ignore();
    getline(cin, loaidat);
}

void GiaoDichDat::Xuat(){
    GiaoDich::Xuat();
    cout << "Loại đất: " << loaidat << endl;
}

double GiaoDichDat::ThanhTien(){
    if(loaidat == "A")
        return dientich * dongia * 1.5;
    else 
        return dientich * dongia;
}