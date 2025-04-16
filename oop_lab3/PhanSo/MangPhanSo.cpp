#include "MangPhanSo.h"

DSPhanSo::DSPhanSo(){}
DSPhanSo::~DSPhanSo(){}

void DSPhanSo::Nhap(){
    int soLuong;
    cout << "Số phân số muốn nhập là: "; cin >> soLuong;
    MangPhanSo.resize(soLuong);

    for(int i = 0; i < soLuong; i++){
        cout << "Nhập phân số thứ " << i+1 << "(tử mẫu): ";
        MangPhanSo[i].Nhap();
    }
}

void DSPhanSo::Xuat(){
    for(int i = 0; i < MangPhanSo.size(); i++){
        MangPhanSo[i].Xuat();
        cout << "  ";
    }
    cout << endl;
}

PhanSo DSPhanSo::Tong(){
    PhanSo a = MangPhanSo[0];
    for(int i = 1; i < MangPhanSo.size(); i++){
        a = MangPhanSo[i].Cong(a);
    }

    a.RutGon();
    return a;
}

PhanSo DSPhanSo::PSLonNhat(){
    PhanSo a = MangPhanSo[0];
    for(int i = 1; i < MangPhanSo.size(); i++){
        if(MangPhanSo[i].SoSanhLonHon(a))
            a = MangPhanSo[i];
    }
    a.RutGon();
    return a;
}

PhanSo DSPhanSo::PSNhoNhat(){
    PhanSo a = MangPhanSo[0];
    for(int i = 1; i < MangPhanSo.size(); i++){
        if(a.SoSanhLonHon(MangPhanSo[i]))
            a = MangPhanSo[i];
    }
    a.RutGon();
    return a;
}

bool SoNguyenTo(int n){
    if(n <= 1) 
        return false;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0) 
            return false;
    }
    return true;
}

PhanSo DSPhanSo::NguyenToLonNhat(){
    PhanSo temp(0, 1);
    bool found = false;

    for(int i = 0; i < MangPhanSo.size(); i++){
        if(SoNguyenTo(MangPhanSo[i].getTu())){
            if(!found || MangPhanSo[i].getTu() > temp.getTu()){
                found = true;
                temp = MangPhanSo[i];
            } 
        }
    }

    if(!found){
        cout << "Không có phân số nào có tử là số nguyên tố.";
        return PhanSo(0, 0);
    }
    else
        return temp;
}

bool SoSanh(PhanSo a, PhanSo b){
    return a.getTu()*b.getMau() < a.getMau()*b.getTu();
}

void DSPhanSo::SXTangDan(){
    sort(MangPhanSo.begin(), MangPhanSo.end(), SoSanh);
}

void DSPhanSo::SXGiamDan(){
    sort(MangPhanSo.rbegin(), MangPhanSo.rend(), SoSanh);
}