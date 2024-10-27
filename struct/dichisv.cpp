#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
struct Tinh{
    string tenTinh;
    int soLuong;
    bool operator < (Tinh b){
        if(this->soLuong != b.soLuong){
            return this->soLuong > b.soLuong;
        }
        return this->tenTinh < b.tenTinh;
    }
};
vector <Tinh> t;
int tim(string tenTinh){
    for(int i=0; i<t.size(); i++){
        if(t[i].tenTinh==tenTinh) return i;
    }
    return -1;
}
struct SinhVien{
    string ten, ns;
    Tinh dc;
    double gpa;
    void nhap(){
        scanf("\n");
        getline(cin, this->ten);
        getline(cin, this->ns);
        getline(cin, this->dc.tenTinh);
        int index=tim(this->dc.tenTinh);
        if(index!=-1) {
            t[index].soLuong++;
        } else {
            t.push_back(Tinh{this->dc.tenTinh, 1});
        }
        cin >> gpa;
    }
};
int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i=0; i<n; i++){
        a[i].nhap();
    }
    sort(t.begin(), t.end());
    int maxSoLuong=t[0].soLuong;
    for(Tinh x: t){
        if(x.soLuong == maxSoLuong) {
            cout << x.tenTinh << endl;
        }
    }
    system("pause");
    return 0;
}