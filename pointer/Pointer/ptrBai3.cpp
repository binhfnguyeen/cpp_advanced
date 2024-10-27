#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int *p = new int;
	int *q = new int;
	cout << "Nhap so thu nhat: ";
	cin >> *p;
	cout << "Nhap so thu hai: ";
	cin >> *q;
	cout << "GCD: " << gcd(*p, *q) << endl;
	delete p;
	p = nullptr;
	delete q;
	q = nullptr;
	system("pause");
	return 0;
}