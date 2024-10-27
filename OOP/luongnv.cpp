#include <iostream>
#include <string>
using namespace std;

class NhanVien{
    private:  
        string manv, hoten, chucvu;
        int luongCB, soNgayCong;
    public:
       void nhap(){
               static int cnt=0;
                cnt++;
                if(cnt<=9) {
                    this->manv = "NV0" + to_string(cnt);
                } else {
                    this->manv = "NV" + to_string(cnt);
                }
            getline(cin, this->hoten);
            cin >> this->luongCB;
            cin >> this->soNgayCong;
            cin >> this->chucvu;
            cin.ignore();
       }
       int tinhLuong(){
            return this->luongCB*this->soNgayCong;
       }
       int tinhThuong(){
            if(this->soNgayCong>=25){
                return tinhLuong()*0.2;
            } else if(this->soNgayCong>=22){
                return tinhLuong()*0.1;
            } else {
                return 0;
            }
       }
       int tinhPhuCap(){
        if (chucvu == "GD") {
            return 250000;
        } else if (chucvu == "PGD") {
            return 200000;
        } else if (chucvu == "TP") {
            return 180000;
        } else {
            return 150000;
        }
       }
       int tinhThuNhap(){
        return tinhLuong() + tinhThuong() + tinhPhuCap();
       }
       void in(){
            cout << this->manv << ' ';
            cout << this->hoten << ' ';
            cout << tinhLuong() << ' ';
            cout << tinhThuong() << ' ';
            cout << tinhPhuCap() << ' ';
            cout << tinhThuNhap() << ' ';
       }
};

int main(){
    NhanVien x;
    x.nhap();
    x.in();
    system("pause");
    return 0;
}