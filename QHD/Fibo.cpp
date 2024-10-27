#include <iostream>
using namespace std;
long long F[100];
long long fibo(int n){
    if(n==1 || n==2) return 1;
    if(F[n]!=0) return F[n];
    F[n] = fibo(n-1)+fibo(n-2);
    return F[n];
}
int main(){
    cout << fibo(92) << endl;
    system("pause");
    return 0;
}