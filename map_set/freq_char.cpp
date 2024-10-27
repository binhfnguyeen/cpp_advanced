//Dùng mảng đánh dấu;
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s; cin >> s;
    char c[256] = {0};
    int max_fre = 0, min_fre = 1e9;
    map <char, int> mp;
    for(char c: s) {
        mp[c]++;
    }
    char max_val, min_val;
    for(char key= 'a'; key <= 'z'; key++){
        if(mp[key]==0) continue;
        if(mp[key] > max_fre) {
            max_fre = mp[key];
            max_val = key;
        }
        if(mp[key] <= min_fre) {
            min_fre = mp[key];
            min_val = key;
        }
    }
    cout << max_val << " " << max_fre << endl;
    cout << min_val << " " << min_fre << endl;
    int cnt=0;
    for(char i='a'; i<='z'; i++){
        if(mp[i]) cnt++;
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}