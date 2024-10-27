#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
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
    int thang(){
        stringstream ss(this->ns);
        string tmp;
        int cnt=1;
        while(getline(ss,tmp, '/')){
            if(cnt==2) return stoi(tmp);
            cnt++;
        }
    }
    void in(){
        cout << ten << " " << ns << " " << dc << " " << fixed << setprecision(2) << gpa << endl;
    }
};
int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i=0; i<n; i++){
        a[i].nhap();
    }
    for(SinhVien x: a){
        if(x.thang()==4) {
            x.in();
        }
    }
    system("pause");
    return 0;
}