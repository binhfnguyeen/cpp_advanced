#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int &x: a) cin >> x;
    long long res=0;
    for(int i=1; i<n; i++){
        if(a[i]<=a[i-1]) {
            res+=a[i-1]+1-a[i];
            a[i]=a[i-1]+1;
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}