#include "DaThuc.h"

istream& operator>>(istream& in, DaThuc& dt){
    int bac;
    cout << "Nhap bac cua da thuc: ";
    in >> bac;
    dt.heso.resize(bac + 1);
    for (int i = bac; i >= 0; --i) {
        cout << "He so bac " << i << ": ";
        in >> dt.heso[i];
    }
    return in;
}

ostream& operator<<(ostream& out, DaThuc& dt){
    bool first = true;
    for (int i = dt.heso.size() - 1; i >= 0; --i) {
        if (dt.heso[i] != 0) {
            if (!first && dt.heso[i] > 0) out << " + ";
            if (dt.heso[i] < 0) out << " - ";
            if (abs(dt.heso[i]) != 1 || i == 0)
                out << abs(dt.heso[i]);
            if (i > 0) out << "x";
            if (i > 1) out << "^" << i;
            first = false;
        }
    }
    if (first) out << "0";
    return out;
}

DaThuc DaThuc::operator+(DaThuc& other){
    int maxBac = max(heso.size(), other.heso.size());
    DaThuc result;
    result.heso.resize(maxBac, 0);
    for (int i = 0; i < maxBac; ++i) {
        double a = (i < heso.size()) ? heso[i] : 0;
        double b = (i < other.heso.size()) ? other.heso[i] : 0;
        result.heso[i] = a + b;
    }
    return result;
}

DaThuc DaThuc::operator-(DaThuc& other){
    int maxBac = max(heso.size(), other.heso.size());
    DaThuc result;
    result.heso.resize(maxBac, 0);
    for (int i = 0; i < maxBac; ++i) {
        double a = (i < heso.size()) ? heso[i] : 0;
        double b = (i < other.heso.size()) ? other.heso[i] : 0;
        result.heso[i] = a - b;
    }
    return result;
}