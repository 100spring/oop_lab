#include "GioPhutGiay.h"

istream& operator>>(istream& in, CTime& t){
    cout << "Nhập giờ: "; in >> t.hrs;
    cout << "Nhập phút: "; in >> t.min;
    cout << "Nhập giây: "; in >> t.sec;
    return in;
}

ostream& operator<<(ostream& out, CTime& t){
    out << t.hrs << ":" << t.min << ":" << t.sec;
    return out;
}

CTime CTime::ChuanHoa(CTime t){
    int total = hrs * 3600 + min * 60 + sec;
    if (total < 0) total = 0;
    hrs = total / 3600;
    total %= 3600;
    min = total / 60;
    sec = total % 60;
}

CTime CTime::operator+(int a){
    CTime temp = *this;
    int total = temp.hrs * 3600 + temp.min * 60 + temp.sec + a;
    if (total < 0) total = 0;
    temp.hrs = total / 3600;
    total %= 3600;
    temp.min = total / 60;
    temp.sec = total % 60;
    return temp;
}

CTime CTime::operator-(int a) {
    return *this + (-a);
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    *this = *this + 1;
    return temp;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    *this = *this - 1;
    return temp;
}