#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct SinhVien{
    private: 
        string ma, ten, lop, ns;
        double gpa;
    public: 
        void nhap(){
            this->ma = "SV001";
            getline(cin, this->ten);
            getline(cin, this->lop);
            getline(cin, this->ns);
            cin >> this->gpa;
        }
        void chuanHoa(){
            if(this->ns[1]=='/') this->ns = "0"+this->ns;
            if(this->ns[4]=='/') this->ns.insert(3, "0");
        }
        void in(){
            cout << this->ma << ' ' << this->ten << ' ' << this->lop << ' ' << this->ns <<' ' << fixed << setprecision(1) << this->gpa << endl;
        }
};
int main(){
    SinhVien x;
    x.nhap();
    x.chuanHoa();
    x.in();
    system("pause");
    return 0;
}