#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class NhanVien{
  private: 
    string ma, ten, ns, gt, dc, mst, hd;
  public:
    void nhap(int stt){
        string tmp = to_string(stt);
        while(tmp.size()<5) tmp="0"+tmp;
        ma = tmp;
        getline(cin, ten);
        getline(cin, gt);
        getline(cin, ns);
        getline(cin, dc);
        getline(cin, mst);
        getline(cin, hd);
    }
    void chuanHoa(){
        if(ns[1]=='/') ns="0"+ns;
        if(ns[4]=='/') ns.insert(3, "0");
        if(hd[1]=='/') hd="0"+hd;
        if(hd[4]=='/') hd.insert(3, "0");
    }
    void in(){
        cout << ma << ' ' << ten << ' ' << gt << ' ' << ns << ' ' << dc << ' ' << mst << ' ' << hd << endl;
    }
    string getNs(){
        return ns;
    }
    string getMa(){
        return ma;
    }
};
vector <int> getDate(string s){
    vector <int> res;
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp, '/')){
        res.push_back(stoi(tmp));
    }
    return res;
}
bool cmp(NhanVien a, NhanVien b){
    vector <int> v1 = getDate(a.getNs()), v2 = getDate(b.getNs());
    for(int i=2; i>=0; i--){
        if(v1[i] != v2[i]) {
            return v1[i] < v2[i];
        }
    }
    return a.getMa() < b.getMa();
}
int main() {
    int n; cin >> n;
    NhanVien a[n];
    cin.ignore();
    for(int i=0; i<n; i++){
        a[i].nhap(i+1);
        a[i].chuanHoa();
    }
    sort(a, a+n, cmp);
    for(NhanVien x: a){
        x.in();
    }
    system("pause");
    return 0;
}
