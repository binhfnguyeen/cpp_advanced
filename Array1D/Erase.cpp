#include <iostream>
using namespace std;
int deleteArr(int arr[], int &n, int pos){
    if(pos>=0 && pos<n){
        for(int j=pos; j<n-1; j++){
            arr[j]=arr[j+1];
        }
        n--;
        return 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    for(int x: a){
        cout << x << " ";
    }
    cout << endl;
    int pos;
    cout << "Nhap vi tri can xoa: \n";
    cin >> pos;
    int del = deleteArr(a, n, pos);
    for(int x: a){
            cout << x << " ";
    }
    system("pause");
    return 0;
}
