#pragma once
#include <iostream>
using namespace std;

int ucln(int a, int b) {
	if (b == 0)
		return a;
	return ucln(b, a%b);
}

class PhanSo {
private: int tuso, mauso;
		 void reduce() {
			 int gcd = ucln(tuso, mauso);
			 tuso /= gcd;
			 mauso /= gcd;
		 }
public:
	int getTuso();
	int getMauso();
	void setTuso(int a);
	void setMauso(int b);
	PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2);
	void hienThi() {
		cout << tuso << "/" << mauso << endl;
	}
};