#define _CRT_INSECURE_DEPRECATE(ctime_s)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

int tong(int a, int b) {
	return a + b;
}
string getTime();

void ghiFile(ofstream &ofs, const string name, int a, int b) {
	ofs.open(name, ios::out);
	if (!ofs.is_open()) {
		cerr << "Khong the mo file de ghi!" << endl;
		return;
	}
	string time = getTime();
	ofs << tong(a, b) << endl;
	ofs << time;
	ofs.close();
}

void docFile(ifstream &ifs, const string name, string &kq) {
	ifs.open(name, ios::in);
	if (!ifs.is_open()) {
		cerr << "Kh�ng th? m? file ?? ??c!" << endl;
		return;
	}
	ifs >> kq;
	ifs.close();
}

void docFileLoc(ifstream &ifs, const string name, string &chuoi, string &chuoi2) {
	ifs.open(name, ios::in);
	chuoi = "";
	if (!ifs.is_open()) {
		cerr << "Khong the mo file de doc!" << endl;
		return;
	}
	char line;
	while (ifs >> line) {
		
		if(line == '\n'){
			if(line != '#'){
				chuoi2 += line;
				
			} else {
				chuoi2 += " ";
			}
		} else {
			if(line != '#')
			chuoi += line;
			else chuoi += " ";
		}
	}
	ifs.close();
}

double docVaTinhTrungBinhCong(const string& fileName, int& a, int& b, int& c) {
	ifstream ifs(fileName);
	if (!ifs.is_open()) {
		cerr << "Khong the mo file de doc!" << endl;
		return 0.0;
	}
	//string line;
	//getline(ifs, line);
	//ifs.close();

	//// Su dung stringstream de phan tach chuoi thanh cac so nguy�n
	//stringstream ss(line);
	//char delim; // Bien luu tru ky tu ph�n t�ch (dau #)
	//ss >> a >> delim >> b >> delim >> c;

	ifs >> a;
	ifs.ignore(1);
	ifs >> b;
	ifs.ignore(1);
	ifs >> c;
	return (a + b + c) / 3.0;
}

void docDong(ifstream &ifs, const string name){
	ifs.open(name, ios::in);
	string line;
	while(getline(ifs, line)){
		cout << "Read: " << line << endl;
		cin.get();
	}
	ifs.close();
}
string getTime() {
	auto now = chrono::system_clock().now();
	time_t now_time = chrono::system_clock().to_time_t(now);
	tm *time_info = localtime(&now_time);
	int hours = time_info->tm_hour;
	int minute = time_info->tm_min;
	int second = time_info->tm_sec;
	string pH = to_string(hours);
	string pM = to_string(minute);
	string pS = to_string(second);

	string gpg = pH + ":" + pM + ":" + pS;
	return gpg;
}
int main() {
	ofstream ofs;
	ifstream ifs;
	string kq, kq2;
	// int a, b;

	// cout << "Nhap a: ";
	// cin >> a;
	// cout << "Nhap b: ";
	// cin >> b;
	// ghiFile(ofs, "file.txt", a, b);
	// docFile(ifs, "file.txt", kq);
	// cout << "Tong: " << kq << endl;

	// string chuoi;
	// docFileLoc(ifs, "bai3.txt", chuoi);
	// cout << chuoi << endl;

	// int a1, b1, c1;
	// double trungBinhCong = docVaTinhTrungBinhCong("IntFile.txt", a1, b1, c1);
	// cout << "Trung binh cong cua 3 so nguyen la: " << trungBinhCong << endl;

	docDong(ifs, "bai3.txt");
	system("pause");

	return 0;
}
