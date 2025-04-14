#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct hocSinh {
    string hoVaTen, xepLoai;
    float diemToan, diemVan, diemAnh, diemTB;
};

// hàm tính điểm trung bình của học sinh
// với đầu vào là điểm toán, văn, anh của học sinh
float diemTrungBinh(hocSinh& hs) {
    hs.diemTB = (hs.diemToan*2 + hs.diemVan + hs.diemAnh)/4;
    return hs.diemTB;
}

// hàm phân loại học lực của học sinh dựa vào điểm trung bình
string phanLoai(hocSinh& hs) {
    if(9 <= hs.diemTB)
        return "XUAT SAC";
    else if(8 <= hs.diemTB && hs.diemTB < 9)
        return "GIOI";
    else if(6.5 <= hs.diemTB && hs.diemTB < 8)
        return "KHA";
    else if(5 <= hs.diemTB && hs.diemTB < 6.5)
        return "TRUNG BINH";
    else
        return "YEU";
}

// hàm kiểm tra tính hợp lệ của tên
bool kiemTraTen(string& ten) {
    for(int i = 0; i < ten.length(); i++) {
        if(ten[i] >= '0' && ten[i] <= '9')
            return false;
    }
    return true;
}

// hàm kiểm tra tính hợp lệ của điểm
bool kiemTraDiem(float& diem) {
    if(diem < 0 || diem > 10)
        return false;
    return true;
}

// hàm hiển thị thông tin của học sinh
void hienThi(hocSinh hs) {
    cout << " ho va ten: " << hs.hoVaTen << endl;
    cout << "diem trung binh: " << hs.diemTB << endl;
    cout << "xep loai hoc luc: " << hs.xepLoai << endl;
}

// hàm chuyển chuỗi chữ thành chữ thường
string chuoiChuThuong(string& str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;  
}

// hàm tìm kiếm học sinh theo tên, không phân biệt chữ hoa thường
vector<hocSinh> timKiemTheoTen(vector<hocSinh>& danhSach, string& tuKhoa) {
    vector<hocSinh> ketQua;
    string tuKhoaLowerCase = chuoiChuThuong(tuKhoa);
    
    for (size_t i = 0; i < danhSach.size(); i++) {
        string tenLowerCase = chuoiChuThuong(danhSach[i].hoVaTen);
        size_t viTri = tenLowerCase.find(tuKhoaLowerCase);
        
        if (viTri != (size_t)-1) {
            ketQua.push_back(danhSach[i]);
        }
    }
    return ketQua;
}

int main() {
    vector<hocSinh> cacHocSinh(3);
    // nhập thông tin của 3 học sinh theo thứ tự
    for(int i = 0; i < 3; i++) {
        cout << "HOC SINH THU " << i+1 << endl;
        // nhập tên học sinh
        do{
            cout << "ho va ten: "; getline(cin, cacHocSinh[i].hoVaTen);
            if(!kiemTraTen(cacHocSinh[i].hoVaTen))
                cout << "ten khong hop le!" << endl;
        }
        while(!kiemTraTen(cacHocSinh[i].hoVaTen));
        
        // nhập điểm toán
        do{
            cout << "nhap diem toan: "; cin >> cacHocSinh[i].diemToan;
            if(!kiemTraDiem(cacHocSinh[i].diemToan))
                cout << "diem khong hop le!" << endl;
        }
        while(!kiemTraDiem(cacHocSinh[i].diemToan));
        
        // nhập điểm văn
        do{
            cout << "nhap diem van: "; cin >> cacHocSinh[i].diemVan;
            if(!kiemTraDiem(cacHocSinh[i].diemVan))
                cout << "diem khong hop le!" << endl;
        }
        while(!kiemTraDiem(cacHocSinh[i].diemVan));        
        
        //nhập điểm anh
        do{
            cout << "nhap diem anh: "; cin >> cacHocSinh[i].diemAnh;
            if(!kiemTraDiem(cacHocSinh[i].diemAnh))
                cout << "diem khong hop le!" << endl;
        }
        while(!kiemTraDiem(cacHocSinh[i].diemAnh));

        cin.ignore(); // tránh dấu cách bỏ qua hàm getline()

        // tính điểm trung bình
        cacHocSinh[i].diemTB = diemTrungBinh(cacHocSinh[i]);

        // phân loại học lực của học sinh dựa trên điểm trung bình
        cacHocSinh[i].xepLoai = phanLoai(cacHocSinh[i]);

    }
    // hiển thị danh sách học sinh
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << "HOC SINH THU " << i+1 << endl;
        hienThi(cacHocSinh[i]);
        cout << endl;
    }

    // tìm học sinh có điểm trung bình cao nhất
    float diemCaoNhat = 0;
    for(int i = 0; i < 3; i++)
        if(cacHocSinh[i].diemTB > diemCaoNhat)
            diemCaoNhat = cacHocSinh[i].diemTB;
    for(int i = 0; i < 3; i++) {
        if(cacHocSinh[i].diemTB == diemCaoNhat) {
            cout << "hoc sinh co diem cao nhat la: " << cacHocSinh[i].hoVaTen << endl;
        }
    }

    //tìm học sinh có điểm toán thấp nhất
    float diemToanThapNhat = cacHocSinh[0].diemToan;
    for(int i = 1; i < 3; i++) {
        if(cacHocSinh[i].diemToan < diemToanThapNhat)
            diemToanThapNhat = cacHocSinh[i].diemToan;
    }
    for(int i = 0; i < 3; i++) {
        if(cacHocSinh[i].diemToan == diemToanThapNhat) {
            cout << "hoc sinh co diem toan thap nhat la: " << cacHocSinh[i].hoVaTen << endl;
        }
    }

    // tìm kiếm học sinh theo tên học sinh(có thể viết thường)
    cout << endl;
    string tuKhoa;
    cout << "Nhap tu khoa tim kiem hoc sinh: "; getline(cin, tuKhoa);
    vector<hocSinh> ketQuaTimKiem = timKiemTheoTen(cacHocSinh, tuKhoa);
    if(ketQuaTimKiem.empty())
        cout << "Khong tim thay hoc sinh co ten phu hop voi tu khoa." << endl;
    else{
        for (size_t i = 0; i < ketQuaTimKiem.size(); i++) {
            hienThi(ketQuaTimKiem[i]);
        }
    }
    return 0;
}