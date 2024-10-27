#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

bool nt(long long n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return n > 1;
}

vector <long long> v;

void solve(){
    queue <long long> q;
    q.push(2); q.push(3); q.push(5); q.push(7); q.push(9);
    while(!q.empty()){
        long long x = q.front(); q.pop();
        if(x > 1e9) break;
        if(nt(x)) v.push_back(x);
        for(int y: {1, 3, 5, 7, 9}){
            if(nt(x*10+y)){
                q.push(x*10+y);
            }
        }
    }
}
int main(){
    solve();
    for(long long x: v){
        cout << x << endl;
    }
    system("pause");
    return 0;
}