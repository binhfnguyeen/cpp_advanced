#include <iostream>
#include <algorithm>
using namespace std;
void shift(int a[], int i, int n){
    int j=2*i+1;
    if(j>=n) return; 
    if(j+1<n){
        if(a[j]<a[j+1]){
            j++;
        }
    }
    if(a[i]>=a[j]) return;
    else {
        int x = a[i];
        a[i] = a[j];
        a[j] = x;
        shift(a, j, n);
    }
}

void heapSort(int a[], int n){
    int i = n/2;
    while(i>=0){
        shift(a, i, n-1);
        i--;
    }
    int right = n-1;
    while(right>=0){
        swap(a[0], a[right]);
        right--;
        if(right>0){
            shift(a, 0, right);
        }
    }
}
int main(){
    int a[] = {1, 3, 2, 5, 9, 8};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}