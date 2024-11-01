/*Tìm kiếm xem có tồn tại một tổng nào trong mảng mà xuất hiện ít nhất hai lần. 
Nếu có, chương trình sẽ in ra 1 và kết thúc; nếu không, nó sẽ in ra -1.:*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n+1];
    long long F[n+1]={0};
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    map<long long, int> mp;
    mp[0]=1;
    for(int i=1; i<=n; i++){
        F[i]=F[i-1]+a[i];
        mp[F[i]]++;
        if(mp[F[i]]==2){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    system("pause");
    return 0;
}
