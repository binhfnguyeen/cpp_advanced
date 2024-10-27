#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int *p;
	p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 100;
		cout << *(p + i) << " ";
	}
	cout << endl;
	cout << "Phan tu le trong mang: " << endl;
	for (int i = 0; i < n; i++) {
		if (*(p+i) % 2 != 0) {
			cout << *(p + i) << " ";
		}
	}
	cout << endl;
	int max = -9999;
	cout << "Phan tu lon nhat trong mang: ";
	for (int i = 0; i < n; i++) {
		if (*(p + i) > max) {
			max = *(p + i);
		}
	}
	cout << max << endl;
	delete[] p;
	system("pause");
	return 0;
}