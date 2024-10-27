#include <iostream>
using namespace std;
int n, k;
long long a[1e6];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    long long maxSum=0, cur=0;
    int pos=k;
    for(int i=1; i<=k; i++){
        cur+=a[i];
    }
    maxSum=max(maxSum, cur);
    for(int i=k+1; i<=n; i++){
        cur +=a[i]-a[i-k];
        if(cur > maxSum){
            maxSum = cur;
            pos=i;
        }
    }
    cout << maxSum << endl;
    for(int i=pos-k+1; i<=pos; i++){
        cout << a[i] << ' ';
    }
    system("pause");
    return 0;
}