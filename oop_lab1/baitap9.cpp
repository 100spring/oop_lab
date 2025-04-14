#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Ngay{
    int ngay, thang, nam;
    Ngay(): ngay(15), thang(3), nam(2025){}
    Ngay(int d, int m, int y) : ngay(d), thang(m), nam(y){}

    // hàm kiểm tra năm nhuận
    bool leapYear(){
        return (nam%4==0 && nam%100!=0) || (nam%400==0);
    }

    // hàm kiểm tra tính hợp lệ của ngày
    bool kiemTraNgay(){
        if(nam < 1 || ngay < 1 || thang < 1 || thang > 12)
            return false;
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(leapYear())
            days[2] = 29;
        return ngay <= days[thang];
    }

    // hàm tính số Julian dùng cho việc tính thời gian giữa hai ngày
    int soJulian(int d, int m, int y){
        if(m < 2){
            m += 12;
            y -= 1;
        }
        return d + (153 * (m + 1) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400);
    }

    //hàm đếm số ngày giữa hai ngày sử dụng công thức tính ngay Julian
    int demSoNgay(Ngay& ngaySau){
        int so1 = soJulian(ngay, thang, nam);
        int so2 = soJulian(ngaySau.ngay, ngaySau.thang, ngaySau.nam);
        return so2-so1;
    }   

    // hàm nhập ngày
    void nhapNgay(){
        do{
            cout << "Nhap ngay mo so(theo dinh dang DD MM YYYY): ";
            cin >> ngay >> thang >> nam;
            if(!kiemTraNgay())
                cout << "Ngay khong hop le. Vui long nhap lai." << endl;
        }
        while(!kiemTraNgay());
    }

    // hàm xuất ngày
    void xuatNgay(){
        cout << ngay << "/" << thang << "/" << nam;
    }
};

// hàm lấy ngày hiện tại(dùng cho việc tính lãi suất)
Ngay layNgayHienTai(){
    // tạm để ngày bất kì
    return Ngay(15, 3, 2025);
}

struct soTietKiem{
    string maSo;
    string hoTen;
    string loaiTietKiem;
    string CMND;
    Ngay ngayMo;
    float soTienGui;

    // hàm kiểm tra kí tự số
    bool kiTuSo(char c){
        return (c >= '0' && c <= '9');
    }

    // kiểm tra mã sổ tiết kiệm
    bool kiemTraMaSo(string& maSoTietKiem){
        if(maSoTietKiem.length() > 5)
            return false;
        for(int i = 0; i < maSoTietKiem.length(); i++){
            if(!isalnum(maSoTietKiem[i]))
                return false;
        }
        return true;
    }

    // kiểm tra họ và tên
    bool kiemTraHoTen(string& hoVaTen){
        if(hoVaTen.length() > 30)
            return false;
        for(int i = 0; i < hoVaTen.length(); i++){
            if(hoVaTen[i] >= '0' && hoVaTen[i] <= '9')
                return false;
        }
        return true;
    }

    // kiểm tra CMND
    bool kiemTraCMND(string& socm){
        if(socm.length() != 9 && socm.length() != 12)
            return false;
        for(int i = 0; i < socm.length(); i++){
            if(!kiTuSo(socm[i]))
                return false;
        }
        return true;
    }

    // nhập thông tin mở sổ tiết kiệm
    void nhapSo(){
        // nhập mã sổ tiết kiệm
        do{
            cout << "Nhap ma so tiet kiem(toi da 5 ki tu, khong chua ki tu dac biet): ";
            cin >> maSo;
            if(!kiemTraMaSo(maSo))
                cout << "Ma so tiet kiem khong hop le. Vui long nhap lai." << endl;
        }
        while(!kiemTraMaSo(maSo));
        // nhập hình thức tiết kiệm
        cin.ignore();
        do{
            cout << "Nhap loai tiet kiem(toi da 10 ki tu): ";
            getline(cin, loaiTietKiem);
            if(loaiTietKiem.length() > 10)
                cout << "Loai tiet kiem qua 10 ki tu. Vui long nhap lai." << endl;
        }
        while(loaiTietKiem.length() > 10);
        // nhập họ và tên
        do{
            cout << "Nhap ho va ten khach hang(toi da 30 ki tu, khong chua so hay ki tu dac biet): ";
            getline(cin, hoTen);
            if(!kiemTraHoTen(hoTen))
                cout << "Ten khach hang khong hop le. Vui long nhap lai." << endl;
        }
        while(!kiemTraHoTen(hoTen));
        // nhập CMND khách hàng
        do{
            cout << "Nhap CMND cua khach hang(9 hoac 12 so): ";
            cin >> CMND;
            if(!kiemTraCMND(CMND))
                cout << "So CMND khong hop le. Vui long nhap lai." << endl;
        }
        while(!kiemTraCMND(CMND));
        // nhập ngày mở sổ
        ngayMo.nhapNgay();
        // nhập số tiền gửi tiết kiệm
        do{
            cout << "Nhap so tien gui: ";
            cin >> soTienGui;
            if(soTienGui <= 0)
                cout << "So tien gui vao phai la so duong. Vui long nhap lai." << endl;
        }
        while(soTienGui <= 0);
    }

    // hàm xuất thông tin sổ tiết kiệm
    void xuatSo(){
        cout << "Ma so: " << maSo << endl;
        cout << "Loai tiet kiem: " << loaiTietKiem << endl;
        cout << "Ho va ten: " << hoTen << endl;
        cout << "So CMND: " << CMND << endl;
        cout << "Ngay mo so: "; ngayMo.xuatNgay();
        cout << endl << "So tien gui vao: " << soTienGui << endl;
    }

    // hàm tính lãi suất, áp dụng cho cả tính lãi suất
    // đúng hạn và trước hạn
    float tinhLaiSuat(float laiSuat, bool rutTruocHan){
        Ngay ngayHienTai = layNgayHienTai();
        int soNgay = ngayMo.demSoNgay(ngayHienTai);
        float rate = laiSuat;
        // tính lãi suất
        if(!rutTruocHan)
            rate = 0.5;
        else{
            if(loaiTietKiem == "dai han" && soNgay <= 183) // chưa đủ 6 tháng, áp dụng lãi suất ngắn hạn 
                rate = rate*0.8;
            else if(loaiTietKiem == "ngan han" && soNgay > 183) // vượt quá 6 tháng, áp dụng lãi suất dài hạn
                rate = rate*1.2;
        }
        return soTienGui * rate / 100 * soNgay / 100;
    }

    // hàm thực hiện rút tiền, trả về true nếu rút tiền thành công và ngược lại
    // hàm phụ cho hàm thực hiện việc rút tiền
    bool rutTien(float soTienRut, float tienLai, float laiSuat){
        if(soTienRut > soTienGui){
            cout << "So tien rut khong duoc vuot qua so tien gui." << endl;
            return false;
        }
        bool rutTruocHan = false; // giả sử mặc định rút đúng hạn
        Ngay ngayHienTai = layNgayHienTai();
        int soNgay = ngayMo.demSoNgay(ngayHienTai);

        if((loaiTietKiem == "ngan han" && soNgay < 30) || (loaiTietKiem == "dai han" && soNgay < 183)){
            cout << "Ban dang rut tien truoc han." << endl << "Lai suat se duoc tinh o muc 0,5%/nam." << endl;
            rutTruocHan = true;
        }
        // tính lãi suất
        tienLai = soTienGui * laiSuat  / 100 * soNgay / 365 * soTienRut / soTienGui; // nếu rút đúng hạn
        if(rutTruocHan)
            tienLai = soTienGui * 0.5  / 100 * soNgay / 365 * soTienRut / soTienGui;
        soTienGui -= soTienRut;
        return true;
    }
};

vector<soTietKiem> danhSachSo;

// hàm nhập thêm sổ tiết kiệm
void themSoTietKiem(){
    soTietKiem so;
    cout << "NHAP THONG TIN MO SO TIET KIEM." << endl;
    so.nhapSo();
    danhSachSo.push_back(so);
    cout << "Them so thanh cong." << endl;
}

// hàm hiển thị danh sách các sổ được nhập vào
void hienThiDanhSachSo(){
    if(danhSachSo.empty())
        cout << "Hien khong co so tiet kiem nao duoc ghi nhan." << endl;
    
    for(int i = 0; i < danhSachSo.size(); i++){
        cout << "Thong tin ve so thu " << i+1;
        danhSachSo[i].xuatSo();
        cout << endl;
    }
}

// hàm tìm kiếm thông tin sổ theo mã sổ hoặc CMND
void timKiemSo(){
    cout << "Chon 1 de tim thong tin so theo ma so." << endl;
    cout << "Chon 2 de tim thong tin so theo CMND." << endl;
    int luaChon;
    cout << "Lua chon cua ban: "; cin >> luaChon;
    string timKiem;
    bool timThay = false;
    do{
        if(luaChon == 1){
            cout << "Ma so muon tim: "; cin >> timKiem;
            for(int i = 0; i < danhSachSo.size(); i++){
                if(danhSachSo[i].maSo == timKiem){
                    danhSachSo[i].xuatSo();
                    timThay = true;
                }
            }
        }
        else if(luaChon == 2){
            cout << "CMND muon tim: "; cin >> timKiem;
            for(int i = 0; i < danhSachSo.size(); i++){
                if(danhSachSo[i].CMND == timKiem){
                    danhSachSo[i].xuatSo();
                    timThay = true;
                }
            }
        }
        else{
            cout << "Lua chon khong hop le." << endl;
        }
    }
    while(luaChon != 1 && luaChon != 2);
    if(!timThay)
        cout << "Khong tim thay so tiet kiem theo yeu cau." << endl;
}

// hàm liệt kê các sổ tiết kiệm được mở trong một khoảng thời gian
void lietKeSoTheoThoiGian(){
    Ngay ngayBatDau(0, 0, 0);
    Ngay ngayKetThuc(0, 0, 0);

    cout << "CAC SO TIM THAY TRONG KHOANG THOI GIAN:" << endl;
    do{
        cout << "Nhap ngay bat dau(DD MM YYYY): "; ngayBatDau.nhapNgay();
        cout << "Nhap ngay ket thuc(DD MM YYYY): "; ngayKetThuc.nhapNgay();
        if(ngayBatDau.demSoNgay(ngayKetThuc) < 0)
            cout << "Ngay bat dau khong duoc truoc ngay ket thuc." << endl;
    }
    while(ngayBatDau.demSoNgay(ngayKetThuc) < 0);

    bool timThay = false;
    for(int i = 0; i < danhSachSo.size(); i++){
        if(ngayBatDau.demSoNgay(danhSachSo[i].ngayMo) >= 0 && danhSachSo[i].ngayMo.demSoNgay(ngayKetThuc) >= 0){
            danhSachSo[i].xuatSo();
            cout << endl;
            timThay = true;
        }
    }
    if(!timThay)
        cout << "Khong co so tiet kiem duoc mo trong khoang thoi gian nay." << endl;
}

// hàm xử lí thực hiện việc rút tiền
void thucHienRutTien(){
    string maSoCanRut;
    cout << "RUT TIEN TU SO TIET KIEM." << endl;
    cout << "Nhap ma so can rut: "; cin >> maSoCanRut;
    
    bool timThay = false;
    for(int i = 0; i < danhSachSo.size(); i++){
        if(danhSachSo[i].maSo == maSoCanRut){
            danhSachSo[i].xuatSo();
            timThay = true;
        
            float soTienRut, laiSuatHienTai, soTienLai;
            cout << "Nhap lai suat hien tai(%/nam): "; cin >> laiSuatHienTai;
            do{
                cout << "Nhap so tien muon rut: "; cin >> soTienRut;
                if(soTienRut <= 0)
                    cout << "So tien rut ra phai la so duong. Vui long nhap lai." << endl;
                if(soTienRut > danhSachSo[i].soTienGui)
                    cout << "So tien rut khong duoc vuot qua so tien gui vao. Vui long nhap lai." << endl;
            }
            while(soTienRut <= 0 || soTienRut > danhSachSo[i].soTienGui);
            if(danhSachSo[i].rutTien(soTienRut, soTienLai, laiSuatHienTai)){
                cout << "Rut tien thanh cong!" << endl;
                cout << "So tien lai duoc nhan: " << soTienLai << endl;
                cout << "Tong so tien nhan duoc: " << soTienRut + soTienLai << endl;
                cout << "So du con lai trong so: " << danhSachSo[i].soTienGui << endl;
            }
            break;
        }
    }

    if(!timThay)
        cout << "Khong tim thay so tiet kiem voi ma tuong ung." << endl;
}

// hàm tính toán lãi suât và hiển thị tiền lãi cho tất cả các sổ đang quản lí
void tinhToanLaiSuat(){
    float laiSuatHienTai;
    cout << "Nhap lai suat hien tai (%/nam): "; cin >> laiSuatHienTai;
    
    for(int i = 0; i < danhSachSo.size(); i++){
        float tienLai = danhSachSo[i].tinhLaiSuat(laiSuatHienTai, false);
        Ngay ngayHienTai = layNgayHienTai();
        int soNgay = danhSachSo[i].ngayMo.demSoNgay(ngayHienTai);
        
        cout << endl;
        cout << "So tiet kiem thu " << i+1 << endl;
        cout << "Ma so: " << danhSachSo[i].maSo << endl;
        cout << "Khach hang: " << danhSachSo[i].hoTen << endl;
        cout << "Loai tiet kiem: " << danhSachSo[i].loaiTietKiem << endl;
        cout << "So tien gui: " << danhSachSo[i].soTienGui << endl;
        cout << "So ngay da gui: " << soNgay << endl;
        cout << "Tien lai tinh den hien tai: " << tienLai << endl;
    }
}

// hàm so sánh số tiền để sử dụng cho việc sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần
bool soSanhSoTienGui(soTietKiem &a, soTietKiem &b) {
    return a.soTienGui > b.soTienGui;
}

// Hàm sắp xếp danh sách sổ tiết kiệm theo số tiền gửi giảm dần
void sapXepTheoTienGuiGiamDan(){
    sort(danhSachSo.begin(), danhSachSo.end(), soSanhSoTienGui);
    cout << endl;
    cout << "Danh sach so tiet kiem sau khi sap xep theo so tien gui giam dan:" << endl;
    hienThiDanhSachSo();
}

// hàm so sánh ngày mở sổ để sử dụng cho việc sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần
bool soSanhNgayMo(soTietKiem &a, soTietKiem &b) {
    if (a.ngayMo.nam != b.ngayMo.nam)
        return a.ngayMo.nam < b.ngayMo.nam;
    if (a.ngayMo.thang != b.ngayMo.thang)
        return a.ngayMo.thang < b.ngayMo.thang;
    return a.ngayMo.ngay < b.ngayMo.ngay;
}

// Hàm sắp xếp danh sách sổ tiết kiệm theo ngày mở sổ tăng dần
void sapXepTheoNgayMoTangDan(){
    sort(danhSachSo.begin(), danhSachSo.end(), soSanhNgayMo);
    cout << endl;
    cout << "Danh sach so tiet kiem sau khi sap xep theo ngay mo so tang dan:" << endl;
    hienThiDanhSachSo();
}

// Hàm hiển thị và xử lý lựa chọn
void hienThiMenu(){
    int luaChon;
    do{
        cout << "1. Them so tiet kiem moi" << endl;
        cout << "2. Hien thi danh sach so tiet kiem" << endl;
        cout << "3. Tim kiem so tiet kiem" << endl;
        cout << "4. Liet ke so tiet kiem theo khoang thoi gian" << endl;
        cout << "5. Rut tien tu so tiet kiem" << endl;
        cout << "6. Tinh toan lai suat cho cac so tiet kiem" << endl;
        cout << "7. Sap xep so tiet kiem theo so tien gui giam dan" << endl;
        cout << "8. Sap xep so tiet kiem theo ngay mo so tang dan" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        
        switch(luaChon){
            case 1:
                themSoTietKiem();
                break;
            case 2:
                hienThiDanhSachSo();
                break;
            case 3:
                timKiemSo();
                break;
            case 4:
                lietKeSoTheoThoiGian();
                break;
            case 5:
                thucHienRutTien();
                break;
            case 6:
                tinhToanLaiSuat();
                break;
            case 7:
                sapXepTheoTienGuiGiamDan();
                break;
            case 8:
                sapXepTheoNgayMoTangDan();
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
        }
    } while(luaChon != 0);
}

int main(){
    hienThiMenu();
    return 0;
}