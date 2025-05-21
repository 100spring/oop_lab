#include "NgayThangNam.h"

istream& operator>>(istream& in, CDate& a){
    cout << "Nhập ngày: "; in >> a.ngay;
    cout << "Nhập tháng: "; in >> a.thang;
    cout << "Nhập năm: "; in >> a.nam;
    return in;
}

ostream& operator<<(ostream& out, CDate& a){
    out << a.ngay << "/" << a.thang << "/" << a.nam;
    return out;
}

CDate CDate::operator+(int n){
    CDate res;
    res.fromDays(this->toDays() + n);
    return res;
}

CDate CDate::operator-(int n){
    CDate res;
    res.fromDays(this->toDays() + n);
    return res;
}

CDate CDate::operator++(int){
    CDate temp = *this;
    *this = *this + 1;
    return temp;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
        *this = *this - 1;
        return temp;
}
