#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int &x: a) cin >> x;
    sort(a, a+n);
    int t1=abs(a[n-1]+a[n-2]);
    int t2=abs(a[0]+a[1]);
    cout << max(t1, t2) << endl;
    system("pause");
    return 0;
}