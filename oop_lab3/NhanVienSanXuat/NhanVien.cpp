#include "NhanVien.h"

NhanVien::NhanVien(){}
NhanVien::~NhanVien(){}

void NhanVien::Nhap(){
    cin.ignore();
    cout << "Nhập mã nhân viên: "; getline(cin, ma);
    cout << "Nhập họ tên nhân viên: "; getline(cin, ten);
    cout << "Nhập ngày sinh: "; getline(cin, ngaysinh);
    cout << "Nhập số sản phẩm làm được: "; cin >> sanpham;
    cout << "Nhập đơn giá sản phẩm: "; cin >> dongia;
}

void NhanVien::Xuat(){
    cout << "Mã nhân viên: " << ma << endl;
    cout << "Họ tên nhân viên: " << ten << endl;
    cout << "Ngày sinh: " << ngaysinh;
    cout << "Lương theo sản phẩm: " << sanpham*dongia << endl;
}

double NhanVien::getLuong(){
    return sanpham*dongia;
}

int NhanVien::getTuoi(){
    int current = 2025;
    int n = ngaysinh.size();
    string chuoiNamSinh;
    
    for(int i = n-4; i < n; i++){
        chuoiNamSinh[i-n+4] = ngaysinh[i];
    }

    int namSinh = stoi(chuoiNamSinh);
    return current-namSinh;
}