#include <iostream>
#include <set>
using namespace std;
//Median: trung vi
int n, k;
long long a[1000005];

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    multiset <int> ms;
    for(int i=0; i<k; i++){
        ms.insert(a[i]);
    }
    auto it = ms.begin();
    advance(it, (k-1)/2);
    for(int i=k; i<=n; i++){
        cout << *it << ' ';
        if(i==n) break;
        ms.insert(a[i]);
        if(*it>a[i]){
            --it;
        }
        if(a[i-k]<=*it) {
            ++it;
        }
        ms.erase(ms.lower_bound(a[i-k]));
    }
    system("pause");
    return 0;
}