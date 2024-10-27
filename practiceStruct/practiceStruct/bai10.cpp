#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class GPG {
private:
	int gio, phut, giay;
public:
	GPG() {
		gio = 0;
		phut = 0;
		giay = 0;
	}
	GPG(int gio, int phut, int giay) {
		this->gio = gio;
		this->phut = phut;
		this->giay = giay;
	}
	int getGio() {
		return gio;
	}
	int getPhut() {
		return phut;
	}
	int getGiay() {
		return giay;
	}
	int khoangCachGiuaHaiGPG(GPG b) {
		return (this->getGio() + this->getPhut() * 60 + this->getGiay() * 3600) - (b.getGio() + b.getPhut() * 60 + b.getGiay() * 3600);
	}
};

int main() {
	GPG gpg1(15, 20, 53);
	GPG gpg2(12, 34, 21);

	int khoangcach = gpg1.khoangCachGiuaHaiGPG(gpg2);
	cout << "Khoang cach time: " << khoangcach << endl;
	system("pause");
	return 0;
}