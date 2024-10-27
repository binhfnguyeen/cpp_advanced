#include <iostream>
using namespace std;
int n, k, X[100];
int final=0;
void ktao(){
    for(int i=1; i<=k; i++){
        X[i]=i;
    }
}
void sinh(){
    //Đi tìm số đầu tiên tính từ bên phải chưa đạt
    //Giá trị max: n-k+i
    int i=k;
    while(i>=1 && X[i]==n-k+i){
        --i;
    }
    if(i==0){
        final=1;
    } else {
        X[i]++;
        for(int j=i+1; j<=n; j++){
            X[j]=X[j-1]+1;
        }
    }
}
int main(){
    cin >> n >> k;
    ktao();
    while(!final){
        for(int i=1; i<=k; i++){
            cout << X[i] << ' ';
        }
        cout << endl;
        sinh();
    }
    system("pause");
    return 0;
}