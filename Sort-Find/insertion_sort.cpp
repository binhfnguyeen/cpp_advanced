#include <iostream>
using namespace std;
void insertionSort(int a[], int n){
    int x, j;
    for(int i=1; i<n; i++){
        x=a[i];
        j=i-1;
        while(0<=j && x > a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
int main(){
    int a[] = {22, 12, 9, 7, 31, 19};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}