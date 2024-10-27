#include <iostream>
#include <string>
using namespace std;
#define ll long long
struct ThiSinh{
    string ten, ns, dc;
    int d1, d2, d3;
    void nhap(){
        scanf("\n");
        getline(cin, this->ten);
        getline(cin, this->ns);
        getline(cin, this->dc);
        cin >> d1 >> d2 >> d3;
    }
    int diemTong(){
        return d1+d2+d3;
    }
    string check(){
        if(this->diemTong()>=24) return "DO";
        else return "TRUOT";
    }
    void in(int k){
        cout << this->ten << " " << this->ns << " " << this->dc << " " << this->diemTong() << " ";
        if(k==1){
            cout << this->check();
        }
        cout << endl;
    }

};
int main(){
    int n; cin >> n;
    ThiSinh a[n];
    int maxDiem=0;
    for(int i=0; i<n; i++){
        a[i].nhap();
        maxDiem=max(maxDiem,a[i].diemTong());
    }
    cout << "DANH SACH THU KHOA:\n";
    for(ThiSinh x: a){
        if(x.diemTong()==maxDiem) {
            x.in(0);
        }
    }
    cout << "KET QUA XET TUYEN:\n";
    for(ThiSinh x: a){
        x.in(1);
    }
    system("pause");
    return 0;
}