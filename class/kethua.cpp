#include <iostream>
#include <string>
using namespace std;

class Nguoi{
    private: 
        string ten, ns, dc;
    public: 
        Nguoi(string ten, string ns, string dc){
            this->ten = ten;
            this->ns = ns;
            this->dc = dc;
        }
        void xinchao(){
            cout << "Xin chao !\n";
        }
        string getTen(){
            return this->ten;
        }
        void in(){
            cout << ten << ' ' << ns << ' ' << dc << endl;
        }
};
class SinhVien : public Nguoi{
    private: 
        double gpa;
    public: 
        SinhVien(string ten, string ns, string dc, double gpa) : Nguoi(ten, ns, dc){
            this->gpa = gpa;
        }
};
class GiaoVien : public Nguoi{
    private: 
        double luong;
    public: 
        GiaoVien(string ten, string ns, string dc, double luong) : Nguoi(ten, ns, dc){
            this->luong = luong;
        }
}
int main(){
    SinhVien x("Chi Vy", "7/12/2003", "Ha Tinh", 3.2);
    x.xinchao();
    x.in();
    system("pause");
    return 0;
}