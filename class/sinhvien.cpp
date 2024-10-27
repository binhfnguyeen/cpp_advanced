#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
// 5
// Nguyen Van A
// CNTT2
// 19/11/2000
// 3.60
// Nguyen Van B
// CNTT1
// 19/3/1999
// 0.10
// Nguyen Van C
// DTVT2
// 21/11/2001
// 1.30
// Nguyen Van D
// DTVT2
// 20/1/2000
// 2.70
// Nguyen Van E
// DTVT2
// 17/5/2003
// 0.30
class SinhVien{
  private: 
    string ma, ten, lop, ns;
    double gpa;
  public:
    void nhap(int stt){
        string tmp=to_string(stt);
        while(tmp.size()<3) tmp="0"+tmp;
        ma = "SV" + tmp;
        getline(cin, ten);
        getline(cin, lop);
        getline(cin, ns);
        cin >> gpa;
    }
    void in(){
        cout << ma << ' ' << ten << ' ' << lop << ' ' << ns << ' ' << fixed << setprecision(2) << gpa << endl;
    }
    void chuanHoa(){
        if(ns[1]=='/') ns = '0' + ns;
        if(ns[4]=='/') ns.insert(3, "0");
    }
};
int main() {
    int n; cin >> n;
    SinhVien a[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        a[i].nhap(i+1);
        a[i].chuanHoa();
    }
    for(SinhVien x: a){
        x.in();
    }
    system("pause");
    return 0;
}
