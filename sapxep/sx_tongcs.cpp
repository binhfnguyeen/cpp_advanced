#include <iostream>
#include <algorithm>
using namespace std;
int tongcs(int n){
    int tong=0;
    while(n){
        tong+=n%10;
        n/=10;
    }
    return tong;
}
int cmp(int a, int b){
    if(tongcs(a)<tongcs(b)) {
        return tongcs(a) < tongcs(b);
    } 
    if(tongcs(a) == tongcs(b)) {
        return a<b;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, cmp);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}