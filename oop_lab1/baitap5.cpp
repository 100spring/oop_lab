#include <iostream>
using namespace std;

struct day {
    int date, month, year;
};

// kiểm tra năm nhuận, đầu vào là năm, xuất ra kết quả đúng hoặc sai
bool leapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

// hàm kiểm tra ngày được nhập vào hợp lệ hay không
bool kiemTraNgayHopLe(day d) {
    if (d.year < 1)
        return false;
    if (d.month < 1 || d.month > 12)
        return false;
    if (d.date < 1 || d.date > 31)
        return false;
    // Kiểm tra các tháng có 30 ngày
    if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        if (d.date > 30)
            return false;
    }
    // Kiểm tra tháng 2
    if (d.month == 2) {
        if (leapYear(d.year)) {
            if (d.date > 29)
                return false;
        } else {
            if (d.date > 28)
                return false;
        }
    }
    
    return true;
}

// hàm nhập ngày
void nhapNgay(day &d) {  
    do{
        cout << "nhap ngay thang nam!" << endl;
        cout << "nhap ngay: "; cin >> d.date;
        cout << "nhap thang: "; cin >> d.month;
        cout << "nhap nam "; cin >> d.year;
        if(!kiemTraNgayHopLe(d))
            cout << "Ngay khong hop le. Vui long nhap lai.";
    }
    while(!kiemTraNgayHopLe(d));
}

// hàm xuất ngày
void xuatNgay(day d) {
    cout << d.date << "/" << d.month << "/" << d.year;
}

// đếm ngày thứ bao nhiêu trong năm, đầu vào là biến kiểu dữ liệu ngày
// đầu ra là kết quả ngày thứ bao nhiêu trong năm
int dayCounting(day d) {
    int res = 0;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(leapYear(d.year))
        days[1] = 29;
    
    for(int i = 0; i < d.month-1; i++) {
        res += days[i];
    }
    
    return res + d.date;
}

// hàm tìm ngày tiếp theo
// đầu vào là một ngày, xuất ra kết quả là ngày tiếp theo
day nextDay(day d) {
    //xét trường hợp tháng 2
    if(d.month == 2) {
        if(leapYear(d.year)) {      
            if(d.date == 29) {
                d.date = 1;
                d.month = 3;
                return d;
            }
            else {
                d.date++;
                return d;
            }
        }
        else {
            if(d.date == 28) {
                d.date = 1;
                d.month = 3;
                return d;
            }
            else {
                d.date++;
                return d;
            }
        }
    }
    // xét trường hợp tháng 12
    else if(d.month == 12) {
        if(d.date == 31) {
            d.date = 1;
            d.month = 1;
            d.year++;
            return d;
        }
        else {
            d.date++;
            return d;
        }
    }
    else{
        switch (d.month)
        {
        // tháng có 31 ngày
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(d.date == 31) {
                d.date = 1;
                d.month++;
                return d;
            }
            else {
                d.date++;
                return d;
            }
            break;
        // tháng có 30 ngày
        default:
            if(d.date == 30) {
                d.date = 1;
                d.month++;
                return d;
            }
            else {
                d.date++;
                return d;
            }
            break;
        }
    }
}

// hàm tìm ngày trước đó
// đầu vào là một ngày, xuất ra kết quả là ngày trước đó
day dayBefore(day d) {
    // xét trường hợp tháng 3
    if(d.month == 3) {
        if(leapYear(d.year)) {
            if(d.date == 1) {
                d.date = 29;
                d.month = 2;
                return d;
            }
            else {
                d.date--;
                return d;  
            }
        }
        else {
            if(d.date == 1) {
                d.date = 28;
                d.month = 2;
                return d;
            }
            else {
                d.date--;
                return d;  
            }
        }
    }
    // xét trường hợp tháng 1
    else if(d.month == 1) {
        if(d.date == 1) {
            d.date = 31;
            d.month = 12;
            d.year--;
            return d;
        }
        else {
            d.date--;
            return d;
        }
    }
    else {
        switch (d.month)
        {
        // Những tháng mà tháng trước nó có 30 ngày
        case 5:  
        case 7:  
        case 10: 
        case 12: 
            if(d.date == 1) {
                d.date = 30;
                d.month--;
                return d;
            }
            else {
                d.date--;
                return d;
            }
            break;
        
        // Những tháng mà tháng trước có 31 ngày
        case 2:  
        case 4:  
        case 6:  
        case 8:  
        case 9:  
        case 11: 
            if(d.date == 1) {
                d.date = 31;
                d.month--;
                return d;
            }
            else {
                d.date--;
                return d;
            }
            break;
        
        default:
            d.date--;
            return d;
            break;
        }
    }
}

int main(){
    day d, dTemp;
    nhapNgay(d);
    
    cout << "day la ngay thu " << dayCounting(d) << " trong nam" << endl;
    
    dTemp = nextDay(d);
    cout << "ngay tiep theo la: ";
    xuatNgay(dTemp);
    cout << endl;

    dTemp = dayBefore(d);
    cout << "ngay truoc do la: ";
    xuatNgay(dTemp);
    cout << endl;
    
    return 0;
}