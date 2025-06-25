#include "CongTy.h"

void CongTy::NhapDanhSach(){
    cout << "NHẬP KHÁCH HÀNG LOẠI A (BÌNH THƯỜNG)" << endl;
    int soluongA;
    cout << "Số lượng khách hàng loại A: "; cin >> soluongA;
    cin.ignore();
    listA.resize(soluongA);
    for(int i = 0; i < soluongA; i++){
        cout << "Khách hàng A thứ " << i+1 << ":" << endl;
        listA[i].Nhap();
        cin.ignore();
    }

    cout << "NHẬP KHÁCH HÀNG LOẠI B (THÂN THIẾT)" << endl;
    int soluongB;
    cout << "Số lượng khách hàng loại B: "; cin >> soluongB;
    cin.ignore();
    listB.resize(soluongB);
    for(int i = 0; i < soluongB; i++){
        cout << "Khách hàng B thứ " << i+1 << ":" << endl;
        listB[i].Nhap();
        cin.ignore();
    }

    cout << "NHẬP KHÁCH HÀNG LOẠI C (ĐẶC BIỆT)" << endl;
    int soluongC;
    cout << "Số lượng khách hàng loại C: "; cin >> soluongC;
    cin.ignore();
    listC.resize(soluongC);
    for(int i = 0; i < soluongC; i++){
        cout << "Khách hàng C thứ " << i+1 << ":" << endl;
        listC[i].Nhap();
        cin.ignore();
    }
}

void CongTy::XuatKetQua(){
    cout << "\n========== KẾT QUẢ ==========" << endl;
    
    cout << "\nKHÁCH HÀNG LOẠI A:" << endl;
    for(int i = 0; i < listA.size(); i++){
        cout << "Khách hàng A" << i+1 << endl;
        listA[i].Xuat();
        cout << "Số tiền phải trả: " << listA[i].TinhSoTienPhaiTra() << endl;
        cout << endl;
    }

    cout << "KHÁCH HÀNG LOẠI B:" << endl;
    for(int i = 0; i < listB.size(); i++){
        cout << "Khách hàng B" << i+1 << endl;
        listB[i].Xuat();
        cout << "Số tiền phải trả: " << listB[i].TinhSoTienPhaiTra() << endl;
        cout << endl;
    }

    cout << "KHÁCH HÀNG LOẠI C:" << endl;
    for(int i = 0; i < listC.size(); i++){
        cout << "Khách hàng C" << i+1 << endl;
        listC[i].Xuat();
        cout << "Số tiền phải trả: " << listC[i].TinhSoTienPhaiTra() << endl;
        cout << endl;
    }
}

void CongTy::TinhTongSoTien(){
    double tongSoTien = 0;
    
    for(int i = 0; i < listA.size(); i++){
        tongSoTien += listA[i].TinhSoTienPhaiTra();
    }
    
    for(int i = 0; i < listB.size(); i++){
        tongSoTien += listB[i].TinhSoTienPhaiTra();
    }
    
    for(int i = 0; i < listC.size(); i++){
        tongSoTien += listC[i].TinhSoTienPhaiTra();
    }
    
    cout << "TỔNG SỐ TIỀN CÔNG TY THU ĐƯỢC: " << tongSoTien << endl;
}

void CongTy::DocFile(string filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Không thể mở file " << filename << endl;
        return;
    }
    
    string line;
    while(getline(file, line)){
        if(line.find("TenKhachHangA") != string::npos){
            LoaiA khA;
            listA.push_back(khA);
        }
        else if(line.find("TenKhachHangB") != string::npos){
            LoaiB khB;
            listB.push_back(khB);
        }
        else if(line.find("TenKhachHangC") != string::npos){
            LoaiC khC;
            listC.push_back(khC);
        }
    }
    
    file.close();
    cout << "Đã đọc dữ liệu từ file " << filename << endl;
}

void CongTy::GhiFile(string filename){
    ofstream file(filename);
    if(!file.is_open()){
        cout << "Không thể tạo file " << filename << endl;
        return;
    }
    
    for(int i = 0; i < listA.size(); i++){
        file << "TenKhachHangA" << i+1 << endl;
        file << "SoTienPhaiTraA" << i+1 << endl;
    }
    
    for(int i = 0; i < listB.size(); i++){
        file << "TenKhachHangB" << i+1 << endl;
        file << "SoTienPhaiTraB" << i+1 << endl;
    }
    
    for(int i = 0; i < listC.size(); i++){
        file << "TenKhachHangC" << i+1 << endl;
        file << "SoTienPhaiTraC" << i+1 << endl;
        file << "TongSoTienCongTyThuDuoc" << endl;
    }
    
    file.close();
    cout << "Đã ghi kết quả ra file " << filename << endl;
}