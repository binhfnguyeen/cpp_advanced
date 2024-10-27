#include <iostream>
using namespace std;

int main(){
    int n, d; cin >> n >> d;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    long long res=0;
    for(int i=1; i<n; i++){
        if(a[i]<=a[i-1]){
            int kc = a[i-1]+1-a[i];
            int buoc= (kc+d-1)/d;
            res+=buoc;
            a[i] = a[i] + buoc*d;
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}