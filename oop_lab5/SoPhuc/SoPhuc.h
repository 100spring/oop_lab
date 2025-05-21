#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc{
    private:
        double phan_thuc, phan_ao;
    public:
        friend istream& operator>>(istream& input, SoPhuc& a);
        friend ostream& operator<<(ostream& output, SoPhuc& a);
        SoPhuc operator+(SoPhuc& b);
        SoPhuc operator-(SoPhuc& b);
        SoPhuc operator*(SoPhuc& b);
        SoPhuc operator/(SoPhuc& b);
        bool operator==(SoPhuc& b);
        bool operator!=(SoPhuc& b);
};

