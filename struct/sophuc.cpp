#include <iostream>
using namespace std;
#define ll long long
struct SoPhuc {
    ll thuc, ao;
    SoPhuc(ll thuc, ll ao){
        this->thuc=thuc;
        this->ao=ao;
    }
    SoPhuc operator + (SoPhuc b){
        ll t1=this->thuc+b.thuc;
        ll a1=this->ao+b.ao;
        return SoPhuc{t1,a1};
    }
    SoPhuc operator - (SoPhuc b){
        ll t1=this->thuc-b.thuc;
        ll a1=this->ao-b.ao;
        return SoPhuc{t1,a1};
    }
    SoPhuc operator * (SoPhuc b){
        ll t1=this->thuc*b.thuc-this->ao*b.ao;
        ll a1=this->thuc*b.ao+this->ao*b.thuc;
        return SoPhuc{t1,a1};
    }
    friend ostream& operator << (ostream &out, SoPhuc x){
        out << x.thuc << " " << x.ao << endl;
        return out;
    }
};
int main(){
    ll t1, a1, t2, a2;
    cin >> t1 >> a1 >> t2 >> a2;
    SoPhuc a(t1, a1);
    SoPhuc b(t2, a2);
    SoPhuc tong=a+b;
    SoPhuc hieu=a-b;
    SoPhuc tich=a*b;
    cout << tong << hieu << tich;
    system("pause");
    return 0;
}