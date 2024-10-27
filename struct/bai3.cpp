#include <iostream>
#include <string>
using namespace std;
struct NhanVien{
    string id;
    string name;
    int begin;
    int birthyear;
};
void nhap(NhanVien nv){
    cout << "Nhap ID: ";
    getline(cin, nv.id);
    cout << "Nhap ten: ";
    getline(cin, nv.name);
    cout << "Nhap nam vao lam: ";
    cin >> nv.begin;
    cout << "Nhap nam sinh: ";
    cin >> nv.birthyear;
}
void xuat(NhanVien nv) {
    cout << "Begin: " << nv.begin << endl;
    cout << "Year of birth: " << nv.birthyear << endl;
    cout << "ID: " << nv.id << endl;
    cout << "Name: " << nv.name << endl;
}
int main() {
    NhanVien nv;
    nhap(nv);
    xuat(nv);
    system("pause");
    return 0;
}