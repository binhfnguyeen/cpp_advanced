#include <iostream>
using namespace std;

int n, X[100];
int finall=0;
void ktao(){
    for(int i=1; i<=n; i++){
        X[i]=0;
    }
}

void sinh(){
    //Đi tìm bit 0 đầu tiên tính từ bên phải
    //Gặp 1 => 0
    int i=n;
    while(i>=1 && X[i]==1){
        X[i]=0;
        --i;
    }
    if(i==0){
        finall=1;
    } else {
        X[i]=1;
    }

}
int main(){
    int n; cin >> n;
    ktao();
    while(finall==0){
        for(int i=1; i<=n; i++){
            cout << X[i];
        }
        cout << endl;
        sinh();
    }
    system("pause");
    return 0;
}