#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SinhVien{
private: 
    string ten, ns;
    double d1, d2, d3;
public: 
    void nhap(){
        getline(cin, ten);
        getline(cin, ns);
        cin >> d1 >> d2 >> d3;
    }
    void in(){
        cout << ten << ' ' << ns << ' ' << fixed << setprecision(1) << d1+d2+d3 << endl;
    }
};

int main(){
    SinhVien x;
    x.nhap();
    x.in();
    system("pause");
    return 0;
}