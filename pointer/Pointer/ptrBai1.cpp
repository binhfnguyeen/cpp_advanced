#include <iostream>
using namespace std;

int main() {
	int x, y;
	int *p;
	p = &x;
	*p = 80;
	cout << "x: " << &x << endl;
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;
	cout << "x: " << x << endl;
	if (*p == x) {
		cout << "p luu tru gia tri x" << endl;
	}
	else {
		cout << "p khong luu gia tri x" << endl;
	}
	system("pause");
	return 0;
}