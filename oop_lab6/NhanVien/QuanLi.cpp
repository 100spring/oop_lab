#include "QuanLi.h"

void QuanLi::Nhap(){
    cout << "NHẬP NHÂN VIÊN VĂN PHÒNG" << endl;
    int soluongvp;
    cout << "Số lượng nhân viên văn phòng: "; cin >> soluongvp;
    listVP.resize(soluongvp);
    for(int i = 0; i < soluongvp; i++){
        listVP[i].Nhap();
    }

    cout << "NHẬP NHÂN VIÊN SẢN XUẤT" << endl;
    int soluongsx;
    cout << "Số lượng nhân viên sản xuất: "; cin >> soluongsx;
    listSX.resize(soluongsx);
    for(int i = 0; i < soluongsx; i++){
        listSX[i].Nhap();
    }
}

void QuanLi::XuatLuong(){
    cout << "LƯƠNG NHÂN VIÊN VĂN PHÒNG" << endl;
    for(int i = 0; i < listVP.size(); i++){
        cout << listVP[i].getHoTen() << listVP[i].TinhLuong() << endl;
    }

    cout << "LƯƠNG NHÂN VIÊN SẢN XUẤT" << endl;
    for(int i = 0; i < listSX.size(); i++){
        cout << listSX[i].getHoTen() << listSX[i].TinhLuong() << endl;
    }
}

void QuanLi::Xuat(){
    cout << "XUÂT NHÂN VIÊN VĂN PHÒNG" << endl;
    for(int i = 0; i < listVP.size(); i++){
        listVP[i].Xuat();
    }
    cout << "XUÂT NHÂN VIÊN SẢN XUẤT" << endl;
    for(int i = 0; i < listSX.size(); i++){
        listSX[i].Xuat();
    }
}

void QuanLi::TongLuong(){
    cout << "TỔNG LƯƠNG CÔNG TY CẦN TRẢ: ";
    double sum;
    for(int i = 0; i < listVP.size(); i++){
        sum += listVP[i].TinhLuong();
    }
    for(int i = 0; i < listSX.size(); i++){
        sum += listSX[i].TinhLuong();
    }
    cout << sum << endl;
}

void QuanLi::LuongSXThapNhat(){
    int index;
    double min_luong = INT_MAX;
    for(int i = 0; i < listSX.size(); i++){
        if(min_luong > listSX[i].TinhLuong())
            index = i;
    }
    cout << "NHÂN VIÊN SẢN XUẤT CÓ LƯƠNG THẤP NHẤT:" << endl;
    listSX[index].Xuat();
}

void QuanLi::VanPhongCaoTuoi(){
    int index;
    int max_namsinh = INT_MIN;
    for(int i = 0; i < listVP.size(); i++){
        if(max_namsinh > listVP[i].getNamSinh())
            index = i;
    }
    cout << "NHÂN VIÊN VĂN PHÒNG CAO TUỔI NHẤT:" << endl;
    listVP[index].Xuat();
}