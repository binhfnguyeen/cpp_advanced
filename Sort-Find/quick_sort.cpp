#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int c=a;
    a=b;
    b=c;
}
void quickSort(int a[], int left, int right){
    int x = a[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(a[i]<x){
            i++;
        }
        while(a[j]>x){
            j--;
        }
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(left<j){
        quickSort(a, left, j);
    }
    if(i<right){
        quickSort(a, i, right);
    }
}
int main(){
    int a[] = {1, 3, 2, 5, 9, 8};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}