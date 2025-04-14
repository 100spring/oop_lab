#include "GioPhutGiay.h"

// Kiểm tra tính hợp lệ của thời gian
// Giới hạn giờ nhỏ hơn 24, phút và giây nhỏ hơn 60
bool gioPhutGiay::KiemTra(){
    if(iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59)
        return false;
    return true;
}

void gioPhutGiay::Nhap(){
    cout << "Nhập một thời điểm." << endl;
    do{
        cout << "Nhập giờ: "; cin >> iGio;
        cout << "Nhập phút: "; cin >> iPhut;
        cout << "Nhập giây: "; cin >> iGiay;
        if(!KiemTra())
            cout << "Giờ không hợp lệ. Vui lòng nhập lại." << endl;
    }
    while(!KiemTra());
}

void gioPhutGiay::Xuat(){
    cout << iGio << ":" << iPhut << ":" << iGiay << endl;
}

gioPhutGiay gioPhutGiay::TinhCongThemMotGiay(){
    // trường hợp đang ở giây 59
    if(iGiay == 59){
        iGiay = 0;
        // nếu đang ở phút 59
        if(iPhut == 59){
            iPhut = 0;
            // nếu đang ở giờ 23
            if(iGio == 23)
                iGio = 0;
            else 
                iGio++;
        }
        else 
            iPhut++;
    }
    // trường hợp thường
    else 
        iGiay++;

    return *this;
}