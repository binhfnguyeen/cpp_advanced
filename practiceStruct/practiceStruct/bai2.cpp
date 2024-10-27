#include <iostream>
#include <string>
using namespace std;

struct PhanSo {
	int tuSo;
	int mauSo;
};

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void rutGonPS(PhanSo p) {
	int ucln = gcd(p.tuSo, p.mauSo);
	p.tuSo /= ucln;
	p.mauSo /= ucln;
}

void nhapPS(PhanSo &p) {
	cout << "Nhap tu so: ";
	cin >> p.tuSo;
	do {
		cout << "Nhap mau so: ";
		cin >> p.mauSo;
	} while (p.mauSo == 0);
	rutGonPS(p);
}

void inPS(PhanSo p) {
	cout << p.tuSo << "/" << p.mauSo << endl;
}

PhanSo tong(const PhanSo p1, const PhanSo p2) {
	PhanSo kq;
	kq.tuSo = p1.tuSo*p2.mauSo + p1.mauSo*p2.tuSo;
	kq.mauSo = p1.mauSo*p2.mauSo;
	rutGonPS(kq);
	return kq;
}

PhanSo hieu(const PhanSo p1, const PhanSo p2) {
	PhanSo kq;
	kq.tuSo = p1.tuSo*p2.mauSo - p1.mauSo*p2.tuSo;
	kq.mauSo = p1.mauSo*p2.mauSo;
	rutGonPS(kq);
	return kq;
}

PhanSo tich(const PhanSo p1, const PhanSo p2) {
	PhanSo kq;
	kq.tuSo = p1.tuSo*p2.tuSo;
	kq.mauSo = p1.mauSo*p2.mauSo;
	rutGonPS(kq);
	return kq;
}

PhanSo thuong(const PhanSo p1, const PhanSo p2) {
	PhanSo kq;
	kq.tuSo = p1.tuSo*p2.mauSo;
	kq.mauSo = p1.mauSo*p2.tuSo;
	rutGonPS(kq);
	return kq;
}
int main() {
	PhanSo p1, p2;
	nhapPS(p1);
	nhapPS(p2);
	inPS(p1);
	inPS(p2);

	cout << "Tong: ";
	inPS(tong(p1, p2));
	cout << "Hieu: ";
	inPS(hieu(p1, p2));
	cout << "Tich: ";
	inPS(tich(p1, p2));
	cout << "Thuong: ";
	inPS(thuong(p1, p2));
	system("pause");
	return 0;
}