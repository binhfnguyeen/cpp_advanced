#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <sstream>
using namespace std;
string chuan_hoa_Ten(string s){
    stringstream ss(s);
    string tmp, res="";
    while(ss >> tmp) {
        tmp[0]=toupper(tmp[0]);
        for(int i=1; i<tmp.size(); i++){
            tmp[i]tolower(tmp[i]);
        }
        res+=tmp;
        res+=' ';
    }
    res.pop_back();
    return res;
}
string chuan_hoa_ngay(string s){
    if(s[2]!='/') s='0'+s;
    if(s[5]!='/') s=s.insert(3, "0");
    return s;
}
int main(){
    string name, ngay;
    cout << "Nhap ten: " << endl;
    getline(cin, name);
    cout << "Nhap ngay sinh: " << endl;
    cin >> ngay;
    name=chuan_hoa_Ten(name);
    ngay=chuan_hoa_ngay(ngay);
    cout << "Ten: " << name << endl;
    cout << "Date: " << ngay << endl;
    system("pause");
    return 0;
}