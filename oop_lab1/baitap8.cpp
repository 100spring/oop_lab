#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ngayBay{
    int ngay, thang, nam;
    bool operator==(ngayBay& ngayKhoiHanh){
        return ngay == ngayKhoiHanh.ngay && thang == ngayKhoiHanh.thang && nam == ngayKhoiHanh.nam;
    }
};

struct thoiGian{
    int gio, phut;
    
    bool operator<(thoiGian& time){
        if(gio != time.gio) return gio < time.gio;
        return phut < time.phut;
    }
};

struct chuyenBay{
    string maChuyenBay, noiDi, noiDen;
    ngayBay ngayKhoiHanh;
    thoiGian gioBay; 
};

// kiểm tra mã chuyến bay hợp lệ chưa
bool kiemTraMaChuyenBay(string& ma){
    if(ma.length() > 5)
        return false;
    for(int i = 0; i < ma.length(); i++){
        if(!isalnum(ma[i]))
            return false;
    }
    return true;
}

// kiểm tra giờ bay hợp lệ chưa
bool kiemTraGioBay(thoiGian& gioBay){
    if(gioBay.gio >= 0 && gioBay.gio <= 23 && gioBay.phut >= 0 && gioBay.phut <= 59)
        return true;
    return false;
}

// kiểm tra ngày khởi hành đã hợp lệ chưa
bool kiemTraNgayBay(ngayBay& ngayKhoiHanh){
    if(ngayKhoiHanh.nam < 0 || ngayKhoiHanh.thang < 1 || ngayKhoiHanh.thang > 12 || ngayKhoiHanh.ngay < 1)
        return false;
    int days;
    switch(ngayKhoiHanh.thang){
        case 2:
            if((ngayKhoiHanh.nam%4==0 && ngayKhoiHanh.nam%100!= 0) || (ngayKhoiHanh.nam%400==0))
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }
    return ngayKhoiHanh.ngay <= days;
}

//kiểm tra nơi đi và nơi đến đã hợp lệ hay chưa
bool kiemTraDiaDiem(string& diaDiem){
    if(diaDiem.length() > 20)
        return false;
    for(int i = 0; i < diaDiem.length(); i++){
        if(!isalnum(diaDiem[i]) && diaDiem[i] != ' ')
            return false;
    }
    return true;
}

// hàm nhập thông tin chuyến bay
chuyenBay nhapThongTin(chuyenBay k){
    // nhập mã chuyến bay
    do{
        cout << "Nhap ma chuyen bay: "; cin >> k.maChuyenBay;
        if(!kiemTraMaChuyenBay(k.maChuyenBay))
            cout << "Ma chuyen bay khong hop le. Vui long nhap lai!" << endl;
    }
    while(!kiemTraMaChuyenBay(k.maChuyenBay));
    // nhập ngày khởi hành
    do{
        cout << "Nhap ngay khoi hanh(theo dinh dang DD MM YYYY): "; cin >> k.ngayKhoiHanh.ngay >> k.ngayKhoiHanh.thang >> k.ngayKhoiHanh.nam;
        if(!kiemTraNgayBay(k.ngayKhoiHanh))
            cout << "Ngay khoi hanh khong hop le. Vui long nhap lai!" << endl;
    }
    while(!kiemTraNgayBay(k.ngayKhoiHanh));
    // nhập giờ bay
    do{
        cout << "Nhap gio bay(theo dinh dang HH MM): "; cin >> k.gioBay.gio >> k.gioBay.phut;
        if(!kiemTraGioBay(k.gioBay))
            cout << "Gio bay khong hop le. Vui long nhap lai!" << endl;
    }
    while(!kiemTraGioBay(k.gioBay));
    // nhập nơi đi
    cin.ignore();
    do{
        cout << "Nhap noi di: "; getline(cin, k.noiDi);
        if(!kiemTraDiaDiem(k.noiDi))
            cout << "Noi di khong hop le. Vui long nhap lai!" << endl;
    }
    while(!kiemTraDiaDiem(k.noiDi));
    // nhập nơi đến
    do{
        cout << "Nhap noi den: "; getline(cin, k.noiDen);
        if(!kiemTraDiaDiem(k.noiDen))
            cout << "Noi den khong hop le. Vui long nhap lai!" << endl;
    }
    while(!kiemTraDiaDiem(k.noiDen));

    return k;
}

// hàm xuất thông tin một chuyến bay
void xuatMotChuyenBay(chuyenBay& k){
    cout << "THONG TIN CHUYEN BAY" << endl;
    cout << "Ma chuyen bay: " << k.maChuyenBay << endl;
    cout << "Ngay khoi hanh: " << k.ngayKhoiHanh.ngay << "/" << k.ngayKhoiHanh.thang << "/" << k.ngayKhoiHanh.nam << endl;
    cout << "Gio bay: " << k.gioBay.gio << ":" << k.gioBay.phut << endl;
    cout << "Noi di: " << k.noiDi << endl;
    cout << "Noi den: " << k.noiDen << endl << endl;
}

// hàm xuất danh sách chuyến bay
void danhSachChuyenBay(vector<chuyenBay>& cacChuyenBay){
    if(cacChuyenBay.empty())
        cout << "Khong co chuyen bay nao trong danh sach!" << endl;
    else{
        for(int i = 0; i < cacChuyenBay.size(); i++)
            xuatMotChuyenBay(cacChuyenBay[i]);
    }    
}

// so sánh thời gian bay
bool soSanhThoiGian(chuyenBay& a, chuyenBay& b){
    if(a.gioBay < b.gioBay) return true;
    if(b.gioBay < a.gioBay) return false;
    return false;
}

// sắp xếp chuyến bay theo thứ tự thời gian bay
vector<chuyenBay> sapXepTheoThoiGian(vector<chuyenBay> cacChuyenBay){
    sort(cacChuyenBay.begin(), cacChuyenBay.end(), soSanhThoiGian);
    return cacChuyenBay;
} 

// hàm tìm kiếm chuyến bay theo mã
void timTheoMa(vector<chuyenBay>& cacChuyenBay, string& ma){
    for(int i = 0; i < cacChuyenBay.size(); i++){
        if(cacChuyenBay[i].maChuyenBay == ma)
            xuatMotChuyenBay(cacChuyenBay[i]);
    }
}

// hàm tìm kiếm chuyến bay theo nơi đi
void timTheoNoiDi(vector<chuyenBay>& cacChuyenBay, string& xuatPhat){
    for(int i = 0; i < cacChuyenBay.size(); i++){
        if(cacChuyenBay[i].noiDi == xuatPhat)
            xuatMotChuyenBay(cacChuyenBay[i]);
    }
}

// hàm tìm kiếm chuyến bay theo nơi đến
void timTheoNoiDen(vector<chuyenBay>& cacChuyenBay, string& diemDen){
    for(int i = 0; i < cacChuyenBay.size(); i++){
        if(cacChuyenBay[i].noiDen == diemDen)
            xuatMotChuyenBay(cacChuyenBay[i]);
    }
}

// hàm tìm kiếm chuyến bay từ nơi đi trong một ngày cụ thể
void timTheoNoiDiTrongNgay(vector<chuyenBay>& cacChuyenBay, string& xuatPhat, ngayBay& ngayDi){
    for(int i = 0; i < cacChuyenBay.size(); i++){
        if(cacChuyenBay[i].noiDi == xuatPhat && cacChuyenBay[i].ngayKhoiHanh == ngayDi)
            xuatMotChuyenBay(cacChuyenBay[i]);
    }
}

// hàm đếm số lượng chuyến bay biết nơi đi và nơi đến
int demSoChuyenBay(vector<chuyenBay>& cacChuyenBay, string& xuatPhat, string& diemDen){
    int count = 0;
    for(int i = 0; i < cacChuyenBay.size(); i++){
        if(cacChuyenBay[i].noiDi == xuatPhat && cacChuyenBay[i].noiDen == diemDen)
            count++;
    }
    return count;
}

int main(){
    int soChuyenBay;
    cout << "So luong chuyen bay muon nhap la: "; cin >> soChuyenBay;
    
    vector<chuyenBay> cacChuyenBay(soChuyenBay);
    cout << "Hay nhap thong tin cua cac chuyen bay!" << endl;
    for(int i = 0; i < soChuyenBay; i++){
        cout << "CHUYEN BAY THU " << i+1 << endl;
        cacChuyenBay[i] = nhapThongTin(cacChuyenBay[i]);
        cout << endl;
    }

    cout << "DANH SACH CHUYEN BAY THEO GIO KHOI HANH:" << endl;
    cacChuyenBay = sapXepTheoThoiGian(cacChuyenBay);
    for(int i = 0; i < soChuyenBay; i++){
        cout << "CHUYEN BAY THU " << i+1 << endl;
        xuatMotChuyenBay(cacChuyenBay[i]);
        cout << endl;
    }

    int luaChon;
    do {
        cout << "\nBan muon thuc hien thao tac nao?" << endl;
        cout << "Nhan 0 de thoat." << endl;
        cout << "Nhan 1 de tim chuyen bay theo ma chuyen bay." << endl;
        cout << "Nhan 2 de tim chuyen bay theo noi di." << endl;
        cout << "Nhan 3 de tim chuyen bay theo noi den." << endl;
        cout << "Nhan 4 de dem tat ca chuyen bay theo noi di va noi den." << endl;
        cout << "Nhan 5 de hien thi danh sach chuyen bay tu noi di trong mot ngay." << endl;
        
        cout << "Ban chon thao tac thu: "; cin >> luaChon;
        cin.ignore(); // bỏ qua kí tự xuống dòng

        switch(luaChon){
            case 0: {
                cout << "Cam on ban da su dung chuong trinh!";
                break;
            }
            case 1: {
                string ma;
                cout << "Nhap ma chuyen bay can tim: "; cin >> ma;
                timTheoMa(cacChuyenBay, ma);
                break;
            }
            case 2: {
                string xuatPhat;
                cout << "Nhap noi di can tim: "; getline(cin, xuatPhat);
                timTheoNoiDi(cacChuyenBay, xuatPhat);
                break;
            }
            case 3: {
                string diemDen;
                cout << "Nhap noi den can tim: "; getline(cin, diemDen);
                timTheoNoiDen(cacChuyenBay, diemDen);
                break;
            }
            case 4: {
                string xuatPhat, diemDen;
                cout << "Nhap noi di can tim: "; getline(cin, xuatPhat);
                cout << "Nhap noi den can tim: "; getline(cin, diemDen);
                cout << "So chuyen bay dem duoc theo yeu cau la: " << demSoChuyenBay(cacChuyenBay, xuatPhat, diemDen);
                break;
            }
            case 5: {
                string xuatPhat;
                ngayBay ngayDi;
                cout << "Nhap noi di can tim: "; getline(cin, xuatPhat);
                cout << "Nhap ngay can tim(theo dinh dang DD MM YYYY): "; cin >> ngayDi.ngay >> ngayDi.thang >> ngayDi.nam;
                timTheoNoiDiTrongNgay(cacChuyenBay, xuatPhat, ngayDi);
                break;
            }
            default: {
                cout << "Lua chon khong hop le.";
            }
        }
        
    } while (luaChon != 0);

    return 0;
}