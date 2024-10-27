#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    while(b) {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
struct PhanSo{
    ll tu, mau;
    void nhap() {
        cin >> this->tu >> this->mau;
    }
    void toiGian(){
        ll k=gcd(this->tu,this->mau);
        this->tu/=k;
        this->mau/=k;
        if(this->mau<0) {
            this->tu*=-1;
            this->mau*=-1;
        }
    }
    PhanSo operator + (PhanSo b){
        ll mc = this->mau * b.mau;
        ll t1 = this->tu*b.mau+this->mau*b.tu;
        PhanSo res{t1,mc};
        res.toiGian();
        return res;
    }
    PhanSo operator - (PhanSo b){
        ll mc = this->mau * b.mau;
        ll t1 = this->tu*b.mau-this->mau*b.tu;
        PhanSo res{t1,mc};
        res.toiGian();
        return res;
    }
    void in(){
        cout << this->tu << "/" << this->mau << endl;
    }
};

int main(){
    PhanSo a, b;
    a.nhap(); b.nhap();
    a.toiGian(); b.toiGian();
    a.in(); b.in();
    PhanSo tong=a+b;
    tong.in();
    PhanSo hieu=a-b;
    hieu.in();
    system("pause");
    return 0;
}