#include <iostream>
#include <limits.h>
using namespace std;

int n, k;
long long a[1000005];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int pos=-1, ans=INT_MAX;
    int l=0;
    long long sum=0;
    for(int i=1; i<=n; i++){
        sum+=a[i];
        while(l<=i && sum >= k){
            int len=i-l+1;
            if(len<ans){
                ans=len;
                pos=l;
            }
            sum-=a[l];
            l++;
        }
    }
    if(ans==INT_MAX) cout << -1 << endl;
    else{
        for(int i=pos; i<=pos+ans-1; i++){
            cout << a[i] << ' ';
        }
    }
    system("pause");
    return 0;
}