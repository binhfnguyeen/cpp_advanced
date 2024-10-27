#include <iostream>
using namespace std;

void fibo(int *p, int n) {
	p[0] = 0;
	p[1] = 1;
	p[2] = 1;
	for (int i = 3; i < n; i++) {
		*(p + i) = *(p + i - 1) + *(p + i - 2);
	}
}
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int *p;
	p = new int[n];
	fibo(*&p, n);
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	delete[] p;
	system("pause");
	return 0;
}