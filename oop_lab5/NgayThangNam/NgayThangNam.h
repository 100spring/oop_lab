#include <iostream>
#include <cmath>
using namespace std;

class CDate{
    private:
        int ngay, thang, nam;

        bool isLeapYear(int y) const {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        }

        int daysInMonth(int m, int y) const {
            static int d[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if (m == 2 && isLeapYear(y)) return 29;
            return d[m - 1];
        }

        void fromDays(int totalDays) {
            nam = 1;
            while (true) {
                int daysInYear = isLeapYear(nam) ? 366 : 365;
                if (totalDays > daysInYear) {
                    totalDays -= daysInYear;
                    nam++;
                } else break;
            }

            thang = 1;
            while (true) {
                int dim = daysInMonth(thang, nam);
                if (totalDays > dim) {
                    totalDays -= dim;
                    thang++;
                } else break;
            }
            ngay = totalDays;
        }

        int toDays() const {
            int days = ngay;
            for (int y = 1; y < nam; ++y)
                days += isLeapYear(y) ? 366 : 365;
            for (int m = 1; m < thang; ++m)
                days += daysInMonth(m, nam);
            return days;
        }
    public:
        CDate(int d = 1, int m = 1, int y = 1) : ngay(d), thang(m), nam(y) {}
        CDate operator+(int n);
        CDate operator-(int n);
        CDate operator++(int);
        CDate operator--(int);
        friend istream& operator>>(istream& in, CDate& a);
        friend ostream& operator<<(ostream& out, CDate& a);
};