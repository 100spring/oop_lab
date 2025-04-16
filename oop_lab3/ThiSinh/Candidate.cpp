#include "Candidate.h"

Candidate::Candidate(){}
Candidate::~Candidate(){}

void Candidate::Nhap(){
    cin.ignore();
    cout << "Nhập mã thí sinh: "; getline(cin, id);
    cout << "Nhập họ tên thí sinh: "; getline(cin, ten);
    cout << "Nhập ngày tháng năm sinh(DD MM YYYY): "; getline(cin, ngaysinh);
    cout << "Nhập lần lượt điểm toán, văn, anh: "; cin >> diemToan >> diemVan >> diemAnh; 
}

double Candidate::getDiemTB(){
    return (diemToan + diemVan + diemAnh)/3;
}

void Candidate::Xuat(){
    cout << "Mã thí sinh: " << id << endl;
    cout << "Họ tên thí sinh: " << ten << endl;
    cout << "Ngày tháng năm sinh: " << ngaysinh << endl;
    cout << "Tổng điểm: " << getDiemTB() << endl;
}