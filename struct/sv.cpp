#include <iostream>
#include <string>
using namespace std;
struct ntn{
    int ngay, thang, nam;
};
struct SinhVien{
    string name;
    ntn days;
    void nhap(){
        cout << "Nhap ten: " << endl;
        getline(cin, this->name);
        cout << "Nhap days: " << endl;
        cin >> this->days.ngay >> this->days.thang >> this->days.nam;
    }
    void in(){
        cout << this->name << endl;
        cout << this->days.ngay << "/" << this->days.thang << "/" << this->days.nam << endl;
    }
};
int main(){
    SinhVien x;
    x.nhap();
    x.in();
    system("pause");
    return 0;
}