#define  _CRT_INSECURE_DEPRECATE(ctime_s)
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <chrono>
#include <ctime>
using namespace std;

//struct Time {
//	int hours;
//	int minute;
//	int second;
//
//	Time(int h, int m, int s) {
//		hours = h;
//		minute = m;
//		second = s;
//	}
//};

struct Xe {
	string bienso;
	string giora;
	string giovao;
};

struct BaiXe {
	int col;
	int row;
	int type;
	int tienthu = 0;
	Xe **Matrix; 
	Xe *xeThang;
};

void xuatBXNgay(BaiXe baixe);
void xuatBXThang(BaiXe baixe);
void chuyenTime(string time, int &hours, int &minutes, int &second);
int tinhGio(int h1, int m1, int s1, int h2, int m2, int t2);
string randomID();

string nowTime() {
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm* time_info = localtime(&now_time);
	int hours = time_info->tm_hour;
	int minute = time_info->tm_min;
	int second = time_info->tm_sec;
	string pH = to_string(hours);
	string pM = to_string(minute);
	string pS = to_string(second);

	string gpg = pH + ":" + pM + ":" + pS;
	return gpg;
}

void initBaixe(BaiXe &baixe) {
	cout << "Kich thuoc bai xe: " << endl;
	cout << "Nhap hang: ";
	cin >> baixe.row;
	cout << "Nhap cot: ";
	cin >> baixe.col;

	baixe.Matrix = new Xe*[baixe.row];
	for (int i = 0; i < baixe.row; i++) {
		baixe.Matrix[i] = new Xe[baixe.col];
	}

	baixe.xeThang = new Xe[baixe.row*baixe.col];
}

void nhapThongTin(BaiXe &baixe) {
	cout << "Chon goi theo thang hay theo ngay (0-1): ";
	cin >> baixe.type;
	switch (baixe.type)
	{
	case 0:
		cout << "-Giu xe theo thang-" << endl;
		int pos;
		cout << "Nhap cho de xe: ";
		cin >> pos;
		cin.ignore();
		cout << "Nhap bien so xe: ";
		getline(cin, baixe.xeThang[pos].bienso);
		cout << "Nhap gio ra: ";
		getline(cin, baixe.xeThang[pos].giora);
		baixe.xeThang[pos].giovao = nowTime();
		xuatBXThang(baixe);
		baixe.tienthu += 200;
	break;
	case 1: {
		cout << "-Giu xe theo ngay-" << endl;
		int hang, cot;
		cout << "Nhap hang de xe: ";
		cin >> hang;
		cout << "Nhap cot de xe: ";
		cin >> cot;
		cin.ignore();
		cout << "Nhap bien so: ";
		getline(cin, baixe.Matrix[hang][cot].bienso);
		cout << "Nhap gio ra: ";
		getline(cin, baixe.Matrix[hang][cot].giora);
		baixe.Matrix[hang][cot].giovao = nowTime();
		xuatBXNgay(baixe);
		int hv, mv, sv;
		int hr, mr, sr;
		string timevao = "";
		timevao += baixe.Matrix[hang][cot].giovao;
		string timera = "";
		timera += baixe.Matrix[hang][cot].giora;
		chuyenTime(timevao, hv, mv, sv);
		chuyenTime(timera, hr, mr, sr);
		int tong_thoi_gian = tinhGio(hv, mv, sv, hr, mr, sr);
		if (tong_thoi_gian <= 60) {
			baixe.tienthu += 50;
		}
		else {
			int so_lan_tang = (tong_thoi_gian - 60) / 30;
			baixe.tienthu += 50 + so_lan_tang * 20;
		}
	}
		break;
	default:
		break;
	}
}
void xuatBXNgay(const BaiXe baixe) {
	for (int i = 0; i < baixe.row; i++) {
		for (int j = 0; j < baixe.col; j++) {
			cout << "vitri[" << i << "][" << j << "]: ";
			if (baixe.Matrix[i][j].bienso != "" && baixe.Matrix[i][j].giora != "") {
				cout << "Bien so: " << baixe.Matrix[i][j].bienso << " ";
				cout << "Gio vao: " << baixe.Matrix[i][j].giovao << " ";
				cout << "Gio ra: " << baixe.Matrix[i][j].giora << endl;
			}
			else {
				cout << "Bien so: con trong" << " ";
				cout << "Gio vao: con trong" << " ";
				cout << "Gio ra: con trong" << endl;
			}
		}
	}
	cout << endl;
}

void xuatBXThang(const BaiXe baixe) {
	for (int i = 0; i < baixe.row*baixe.col; i++) {
		if (baixe.xeThang[i].bienso != "" && baixe.xeThang[i].giora != "") {
			cout << "Bien so: " << baixe.xeThang[i].bienso << " ";
			cout << "Gio vao: " << baixe.xeThang[i].giovao << " ";
			cout << "Gio ra: " << baixe.xeThang[i].giora;
			cout << endl;
		}
		else {
			cout << "Bien so: con trong" << " ";
			cout << "Gio vao: con trong" << " ";
			cout << "Gio ra: con trong" << endl;
		}
	}
	cout << endl;
}

void chuyenTime(string time, int &hours, int &minutes, int &second) {
	size_t pos1 = time.find(":");
	size_t pos2 = time.rfind(":");
	hours = stoi(time.substr(0, pos1));
	minutes = stoi(time.substr(pos1 + 1, pos2 - pos1 - 1));
	second = stoi(time.substr(pos2 + 1));
}

int tinhGio(int h1, int m1, int s1, int h2, int m2, int t2) {
	return (h1 + m1 * 60 + s1 * 3600) - (h2 + m2 * 60 + t2 * 3600);
}

int soLuong(BaiXe baixe) {
	int tong = 0;
	for (int i = 0; i < baixe.row; i++) {
		for (int j = 0; j < baixe.col; j++) {
			if (baixe.Matrix[i][j].bienso != "" && baixe.Matrix[i][j].giora != "") {
				tong += 1;
			}
		}
	}
	for (int i = 0; i < baixe.row*baixe.col; i++) {
		if (baixe.xeThang[i].bienso != "" && baixe.xeThang[i].giora != "") {
			tong += 1;
		}
	}
	return tong;
}

string randomID() {
	srand(time(NULL));
	char kytu[] = { 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
	char chuso[] = { '0','1','2','3','4','5','6','7','8','9' };
	string chuoiID = "";
	for (int i = 0; i < 5; i++) {
		int pos = rand() % 26;
		chuoiID += kytu[pos];
	}
	for (int i = 5; i < 10; i++) {
		int pos = rand() % 10;
		chuoiID += chuso[pos];
	}
	return chuoiID;
}

int main() {
	BaiXe baixe;
	initBaixe(baixe);
	system("cls");
	while(true){
		nhapThongTin(baixe);
		int so;
		cout << "Nhap 0 de thoat/ so khac de tiep tuc: ";
		cin >> so;
		if (so == 0) {
			break;
		}
	}
	cout << "So luong xe: " << soLuong(baixe) << endl;
	cout << "Tien thu: " << baixe.tienthu << endl;
	system("pause");
	return 0;
}