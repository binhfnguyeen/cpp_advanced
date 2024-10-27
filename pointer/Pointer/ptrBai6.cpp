#include <iostream>
using namespace std;

//*&p: tham chieu con tro(con tro tro toi con tro): khi truyen vào hàm chua tham so
// name(int *&p) thì ta truyen dia chi vào nó: ptr = &x  -> name(ptr); = thay doi giá tri goc
//**p: con tro tro toi con tro khác: khi truyen vòa hàm chua tham so 
// name(int **p) thì truyen &ptr -> name(&ptr); = truy cap toi giá tri mà p tro toi
//**p = &ptr;
//*&p = p = &x;
void swap(int *&a, int *&b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverseArray(int *p, int n) {
	int i = 0, j=n-1;
	while (i<j) {
		swap(*(p + i), *(p + j));
		j--;
		i++;
	}
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
	cout << "Mang sau khi dao nguoc: " << endl;
	reverseArray(p, n);
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	delete[] p;
	system("pause");
	return 0;
}