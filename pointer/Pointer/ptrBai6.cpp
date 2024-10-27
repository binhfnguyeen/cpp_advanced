#include <iostream>
using namespace std;

//*&p: tham chieu con tro(con tro tro toi con tro): khi truyen v�o h�m chua tham so
// name(int *&p) th� ta truyen dia chi v�o n�: ptr = &x  -> name(ptr); = thay doi gi� tri goc
//**p: con tro tro toi con tro kh�c: khi truyen v�a h�m chua tham so 
// name(int **p) th� truyen &ptr -> name(&ptr); = truy cap toi gi� tri m� p tro toi
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