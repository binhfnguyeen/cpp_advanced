#include <iostream>
#include <string>
using namespace std;
struct PhongBan {
    string id;
    string name;
} pb;
int main(){
    cout << "Nhap id: " << endl;
    getline(cin, pb.id);
    cout << "Nhap ten: " << endl;
    getline(cin, pb.name);
    cout << "ID: " << pb.id << endl;
    cout << "Name: " << pb.name << endl;
    system("pause");
    return 0;
}