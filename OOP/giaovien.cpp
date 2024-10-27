#include <iostream>
#include <string>
using namespace std;

class GiaoVien{
    private: 
        string mangach;
        string hoten;
        long long luongcoban;
        long long phucap;
    public: 
        long long tinhluong(){
            long long hsluong=stoll(this->mangach.substr(2,2));
            if(this->mangach.substr(0,2)=="HT"){
                this->phucap=2000000;
            } else if(this->mangach.substr(0,2)=="HP"){
                this->phucap=900000;
            } else if(mangach.substr(0,2)=="GV"){
                this->phucap=500000;
            }
            return this->luongcoban*hsluong+this->phucap;
        }
        void nhap(){
            getline(cin, this->mangach);
            getline(cin, this->hoten);
            cin >> luongcoban;
            cin >> phucap;
        }
        void in(){
            long long luong=tinhluong();
            cout << this->mangach << ' ';
            cout << this->hoten << ' ';
            cout << stoi(mangach.substr(2,2)) << ' ';
            cout << luong << endl;
        }
};

int main(){
    GiaoVien x;
    x.nhap();
    x.in();
    system("pause");
    return 0;
}