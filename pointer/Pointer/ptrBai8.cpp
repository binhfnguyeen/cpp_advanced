#include <iostream>
using namespace std;

int main() {
	int h;
	cout << "Nhap chieu cao: "; cin >> h;
	int **p;
	p = new int*[h];
	for (int i = 0; i < h; i++) {
		p[i] = new int[i+1];
	}
	
	for (int i = 0; i < h; i++) {
		p[i][0] = 1;
		p[i][i] = 1;
		for (int j = 1; j < i; j++) {
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < h; i++) {
		delete[] p[i];
	}
	delete[]p;
	system("pause");
	return 0;
}