#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m; 
	int x[100], y[100];
	for (int j = 0; j < n1; j++) {
		x[j] = a[l+j];
	}
	for (int j = 0; j < n2; j++) {
		y[j] = a[m+1+j];
	}
	int i = 0, j = 0, cnt = l;
	while (i < n1 && j < n2) {
		if (x[i] <= y[j]) {
			a[cnt++] = x[i++];
		}
		else {
			a[cnt++] = y[j++];
		}
	}
	while (i < n1) {
		a[cnt++] = x[i++];
	}
	while (j < n2) {
		a[cnt++] = y[j++];
	}
}
void mergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = l+(r-l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main(){
    int a[]={40,60,15,50,90,20,10};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a, 0, n-1);
    for(int x: a){
        cout << x << " ";
    }
    system("pause");
    return 0;
}