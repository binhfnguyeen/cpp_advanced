#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n], d[3]={0};
    for(int &x: a){
        cin >> x;
        d[x]++;
    }
    for(int i=0; i=2; i++){
        for(int j=0; j<d[i]; j++){
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}