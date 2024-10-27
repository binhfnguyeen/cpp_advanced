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
    mp[0]=0;
    int max_len=-1, st=0;
    for(int i=1; i<=n; i++){
        F[i]=F[i-1]+a[i];
        if(mp.count(F[i]-k)){
            int cur_len=i-mp[F[i]-k];
            if(cur_len>max_len){
                st=mp[F[i]-k]+1;
                max_len=cur_len;
            }
        }
        if(!mp.count(F[i])){
            mp[F[i]]=i;
        }
    }
    if(max_len==-1) cout << "NOT_FOUND";
    else {
        for(int i=st; i<st+max_len; i++){
            cout << a[i] << " ";
        }
    }
    system("pause");
    return 0;
}