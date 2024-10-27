#include <iostream>
using namespace std;
int *firstPos(int *p, int n, int num) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (*(p + i) == num) {
			return p+i;
		}
	}
	return nullptr;
}
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int *p;
	p = new int[n];
	for (int i = 0; i < n; i++) {
		*(p + i) = rand() % 100;
		cout << *(p + i) << " ";
	}
	cout << endl;
	int *tim = firstPos(p, n, 41);
	if (tim != nullptr) {
		cout << "Co trong mang" << endl;
	}
	else {
		cout << "Khong tim thay!" << endl;
	}
	system("pause");
	return 0;
}