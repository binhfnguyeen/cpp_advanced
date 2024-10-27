#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    map<int, int> pos;
    int ans=-1;
    for(int i=0; i<n; i++){
        if(pos.find(a[i]+k)!=pos.end()) {
            ans=max(ans, i - pos[a[i]+k]);
        }
        if(pos.find(a[i]-k)!=pos.end()) {
            ans=max(ans, i- pos[a[i]-k]);
        }
        if(pos.find(a[i])==pos.end()) {
            pos[a[i]]=i;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}