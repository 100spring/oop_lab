#include "GiaoDichTienTe.h"

void GiaoDichTienTe::NhapTienTe(){
    Trade::Nhap();
    cout << "Nhập loại tiền tệ(VND/USD/EUR): ";
    cin.ignore();
    getline(cin, loaiTienTe);
    if(loaiTienTe == "VND")
        tiGia = 1;
    else if(loaiTienTe == "USD")
        tiGia = 25000;
    else 
        tiGia = 30000;
}
 
void GiaoDichTienTe::XuatTienTe(){
    Trade::Xuat();
    cout << "Loại tiền tệ: " << loaiTienTe << endl;
    cout << "Tỉ giá: " << tiGia << endl;
}

double GiaoDichTienTe::ThanhTien(){
    return soLuong*donGia*tiGia;
}

string GiaoDichTienTe::getType(){
    return loaiTienTe;
}