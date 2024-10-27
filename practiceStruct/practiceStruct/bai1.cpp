#include <iostream>
#include <string>
using namespace std;

struct PhongBan
{
	string maPhong;
	string tenPhong;
};
int main() {
	PhongBan pb;
	cout << "Nhap id phong ban: ";
	cin >> pb.maPhong;
	cin.ignore();
	cout << "Nhap ten phong ban: ";
	getline(cin, pb.tenPhong);

	cout << "ID phong: " << pb.maPhong << endl;
	cout << "Ten phong: " << pb.tenPhong << endl;
	system("pause");
	return 0;
}