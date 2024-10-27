#include <iostream>
#include <ctime>
using namespace std;

//void swap(int &a, int &b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
void quickSort(int *a, int left, int right) {
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (a[i] < x) {
			i++;
		}
		while (a[j] > x) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j) {
		quickSort(a, left, j);
	}
	if (i < right) {
		quickSort(a, i, right);
	}
}

int main() {
	int *a;
	a = new int[7];

	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	quickSort(a, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}