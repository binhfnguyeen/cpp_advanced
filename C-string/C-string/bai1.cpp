#define  _CRT_INSECURE_DEPRECATE(ctime_s)
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <chrono>
using namespace std;

struct Time {
	int hours;
	int minute;
	int second;

	Time(int h, int m, int s) {
		hours = h;
		minute = m;
		second = s;
	}
};
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

string nowTime() {
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm* time_info = localtime(&now_time);
	int hours = time_info->tm_hour;
	int minute = time_info->tm_min;
	int second = time_info->tm_sec;
	string pH = hours + "0";
	string pM = minute + "0";
	string pS = second + "0";
	string gpg = pH + ":" + pM + ":" + pS;
	return gpg;
}

void initBaixe(BaiXe &baixe) {
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
	case 0: {
		cout << "-Giu xe theo thang-" << endl;
		int hang, cot;
		cout << "Nhap hang de xe: ";
		cin >> hang;
		cout << "Nhap cot de xe: ";
		cin >> cot;

		getline(cin, baixe.Matrix[hang][cot].bienso);
		getline(cin, baixe.Matrix[hang][cot].giora);
		baixe.Matrix[hang][cot].giovao = nowTime();
	} break;
	default:
		break;
	}
}
int main() {
	cout << nowTime() << endl;
	system("pause");
	return 0;
}