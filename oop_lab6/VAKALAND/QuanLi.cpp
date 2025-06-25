#include "QuanLi.h"

void QuanLi::Nhap() {
    int n;

    cout << "NHAP GIAO DICH DAT\n";
    cout << "So luong giao dich dat: "; cin >> n;
    dsDat.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Giao dich dat thu " << i + 1 << ":\n";
        dsDat[i].Nhap();
    }

    cout << "NHAP GIAO DICH NHA\n";
    cout << "So luong giao dich nha: "; cin >> n;
    dsNha.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Giao dich nha thu " << i + 1 << ":\n";
        dsNha[i].Nhap();
    }

    cout << "NHAP GIAO DICH CHUNG CU\n";
    cout << "So luong giao dich chung cu: "; cin >> n;
    dsCC.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Giao dich chung cu thu " << i + 1 << ":\n";
        dsCC[i].Nhap();
    }
}

void QuanLi::Xuat() {
    cout << "DANH SACH GIAO DICH DAT\n";
    for (int i = 0; i < dsDat.size(); i++) {
        cout << "Giao dich thu " << i + 1 << ":\n";
        dsDat[i].Xuat();
    }

    cout << "DANH SACH GIAO DICH NHA\n";
    for (int i = 0; i < dsNha.size(); i++) {
        cout << "Giao dich thu " << i + 1 << ":\n";
        dsNha[i].Xuat();
    }

    cout << "\nDANH SACH GIAO DICH CHUNG CU\n";
    for (int i = 0; i < dsCC.size(); i++) {
        cout << "Giao dich thu " << i + 1 << ":\n";
        dsCC[i].Xuat();
    }
}

void QuanLi::ThongKe() {
    cout << "TONG SO LUONG GIAO DICH:\n";
    cout << "Giao dich dat: " << dsDat.size() << endl;
    cout << "Giao dich nha: " << dsNha.size() << endl;
    cout << "Giao dich chung cu: " << dsCC.size() << endl;
}

void QuanLi::TrungBinhChungCu() {
    double sum = 0;
    for (int i = 0; i < dsCC.size(); i++) {
        sum += dsCC[i].TinhTien();
    }
    if (!dsCC.empty()) {
        cout << "\nTRUNG BINH THANH TIEN GIAO DICH CHUNG CU: ";
        cout << sum / dsCC.size() << endl;
    } else {
        cout << "\nKHONG CO GIAO DICH CHUNG CU.\n";
    }
}

void QuanLi::NhaCaoNhat() {
    if (dsNha.empty()) {
        cout << "\nKHONG CO GIAO DICH NHA.\n";
        return;
    }

    int index = 0;
    double maxVal = dsNha[0].TinhTien();

    for (int i = 1; i < dsNha.size(); i++) {
        if (dsNha[i].TinhTien() > maxVal) {
            maxVal = dsNha[i].TinhTien();
            index = i;
        }
    }

    cout << "\nGIAO DICH NHA CO THANH TIEN CAO NHAT:\n";
    dsNha[index].Xuat();
}

void QuanLi::GiaoDichThang12() {
    cout << "\nDANH SACH GIAO DICH THANG 12 NAM 2024:\n";

    auto checkThang12 = [](const string& ngay) {
        if (ngay.length() < 10) return false;

        int thang = stoi(ngay.substr(3, 2));
        int nam = stoi(ngay.substr(6, 4));

        return thang == 12 && nam == 2024;
    };

    for (int i = 0; i < dsDat.size(); i++) {
        if (checkThang12(dsDat[i].getNgayGD())) {
            dsDat[i].Xuat();
        }
    }

    for (int i = 0; i < dsNha.size(); i++) {
        if (checkThang12(dsNha[i].getNgayGD())) {
            dsNha[i].Xuat();
        }
    }

    for (int i = 0; i < dsCC.size(); i++) {
        if (checkThang12(dsCC[i].getNgayGD())) {
            dsCC[i].Xuat();
        }
    }
}