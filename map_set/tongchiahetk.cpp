#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &x: a) {
        cin >> x;
    }
    map <long long, int> mp;
    long long sum=0;
    int ans=-1;
    for(int i=0; i<n; i++){
        sum+=a[i];
        sum = (sum%k + k )%k;
        if(sum==0) {
            ans=max(ans, i+1);
        }
        if(mp.find(sum)!=mp.end()){
            ans=max(ans, i-1);
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}