#include "QuanLi.h"

void QuanLi::NhapGiaoDichDat(){
    int n;
    cout << "Nhập số lượng giao dịch đất: "; cin >> n;
    GDDat.resize(n);
    for(int i = 0; i < n; i++){
        GDDat[i].Nhap();
    }
}

void QuanLi::NhapGiaoDichNhaPho(){
    int n;
    cout << "Nhập số lượng giao dịch nhà phố: "; cin >> n;
    GDNhaPho.resize(n);
    for(int i = 0; i < n; i++){
        GDNhaPho[i].Nhap();
    }
}
void QuanLi::NhapGiaoDichChungCu(){
    int n;
    cout << "Nhập số lượng giao dịch nhà chung cư: "; cin >> n;
    GDChungCu.resize(n);
    for(int i = 0; i < n; i++){
        GDChungCu[i].Nhap();
    }
}

void QuanLi::SoLuong(){
    cout << "Số lượng giao dịch đất là: " << GDDat.size() << endl;
    cout << "Số lượng giao dịch nhà phố là: " << GDNhaPho.size() << endl;
    cout << "Số lượng giao dịch chung cư là: " << GDChungCu.size() << endl;
}

void QuanLi::TrungBinhChungCu(){
    double tongChungCu = 0;
    if(GDChungCu.size() == 0) {
        cout << "Chưa có giao dịch chung cư nào!" << endl;
        return;
    }
    
    for(int i = 0; i < GDChungCu.size(); i++){
        tongChungCu += GDChungCu[i].ThanhTien();
    }
    cout << "Trung bình mỗi giao dịch chung cư có giá: " << tongChungCu / GDChungCu.size() << endl;
}

void QuanLi::NhaPhoCaoNhat(){
    if(GDNhaPho.size() == 0) {
        cout << "Chưa có giao dịch nhà phố nào!" << endl;
        return;
    }
    
    double nhaCaoNhat = INT_MIN;
    int nhaCaoNhat_index = 0;
    
    for(int i = 0; i < GDNhaPho.size(); i++){
        if(GDNhaPho[i].ThanhTien() > nhaCaoNhat) {
            nhaCaoNhat = GDNhaPho[i].ThanhTien();
            nhaCaoNhat_index = i;
        }
    }

    cout << "Thông tin giao dịch nhà phố có giá trị cao nhất: " << endl;
    GDNhaPho[nhaCaoNhat_index].Xuat();
    cout << "Thành tiền: " << nhaCaoNhat << endl;
}

void QuanLi::GiaoDichThang12(){
    cout << "Các giao dịch trong tháng 12 năm 2024:" << endl;
    bool coGiaoDich = false;
    
    cout << "Giao dịch đất:" << endl;
    for(int i = 0; i < GDDat.size(); i++){
        if(GDDat[i].getNgayGD().find("12 2024") != string::npos){
            GDDat[i].Xuat();
            cout << "Thành tiền: " << GDDat[i].ThanhTien() << endl;
            cout << "------------------------" << endl;
            coGiaoDich = true;
        }
    }
    
    cout << "Giao dịch nhà phố:" << endl;
    for(int i = 0; i < GDNhaPho.size(); i++){
        if(GDNhaPho[i].getNgayGD().find("12 2024") != string::npos){
            GDNhaPho[i].Xuat();
            cout << "Thành tiền: " << GDNhaPho[i].ThanhTien() << endl;
            cout << "------------------------" << endl;
            coGiaoDich = true;
        }
    }
    
    cout << "Giao dịch chung cư:" << endl;
    for(int i = 0; i < GDChungCu.size(); i++){
        if(GDChungCu[i].getNgayGD().find("12 2024") != string::npos){
            GDChungCu[i].Xuat();
            cout << "Thành tiền: " << GDChungCu[i].ThanhTien() << endl;
            cout << "------------------------" << endl;
            coGiaoDich = true;
        }
    }
    
    if(!coGiaoDich) {
        cout << "Không có giao dịch nào trong tháng 12 năm 2024!" << endl;
    }
}

void QuanLi::menu(){
    cout << "===== CHƯƠNG TRÌNH QUẢN LÝ GIAO DỊCH BẤT ĐỘNG SẢN =====" << endl;
    QuanLi::NhapGiaoDichDat();
    QuanLi::NhapGiaoDichNhaPho();
    QuanLi::NhapGiaoDichChungCu();

    cout << "\n===== MENU =====" << endl;
    cout << "1. Tổng số lượng giao dịch từng loại." << endl;
    cout << "2. Trung bình thành tiền mỗi giao dịch nhà chung cư." << endl;
    cout << "3. Giao dịch nhà phố có giá trị cao nhất." << endl;
    cout << "4. Giao dịch trong tháng 12 năm 2024." << endl;
    cout << "0. Kết thúc chương trình." << endl;

    int choice;
    do{
        cout << "\nNhập lựa chọn của bạn: "; cin >> choice;
        switch(choice){
            case 1:
                SoLuong();
                break;
            case 2:
                TrungBinhChungCu();
                break;
            case 3:
                NhaPhoCaoNhat();
                break;
            case 4:
                GiaoDichThang12();
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