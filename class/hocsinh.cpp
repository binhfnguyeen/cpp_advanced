#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class HocSinh{
  private: 
    string ma, ten;
    double diem[10];
  public: 
    void nhap(int stt){
        string tmp = to_string(stt);
        if(tmp.size()==1) tmp = "0" + tmp;
        ma = "HS" + tmp;
        cin.ignore();
        getline(cin, ten);
        for(int i=0; i<10; i++){
            cin >> diem[i];
        }
        cin.ignore();
    }
    double getTB(){
        double tong = 0;
        for(int i=0; i<10; i++){
            tong += diem[i];
        }
        return tong/10;
    }
    void in(){
        double tb = getTB();
        cout << ma << ' ' << ten << ' ' << fixed << setprecision(1) << tb << ' ';
        if(tb>=9) cout << "XUAT SAC\n";
        else if(tb>=8) cout << "GIOI\n";
        else if(tb>=7) cout << "KHA\n";
        else if(tb>=5) cout << "TB\n";
        else cout << "YEU\n";
    }
    string getMa(){
        return ma;
    }
};
bool cmp(HocSinh a, HocSinh b){
    if(a.getTB()!=b.getTB()) {
        return a.getTB() > b.getTB();
    }
    return a.getMa() < b.getMa();
}
int main() {
    int n; cin >> n;
    HocSinh a[n];
    for(int i=0; i<n; i++){
        a[i].nhap(i+1);
    }
    sort(a, a+n, cmp);
    for(HocSinh x: a){
        x.in();
    }
    system("pause");
    return 0;
}
