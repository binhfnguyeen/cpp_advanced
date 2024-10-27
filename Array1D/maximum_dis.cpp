#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    map<int, int> mp;
    int max_len=-1;
    for(int i=0; i<n; i++){
        int x=a[i];
        if(mp.count(x-k)){
            max_len=max(max_len, i-mp[x-k]);
        }
        if(mp.count(x+k)){
            max_len=max(max_len, i-mp[x+k]);
        }
        if(!mp.count(a[i])) {
            mp[a[i]]=i;
        }
    }
    cout << max_len << endl;
    system("pause");
    return 0;
}