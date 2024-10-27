#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int a[30];
	for (int i = 0; i < 30; i++) {
		a[i] = rand() % 10;
	}

	int *p;
	p = new int[30];
	p = &a[0];
	cout << "Ky phap do doi: " << endl;
	for (int i = 0; i < 30; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
	cout << "Ky phap chi so: " << endl;
	for (int i = 0; i < 30; i++) {
		cout << p[i] << " ";
	}

	delete[]p;
	p = nullptr;
	system("pause");
	return 0;
}