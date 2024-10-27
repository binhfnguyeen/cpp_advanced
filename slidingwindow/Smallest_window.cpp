#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

string s;
int n;
int main(){
    cin >> s;
    int n=s.size();
    set <char> se;
    for(auto x: s){
        se.insert(x);
    }
    int sz = se.size();
    map<char, int> cnt;
    int ans = n;
    int freq=0, pos=0;
    for(int i=0; i<n; i++){
        cnt[s[i]]++;
        if(cnt[s[i]]==1) freq++;
        while(pos<=i && freq>=sz){
            ans = min(ans, i-pos+1);
            cnt[s[pos]]--;
            if(cnt[s[pos]]==0) freq--;
            pos++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}