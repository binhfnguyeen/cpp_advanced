#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n+1];
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    map<long long, int> mp;
    mp[0]=0;
    int max_len=-1, sum=0;
    for(int i=1; i<=n; i++){
        sum=((sum+a[i])%k+k)%k;
        if(mp.count(sum)){
            max_len=max(max_len, i-mp[sum]);
        }
        //i-mp[sum] => tra ve do dai mang con
        if(!mp.count(sum)){
            mp[sum]=i;
        }
        //neu trong map chua co sum, thi se luu vao mp la vi tri hien tai
    }
    cout << max_len << endl;
    system("pause");
    return 0;
}