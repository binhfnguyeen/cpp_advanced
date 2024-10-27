#include <iostream>
#include <algorithm>
using namespace std;
struct PhanSo {
    int tu;
    int mau;
};
PhanSo rutgon(PhanSo p){
    int gcd=__gcd(p.tu, p.mau);
    p.tu/=gcd;
    p.mau/=gcd;
    return p;
}
PhanSo cong(PhanSo p1, PhanSo p2){
    PhanSo p;
    p.tu=p1.tu*p2.mau+p1.mau*p2.tu;
    p.mau=p1.mau*p2.mau;
    return rutgon(p);
}
PhanSo tru(PhanSo p1, PhanSo p2){
    PhanSo p;
    p.tu=p1.tu*p2.mau-p1.mau*p2.tu;
    p.mau=p1.mau*p2.mau;
    return rutgon(p);
}
PhanSo nhan(PhanSo p1, PhanSo p2){
    PhanSo p;
    p.tu=p1.tu*p2.tu;
    p.mau=p1.mau*p2.mau;
    return rutgon(p);
}
PhanSo chia(PhanSo p1, PhanSo p2){
    PhanSo p;
    p.tu=p1.tu*p2.mau;
    p.mau=p2.tu*p1.tu;
    return rutgon(p);
}
void xuat(PhanSo p) {
    cout << p.tu << "/" << p.mau << endl;
}
int main() {
    PhanSo p1, p2;
    cout << "Phan so 1: " << endl;
    cin >> p1.tu >> p1.mau;
    xuat(p1);
    cout << endl;
    cout << "Phan so 2: " << endl;
    cin >> p2.tu >> p2.mau;
    xuat(p2);
    cout << endl;
    cout << "p1 + p2= ";
    xuat(cong(p1, p2));
    cout << "p1 - p2= ";
    xuat(tru(p1, p2));
    cout << "p1 * p2= ";
    xuat(nhan(p1, p2));
    cout << "p1 / p2= ";
    xuat(chia(p1, p2));
    system("pause");
    return 0;

}