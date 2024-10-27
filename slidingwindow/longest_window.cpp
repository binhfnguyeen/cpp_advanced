#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
int n;
int main(){
    cin >> s;
    n=s.size();
    int ans=1;
    map<char, int> cnt;
    int pos=0;
    for(int i=0; i<n; i++){
        cnt[s[i]]++;
        while(pos<=i && cnt[s[i]]>1){
            cnt[s[pos]]--;
            pos++;
        }
        ans=max(ans, i-pos+1);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
