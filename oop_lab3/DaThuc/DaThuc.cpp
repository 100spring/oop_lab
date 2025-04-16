#include "DaThuc.h"

void DaThuc::Nhap(){
    int p;
    cout << "Bậc cao nhất của đa thức: "; cin >> p;
    DSDonThuc.resize(p+1);

    for(int i = 0; i <= p; i++){
        DSDonThuc[i].Nhap();
    }
    cout << endl;
}

void DaThuc::Xuat(){
    for(int i = 0; i <= DSDonThuc.size(); i++){
        cout << (i == 0 ? "" : " + ");
        DSDonThuc[i].Xuat();
    }
    cout << endl;
}

void DaThuc::TinhGiaTri(){
    int x;
    cout << "Giá trị của x: "; cin >> x;
    
    int sum = 0;
    for(int i = 0; i <= DSDonThuc.size(); i++){
        sum += pow(x, DSDonThuc[i].getBac()) * DSDonThuc[i].getHeSo();
    }

    cout << "Giá trị của đa thức với giá trị x = " << x << " là: " << sum << endl << endl;
}

DaThuc DaThuc::Cong(DaThuc &p1, DaThuc &p2){
    DaThuc result;

    for(int i = 0; i < p1.DSDonThuc.size(); i++){
        result.DSDonThuc.push_back(p1.DSDonThuc[i]);
    }

    for(int i = 0; i < p2.DSDonThuc.size(); i++){
        int bac = p2.DSDonThuc[i].getBac();
        double heso = p2.DSDonThuc[i].getHeSo();
        bool found = false;
        
        for(int j = 0; j < result.DSDonThuc.size(); j++){
            if(result.DSDonThuc[j].getBac() == bac){
                double newHeSo = result.DSDonThuc[j].getHeSo() + heso;
                result.DSDonThuc[j] = DonThuc(bac, newHeSo);
                found = true;
                break;
            }
        }
        
        if(!found) {
            result.DSDonThuc.push_back(DonThuc(bac, heso));
        }
    }
    return result;
}

DaThuc DaThuc::Tru(DaThuc &p1, DaThuc &p2){
    DaThuc result;

    for(int i = 0; i < p1.DSDonThuc.size(); i++){
        result.DSDonThuc.push_back(p1.DSDonThuc[i]);
    }

    for(int i = 0; i < p2.DSDonThuc.size(); i++){
        int bac = p2.DSDonThuc[i].getBac();
        double heso = p2.DSDonThuc[i].getHeSo();
        bool found = false;
        
        for(int j = 0; j < result.DSDonThuc.size(); j++){
            if(result.DSDonThuc[j].getBac() == bac){
                double newHeSo = result.DSDonThuc[j].getHeSo() - heso;
                result.DSDonThuc[j] = DonThuc(bac, newHeSo);
                found = true;
                break;
            }
        }
        
        if(!found) {
            result.DSDonThuc.push_back(DonThuc(bac, -heso));
        }
    }
    return result;
}