#include "DaGiac.h"

DaGiac::DaGiac(){

}

DaGiac::~DaGiac(){

}

void DaGiac::Nhap(){
    int soGoc;
    cout << "Nhập số góc của đa giác: "; cin >> soGoc;
    GocDaGiac.resize(soGoc);

    cout << "Nhập tọa độ các góc của đa giác:" << endl;
    for(int i = 0; i < soGoc; i++){
        GocDaGiac[i].Nhap();
    }
    cout << endl;
}

void DaGiac::Xuat(){
    cout << "Tọa độ các góc của đa giác:" << endl;
    for(int i = 0; i < GocDaGiac.size(); i++){
        cout << "Góc thứ " << i+1 << ": ";
        GocDaGiac[i].Xuat();
        cout << endl;
    }
    cout << endl;
}

double DaGiac::ChuVi(){
    double chuVi = 0;

    for(int i = 0; i < GocDaGiac.size(); i++){
        int j = (i+1) % GocDaGiac.size();
        chuVi +=GocDaGiac[i].KhoangCach(GocDaGiac[j]);
    }

    return chuVi;
}

double DaGiac::DienTich(){
    double canh = GocDaGiac[0].KhoangCach(GocDaGiac[1]);
    return GocDaGiac.size() * pow(canh, 2) * (1/tan(M_PI/GocDaGiac.size())) / 4;
}

void DaGiac::TinhTien(){
    double x, y;
    cout << "Nhập vector tịnh tiến: "; cin >> x >> y;
    for(int i = 0; i < GocDaGiac.size(); i++){
        GocDaGiac[i].TinhTien(x, y);
    }
}

void DaGiac::PhongTo(){
    int tyLe;
    cout << "Nhập tỷ lệ phóng to(thu nhỏ): "; cin >> tyLe;

    double cx = 0, cy = 0;
    for(int i = 0; i < GocDaGiac.size(); i++){
        cx += GocDaGiac[i].getX();
        cy += GocDaGiac[i].getY();
    }
    cx /= GocDaGiac.size();
    cy /= GocDaGiac.size();

    for(int i = 0; i < GocDaGiac.size(); i++){
        GocDaGiac[i].TinhTien(-cx, -cy);
        GocDaGiac[i] = Diem(GocDaGiac[i].getX()*tyLe, GocDaGiac[i].getY()*tyLe);
        GocDaGiac[i].TinhTien(cx, cy);
    }
}

void DaGiac::Quay(){
    double cx = 0, cy = 0;
    for(int i = 0; i < GocDaGiac.size(); i++){
        cx += GocDaGiac[i].getX();
        cy += GocDaGiac[i].getY();
    }
    cx /= GocDaGiac.size();
    cy /= GocDaGiac.size();

    double goc;
    cout << "Nhập góc quay(radian): "; cin >> goc;

    for(int i = 0; i < GocDaGiac.size(); i++){
        GocDaGiac[i].TinhTien(-cx, -cy);
        GocDaGiac[i] = Diem(GocDaGiac[i].getX()*cos(goc) + GocDaGiac[i].getY()*sin(goc),
                        GocDaGiac[i].getX()*sin(goc) + GocDaGiac[i].getY()*cos(goc));
        GocDaGiac[i].TinhTien(cx, cy);
    }
}