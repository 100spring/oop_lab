#include "PhanSo.h"

istream& operator>>(istream& in, PhanSo& a){
    cout << "Nhập tử số: "; in >> a.tu_so;
    cout << "Nhập mẫu số: "; in >> a.mau_so;
    return in;
}

ostream& operator<<(ostream& out, PhanSo& a){
    if(a.mau_so > 0)
        out << a.tu_so << "/" << a.mau_so;
    else 
        out << -a.tu_so << "/" << -a.mau_so;
    return out;
}

PhanSo PhanSo::ChuanHoa(PhanSo& a){
    int tu = abs(a.tu_so);
    int mau = abs(a.mau_so);
    while(tu != mau){
        if(tu > mau)
            tu -= mau;
        else 
            mau -= tu;
    }
    a.tu_so /= tu;
    a.mau_so /= mau;
    if(a.mau_so < 0){
        a.tu_so = -a.tu_so;
        a.mau_so = -a.mau_so;
    }
    return a;
}

PhanSo PhanSo::operator+(PhanSo& b){
    PhanSo temp;
    temp.tu_so = tu_so*b.mau_so + b.tu_so*mau_so;
    temp.mau_so = mau_so*b.mau_so;
    return PhanSo::ChuanHoa(temp);
}

PhanSo PhanSo::operator-(PhanSo& b){
    PhanSo temp;
    temp.tu_so = tu_so*b.mau_so - b.tu_so*mau_so;
    temp.mau_so = mau_so*b.mau_so;
    return PhanSo::ChuanHoa(temp);
}

PhanSo PhanSo::operator*(PhanSo& b){
    PhanSo temp;
    temp.tu_so = tu_so*b.tu_so;
    temp.mau_so = mau_so*b.mau_so;
    return PhanSo::ChuanHoa(temp);
}

PhanSo PhanSo::operator/(PhanSo& b){
    PhanSo temp;
    temp.tu_so = tu_so*b.mau_so;
    temp.mau_so = mau_so*b.tu_so;
    return PhanSo::ChuanHoa(temp);
}

bool PhanSo::operator==(PhanSo& b){
    return tu_so*b.mau_so - b.tu_so*mau_so == 0;
}

bool PhanSo::operator<(PhanSo& b){
    return tu_so*b.mau_so - b.tu_so*mau_so < 0;
}

bool PhanSo::operator>(PhanSo& b){
    return tu_so*b.mau_so - b.tu_so*mau_so > 0;
}