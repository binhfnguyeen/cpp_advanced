#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x: a) cin >> x;
    sort(a, a+n);
    int l=0, res=-1;
    for(int r=0; r<n; r++){
        while(a[r]-a[l]>k){
            l++;
        }
        res=max(res, r-l+1);
    }
    cout << res << endl;
    system("pause");
    return 0;
}