#include <iostream>
#include <map>
using namespace std;
// Cho mảng A[] gồm N phần tử và số nguyên K, 
// bạn hãy xác định xem trong mảng có tồn tại 2 phần tử A[i], A[j] với i khác j 
// sao cho A[i] = A[j] và abs(i - j) <= K hay không. Nếu có in ra YES, ngược lại in ra NO. 
// Bài này các bạn có thể sử dụng sort hoặc sliding window

int n, k;
int a[1000005];
int main(){
    cin >> n >> k;
    map<int, int> mp;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mp[a[i]]=-1;
    }
    for(int i=1; i<=n; i++){
        if(mp[a[i]]!=-1){
            if(i-mp[a[i]]<=k){
                cout << "YES\n";
                return 0;
            } 
            else mp[a[i]]=i;
        }
        mp[a[i]]=i;
    }
    cout << "NO\n";
    system("pause");
    return 0;
}