#include "NhanVien.h"

NhanVien::NhanVien(){}
NhanVien::~NhanVien(){}

void NhanVien::Nhap(){
    cin.ignore();
    cout << "Nhập mã nhân viên: "; getline(cin, ma);
    cout << "Nhập họ tên: "; getline(cin, ten);
    cout << "Nhập ngày sinh: "; getline(cin, ngaysinh);
    cout << "Nhập lương: "; cin >> luong;
}

void NhanVien::Xuat(){
    cout << "Mã nhân viên: " << ma << endl;
    cout << "Họ tên: " << ten << endl;
    cout << "Ngày sinh: " << ngaysinh << endl;
    cout << "Lương: " << luong << endl;
}

double NhanVien::getLuong(){
    return luong;
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