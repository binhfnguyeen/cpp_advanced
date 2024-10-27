#define  _CRT_INSECURE_DEPRECATE(ctime_s)
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;

int nowYear() {
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm* time_info = localtime(&now_time);
	int years = time_info->tm_year + 1900;
	return years;
}

struct NhanVien {
	string maNV;
	string hoTen;
	int namVaoLam;
	int namSinh;
};

void nhapThongTin(NhanVien &nv) {
	cout << "Nhap id: ";
	getline(cin, nv.maNV);
	cout << "Nhap ten: ";
	getline(cin, nv.hoTen);
	cout << "Nhap nam vao lam: ";
	cin >> nv.namVaoLam;
	cout << "Nhap nam sinh: ";
	cin >> nv.namSinh;
}

void xuatThongTin(NhanVien nv) {
	cout << "ID: " << nv.maNV << endl;
	cout << "Ho ten: " << nv.hoTen << endl;
	cout << "Nam vao lam: " << nv.namVaoLam << endl;
	cout << "Nam sinh: " << nv.namSinh << endl;
}

int tuoiNV(NhanVien nv) {
	int tuoi = nowYear() - nv.namSinh;
	return tuoi;
}

int thamNien(NhanVien nv) {
	int thamnien = nowYear() - nv.namVaoLam;
	return thamnien;
}
int main() {
	/*auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	cout << "Currently time: " << ctime(&now_time);
	tm* time_info = localtime(&now_time);
	int year = time_info->tm_year + 1900;
	int month = time_info->tm_mon + 1;
	int day = time_info->tm_mday;
	cout << "Ngay hien tai: " << year << "-" << month << "-" << day << endl;
	int hours = time_info->tm_hour;
	int minutes = time_info->tm_min;
	int secconds = time_info->tm_sec;
	cout << "Gio hien tai: " << hours << ":" << minutes << ":" << secconds << endl;*/
	NhanVien nv;
	nhapThongTin(nv);
	xuatThongTin(nv);
	cout << "Tuoi: " << tuoiNV(nv) << endl;
	cout << "Tham nien: " << thamNien(nv) << endl;
	system("pause");
	return 0;
}