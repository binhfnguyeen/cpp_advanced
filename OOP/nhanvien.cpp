#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class NhanVien{
private: 
    string ma, name, gt, ns, dc, hdong, msthue;
public: 
    void nhap(){
        this->ma="00001";
        getline(cin, this->name);
        getline(cin, this->gt);
        getline(cin, this->ns);
        getline(cin, this->dc);
        getline(cin, this->hdong);
        getline(cin, this->msthue);
    }
    string chuanHDate(string s){
        if(s[2]!='/') s="0"+s;
        if(s[5]!='/') s.insert(3, "0");
        return s;
    }
    string chuanHTen(string name){
        stringstream ss(name);
        string tmp;
        string res="";
        while(ss >> tmp){
            tmp[0] = toupper(tmp[0]);
            for(int i=1; i<tmp.size(); i++){
                tmp[i] = tolower(tmp[i]);
            }
            res+=tmp;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
    void in(){
        cout << this->ma << ' ';
        cout << chuanHTen(this->name) << ' ';
        cout << this->gt << ' ';
        cout << chuanHDate(this->ns) << ' ';
        cout << chuanHTen(this->dc) << ' ';
        cout << chuanHDate(this->hdong) << ' ';
        cout << this->msthue << ' ';
    }
};

int main(){
    NhanVien x;
    x.nhap();
    x.in();
    system("pause");
    return 0;
}