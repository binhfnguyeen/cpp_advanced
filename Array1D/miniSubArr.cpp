#include <iostream>
using namespace std;
long long a[1000005];
int main(){
    int n, k; cin >> n >> k;
    for(long long &x: a){
        cin >> x;
    }
    int len=1; 
    while(len<=n){
        long long sum=0;
        for(int i=0; i<len; i++) sum+=a[i];
        if(sum==k){
            cout << len << endl;
            return 0;
        }
        for(int i=len; i<n; i++){
            sum+=a[i]-a[i-len];
            if(sum==k){
                cout << len << endl;
                return 0;
            }
        }
        len++;
    }
    cout << -1 << endl;
    system("pause");
    return 0;
}