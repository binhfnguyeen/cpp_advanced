#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string s, t;
int n, m;
int main() {
    cin >> s >> t;
    n=s.size();
    m=t.size();
    map<char, int> T;
    for(auto x: t){
        T[x]++;
    }
    int ans=n, pos=-1;
    int l=0;
    int cnt=0;
    map<char, int> S;
    for(int i=0; i<n; i++){
        S[s[i]]++;
        if(S[s[i]]<=T[s[i]]){
            cnt++;
        }
        if(cnt==t.size()){
            while(S[s[l]]>T[s[l]] || T[s[l]]==0){
                S[s[l]]--;
                ++l;
            }
            int len=i-l+1;
            if(len<ans){
                ans=len;
                pos=l;
            }
        }
    }
    if(pos!=-1){
        for(int i=pos; i<=ans+pos-1; i++){
            cout << s[i];
        }
    }
    else cout << -1 << endl;
    system("pause");
    return 0;
}
