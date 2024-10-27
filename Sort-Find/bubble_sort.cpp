#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int c=a;
    a=b;
    b=c;
}
void bubbleSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(a[j-1]>a[j]){
                swap(a[j], a[j-1]);
            }
        }
    }
}
int main(){
    int a[] = {1, 3, 2, 5, 9, 8};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}