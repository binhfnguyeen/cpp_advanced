#include <iostream>
using namespace std;
int X[100];
int n, k; 

void Try(int i){
    for(int j = X[i-1]+1; j<=n-k+i; j++){
        X[i]=j;
        if(i==k){
            for(int idx=1; idx<=k; idx++){
                cout << X[idx] << " ";
            }
            cout << endl;
        } else {
            Try(i+1);
        }
    }
}
int main(){
    cin >> n >> k;
    Try(1);
    system("pause");
    return 0;
}