#include "DanhSach.h"

void DanhSach::Nhap(){
    int soLuong;
    cout << "Số nhân viên cần nhập là: "; cin >> soLuong;
    DSNhanVien.resize(soLuong);

    for(int i = 0; i < soLuong; i++){
        cout << "Nhập thông tin nhân viên thứ " << i+1 << endl;
        DSNhanVien[i].Nhap();
    }
    cout << endl;
}

void DanhSach::Xuat(){
    for(int i = 0; i < DSNhanVien.size(); i++){
        cout << "Thông tin của nhân viên thứ " << i+1 << endl;
        DSNhanVien[i].Xuat();
        cout << endl;
    }
}

void DanhSach::LuongCaoNhat(){
    int temp = INT_MIN;
    NhanVien x;

    for(int i = 0; i < DSNhanVien.size(); i++){
        if(DSNhanVien[i].getLuong() > temp){
            x = DSNhanVien[i];
            temp = DSNhanVien[i].getLuong();
        }
    }

    cout << "Nhân viên có lương cao nhất là: " << endl;
    x.Xuat();
    cout << endl;
}

void DanhSach::TongLuong(){
    double sum;
    for(int i = 0; i < DSNhanVien.size(); i++){
        sum += DSNhanVien[i].getLuong();
    }

    cout << "Tổng lương cần trả cho nhân viên là: " << sum << endl << endl;
}

void DanhSach::TuoiCaoNhat(){
    int age = INT_MIN;
    NhanVien x;

    for(int i = 0; i < DSNhanVien.size(); i++){
        if(DSNhanVien[i].getTuoi() > age){
            x = DSNhanVien[i];
            age = DSNhanVien[i].getTuoi();
        }
    }

    cout << "Nhân viên có tuổi cao nhất là: " << endl;
    x.Xuat();
    cout << endl;
}

bool SoSanh(NhanVien a, NhanVien b){
    return a.getLuong() < b.getLuong();
}

void DanhSach::SXTangTheoLuong(){
    sort(DSNhanVien.begin(), DSNhanVien.end(), SoSanh);

    cout << "Danh sách nhân viên tăng dần theo lương:" << endl;
    for(int i = 0; i < DSNhanVien.size(); i++){
        DSNhanVien[i].Xuat();
        cout << endl;
    }
}