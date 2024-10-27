#include <iostream>
#include <cmath>
using namespace std;

void input(int **&a, int r, int c) {
	a = new int*[r];
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
		for (int j = 0; j < c; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
			cin >> *(*(a + i) + j);
		}
	}
}

void output(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int sumPrime(int **p, int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (isPrime(*(*(p + i) + j))) {
				sum += *(*(p + i) + j);
			}
		}
	}
	return sum;
}
int main() {
	int r, c;
	cout << "Nhap row va col: "; cin >> r >> c;
	int **p;
	input(p, r, c);
	output(p, r, c);
	cout << "Tong cac so nguyen to: " << sumPrime(p, r, c) << endl;
	system("pause");
	return 0;
}