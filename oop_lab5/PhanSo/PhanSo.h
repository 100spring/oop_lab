#include <iostream>
using namespace std;

class PhanSo{
    private:
        int tu_so, mau_so;
    public:
        friend istream& operator>>(istream& in, PhanSo& a);
        friend ostream& operator<<(ostream& out, PhanSo& a);
        PhanSo ChuanHoa(PhanSo& a);
        PhanSo operator+(PhanSo& b);
        PhanSo operator-(PhanSo& b);
        PhanSo operator*(PhanSo& b);
        PhanSo operator/(PhanSo& b);
        bool operator==(PhanSo& b);
        bool operator<(PhanSo& b);
        bool operator>(PhanSo& b);
};