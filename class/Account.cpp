#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Account{
  private: 
    string username, password, ten, vao, ra;
  public:
    void nhap(){
        getline(cin, username);
        getline(cin, password);
        getline(cin, ten);
        getline(cin, vao);
        getline(cin, ra);
    }
    int getGioChoi(){
        int hvao = stoi(vao.substr(0, 2));
        int mvao = stoi(vao.substr(3, 2));
        int hra = stoi(ra.substr(0, 2));
        int mra = stoi(ra.substr(3, 2));
        return (hra*60+mra) - (hvao*60+mvao);
    }
    void in(){
        int minute = getGioChoi();
        cout << username << ' ' << password << ' ' << ten << ' ' << minute/60 << " gio " << minute%60 << " phut " << endl;
    }
    string getUsername(){
        return username;
    }
};
bool cmp(Account a, Account b){
    if(a.getGioChoi() != b.getGioChoi()){
        return a.getGioChoi() > b.getGioChoi();
    }
    return a.getUsername() < b.getUsername();
}
int main() {
    int n; cin >> n;
    Account a[n];
    cin.ignore();
    for(int i=0; i<n; i++){
        a[i].nhap();
    }
    sort(a, a+n, cmp);
    for(Account x: a){
        x.in();
    }
    system("pause");
    return 0;
}
