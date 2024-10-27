#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int c = a;
    a=b;
    b=c;
}
void selectionSort(int a[], int n){
    int min_pos;
    for(int i=0; i<n-1; i++){
        min_pos=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min_pos]){
                min_pos=j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}
int main(){
    int a[] = {1, 3, 2, 5, 9, 8};
    int n = sizeof(a)/sizeof(a[0]);
    selectionSort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}