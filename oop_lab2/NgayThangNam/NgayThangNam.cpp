#include "NgayThangNam.h"

void ngayThangNam::Nhap(){
    cout << "Nhap ngay thang nam(DD MM YYYY): ";
    cin >> iNgay >> iThang >> iNam;
}

void ngayThangNam::Xuat(){
    cout << iNgay << "/" << iThang << "/" << iNam;
}

ngayThangNam ngayThangNam::NgayThangNamTiepTheo(){
    // xét trường hợp tháng 2
    if(iThang == 2){
        // nếu là năm nhuận
        if((iNam%4==0 && iNam%100!=0) || (iNam%400==0)){
            if(iNgay == 29){
                iNgay = 1;
                iThang = 3;
                return *this;
            }
            else{
                iNgay++;
                return *this;
            }
        }
        // nếu không là năm nhuận
        else{
            if(iNgay == 28){
                iNgay = 1;
                iThang = 3;
                return *this;
            }
            else{
                iNgay++;
                return *this;
            }
        }
    }
    // xét trường hợp tháng 12
    else if(iThang == 12){
        if(iNgay == 31){
            iNgay = 1;
            iThang = 1;
            iNam++;
            return *this;
        }
        else{
            iNgay++;
            return *this;
        }
    }
    else{
        switch(iThang){
            // tháng có 31 ngày
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                if(iNgay == 31){
                    iNgay = 1;
                    iThang++;
                    return *this;
                }
                else{
                    iNgay++;
                    return *this;
                }
                break;
            // tháng có 30 ngày    
            default:
            if(iNgay == 30){
                iNgay = 1;
                iThang++;
                return *this;
            }
            else{
                iNgay++;
                return *this;
            }
            break;
        }
    }
}

// hàm kiểm tra năm nhuận
bool NamNhuan(int nam){
    if((nam%4==0 && nam%100!=0) || (nam%400==0))
        return true;
    return false;
}