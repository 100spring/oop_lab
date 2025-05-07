#include "QuanLi.h"

void QuanLi::GiaoDichVangCaoNhat(){
    double maxGD = INT_MIN;

    for(int i = 0; i < GDV.size(); i++){
        maxGD = max(maxGD, GDV[i].ThanhTienVang());
    }

    cout << "Giao dịch vàng có giá trị lớn nhất:" << endl;
    for(int i = 0; i < GDV.size(); i++){
        if(GDV[i].ThanhTienVang() == maxGD){
            GDV[i].XuatVang();
            cout << endl;
            break;
        }
    }
}

void QuanLi::GiaoDichEURThapNhat(){
    double minGD = INT_MAX;
    bool check = false;

    for(int i = 0; i < GDTT.size(); i++){
        if(GDTT[i].getType() == "EUR"){
            check = true;
            minGD = min(minGD, GDTT[i].ThanhTien());
        }
    }

    if(!check){
        cout << "Không có giao dịch đồng EUR nào." << endl;
        return;
    }
    cout << "Giao dịch đồng EUR có giá trị nhỏ nhất là:" << endl;
    for(int i = 0; i < GDTT.size(); i++){
        if(GDTT[i].ThanhTien() == minGD){
            GDTT[i].XuatTienTe();
            cout << endl;
            break;
        }
    }
}

void QuanLi::GiaoDichGiaTriCao(){
    bool check = false;

    for(int i = 0; i < GDV.size(); i++){
        if(GDV[i].ThanhTienVang() > 1e9){
            GDV[i].XuatVang();
            cout << endl;
            check = true;
        }
    }

    for(int i = 0; i < GDTT.size(); i++){
        if(GDTT[i].ThanhTien() > 1e9){
            GDTT[i].XuatTienTe();
            cout << endl;
            check = true;
        }
    }

    if(!check){
        cout << "Không có giao dịch nào có giá trị trên 1 tỉ." << endl;
    }
}

void QuanLi::menu(){
    int soLuongVang, soLuongTienTe;
    cout << "Số lượng giao dịch vàng muốn quản lí: "; cin >> soLuongVang;
    cout << "Số lượng giao dịch tiền tệ muốn quản lí: "; cin >> soLuongTienTe;

    GDV.resize(soLuongVang);
    GDTT.resize(soLuongTienTe);

    cout << endl;
    cout << "Nhập thông tin các giao dịch vàng." << endl;
    for(int i = 0; i < soLuongVang; i++){
        GDV[i].NhapVang();
        cout << endl;
    }
    cout << "Nhập thông tin các giao dịch tiền tệ." << endl;
    for(int i = 0; i < soLuongTienTe; i++){
        GDTT[i].NhapTienTe();
        cout << endl;
    }

    cout << "1. Hiển thị giao dịch vàng có giá trị cao nhất." << endl;
    cout << "2. Hiển thị giao dịch đồng EUR có giá trị thấp nhất." << endl;
    cout << "3. Hiển thị các giao dịch có giá trị trên 1 tỉ đồng." << endl;
    cout << "0. Kết thúc chương trình." << endl;

    int choice;
    do{
        cout << "Nhập lựa chọn của bạn: "; cin >> choice;
        switch(choice){
            case 1:
                GiaoDichVangCaoNhat();
                break;
            case 2:
                GiaoDichEURThapNhat();
                break;
            case 3:
                GiaoDichGiaTriCao();
                break;
            case 0:
                cout << "Kết thúc chương trình.";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại." << endl;

        }
    }
    while(choice != 0);
} 