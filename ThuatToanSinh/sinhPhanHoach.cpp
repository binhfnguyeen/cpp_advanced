#include <iostream>
using namespace std;

int n, a[100], cnt;
int final=0;
void ktao(){
    cnt=1;
    a[1]=n;
}
void sinh(){
    int i=cnt;
    while(i>=1 && a[i]==1){
        --i;
    }
    if(i==0){
        final=1;
    } else {
        --a[i];
        int d=cnt-i+1;
        cnt=i;
        int q=d/a[i], r=d%a[i];
        for(int j=1; j<=q; j++){
            ++cnt;
            a[cnt]=a[j];
        }
        if(r){
            ++cnt;
            a[cnt]=r;
        }
    }
}
int main(){
    cin >> n;
    ktao();
    while(!final){
        for(int i=1; i<=cnt; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    system("pause");
    return 0;
}