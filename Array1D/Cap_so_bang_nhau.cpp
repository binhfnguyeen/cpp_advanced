#include <iostream>
using namespace std;
//Su dung To hop: n(n-1)/2
int d[1000005];
int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        d[x]++;
    }
    long long sum=0;
    for(int i=0; i<=1e6; i++){
        sum+=1ll*d[i]*(d[i]-1)/2;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}