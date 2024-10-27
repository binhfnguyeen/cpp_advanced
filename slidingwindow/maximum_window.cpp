#include <iostream>
#include <set>
using namespace std;

int n, k;
long long a[1000005];
int main(){
    cin >> n >> k;
    multiset <int> ms;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=k; i++){
        ms.insert(a[i]);
    }
    for(int i=k+1; i<=n+1; i++){
        cout << (*ms.begin()) << " " << (*ms.rbegin()) << endl;
        if(i==n+1){
            break;
        }
        ms.insert(a[i]);
        ms.erase(ms.lower_bound(a[i-k]));
    }
    system("pause");
    return 0;
}