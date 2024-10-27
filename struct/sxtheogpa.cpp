#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
#define ll long long
struct SinhVien{
    string ten, ns, dc;
    double gpa;
    void nhap(){
        scanf("\n");
        getline(cin, this->ten);
        getline(cin, this->ns);
        getline(cin, this->dc);
        cin >> gpa;
    }
    // Nạp chồng;
    /*
    bool operator > (SinhVien b){
        return this->gpa > b.gpa;
    }
    */
    void in(){
        cout << ten << " " << ns << " " << dc << " " << fixed << setprecision(2) << gpa << endl;
    }
};
//Sài stable_sort thì không được nạp chồng <3;
bool cmp(SinhVien a, SinhVien b) {
    return a.gpa > b.gpa;
}
int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i=0; i<n; i++){
        a[i].nhap();
    }
    stable_sort(a, a+n, cmp);
    for(SinhVien x: a){
        x.in();
    }
    system("pause");
    return 0;
}