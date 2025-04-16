#include "ListCandidate.h"

void ListCandidate::Nhap(){
    int soLuong;
    cout << "Số thí sinh cần nhập là: "; cin >> soLuong;
    DSThiSinh.resize(soLuong);

    for(int i = 0; i < soLuong; i++){
        cout << "Nhập thông tin thí sinh thứ " << i+1 << endl;
        DSThiSinh[i].Nhap();
    }
    cout << endl;
}

void ListCandidate::XuatTongDiemCao(){
    cout << "Danh sách thí sinh có tổng điểm cao hơn 15" << endl;
    for(int i = 0; i < DSThiSinh.size(); i++){
        if(DSThiSinh[i].getDiemTB() > 15){
            DSThiSinh[i].Xuat();
        }
    }
    cout << endl;
}

void ListCandidate::ThiSinhCaoDiemNhat(){
    cout << "Thí sinh có tổng điểm cao nhất là: " << endl;
    double temp = INT_MIN;
    Candidate thisinh;

    for(int i = 0; i < DSThiSinh.size(); i++){
        if(DSThiSinh[i].getDiemTB() > temp){
            thisinh = DSThiSinh[i];
            temp = DSThiSinh[i].getDiemTB();
        }
    }

    thisinh.Xuat();
    cout << endl;
}

bool SoSanh(Candidate a, Candidate b){
    return a.getDiemTB() > b.getDiemTB();
}

void ListCandidate::TongDiemGiamDan(){
    sort(DSThiSinh.begin(), DSThiSinh.end(), SoSanh);

    cout << "Danh sách thí sinh sau khi xếp theo tổng điểm giảm dần" << endl;
    for(int i = 0; i < DSThiSinh.size(); i++){
        DSThiSinh[i].Xuat();
    }
}