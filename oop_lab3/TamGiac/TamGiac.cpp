#include "TamGiac.h"

TamGiac::TamGiac(){

}

TamGiac::~TamGiac(){

}

TamGiac::TamGiac(Diem m, Diem n, Diem p){
    A = m; B = n; C = p;
}

void TamGiac::Nhap(){
    cout << "Nhập các đỉnh tam giác: " << endl;
    cout << "Nhập điểm A: "; A.Diem::Nhap();
    cout << "Nhập điểm B: "; B.Diem::Nhap();
    cout << "Nhập điểm C: "; C.Diem::Nhap();
}

void TamGiac::Xuat(){
    cout << "Tọa độ điểm A: "; A.Diem::Xuat();
    cout << "Tọa độ điểm B: "; B.Diem::Xuat();
    cout << "Tọa độ điểm C: "; C.Diem::Xuat();
    cout << endl;
}

double TamGiac::ChuVi(){
    return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);
}

double TamGiac::DienTich(){
    double p = ChuVi() / 2;
    return sqrt(p * (p - A.KhoangCach(B)) * (p - B.KhoangCach(C)) * (p - C.KhoangCach(A)));
}

string TamGiac::KiemTraLoai(){
    cout << "Loại tam giác: ";
    double a = B.KhoangCach(C);
    double b = C.KhoangCach(A);
    double c = A.KhoangCach(B);

    vector<double> arr = {a, b, c};
    sort(arr.begin(), arr.end());

    if(a == b && b == c)
        return "Tam giác đều.";
    else if((a == b || b == c || c == a) && (pow(arr[0], 2) + pow(arr[1], 2) - pow(arr[2], 2)) == 0)
        return "Tam giác vuông cân.";
    else if(a == b || b == c || c == a)
        return "Tam giác cân.";
    else if(pow(arr[0], 2) + pow(arr[1], 2) - pow(arr[2], 2) == 0)
        return "Tam giác vuông.";
    else 
        return "Tam giác thường.";
}

void TamGiac::TinhTien(){
    double x, y;
    cout << "Nhập vector tịnh tiến(x y): "; cin >> x >> y;
    A.Diem::TinhTien(x, y);
    B.Diem::TinhTien(x, y);
    C.Diem::TinhTien(x, y); 
}

void TamGiac::PhongTo(){
    double cx = (A.getX() + B.getX() + C.getX()) / 3;
    double cy = (A.getY() + B.getY() + C.getY()) / 3;

    double tyLe;
    cout << "Nhập tỷ lệ phóng to(thu nhỏ): "; cin >> tyLe;

    A.TinhTien(-cx, -cy);
    B.TinhTien(-cx, -cy);
    C.TinhTien(-cx, -cy);
    
    double newAx = A.getX() * tyLe;
    double newAy = A.getY() * tyLe;
    double newBx = B.getX() * tyLe;
    double newBy = B.getY() * tyLe;
    double newCx = C.getX() * tyLe;
    double newCy = C.getY() * tyLe;
    
    A = Diem(newAx, newAy);
    B = Diem(newBx, newBy);
    C = Diem(newCx, newCy);
    
    A.TinhTien(cx, cy);
    B.TinhTien(cx, cy);
    C.TinhTien(cx, cy);    
}

void TamGiac::Quay(){
    double cx = xTrongTam(A, B, C);
    double cy = yTrongTam(A, B, C);
    
    double goc;
    cout << "Nhập góc quay(radian): "; cin >> goc;
    
    A.TinhTien(-cx, -cy);
    B.TinhTien(-cx, -cy);
    C.TinhTien(-cx, -cy);
    
    double newAx = A.getX() * cos(goc) - A.getY() * sin(goc);
    double newAy = A.getX() * sin(goc) + A.getY() * cos(goc);
    double newBx = B.getX() * cos(goc) - B.getY() * sin(goc);
    double newBy = B.getX() * sin(goc) + B.getY() * cos(goc);
    double newCx = C.getX() * cos(goc) - C.getY() * sin(goc);
    double newCy = C.getX() * sin(goc) + C.getY() * cos(goc);
    
    A = Diem(newAx, newAy);
    B = Diem(newBx, newBy);
    C = Diem(newCx, newCy);
    
    A.TinhTien(cx, cy);
    B.TinhTien(cx, cy);
    C.TinhTien(cx, cy);
}