#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string s;
    cin >> s;
    vector<pair<char, int>> freq;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        bool found=false;
        for(int j=0; j<freq.size(); j++){
            if(freq[j].first==c) {
                freq[j].second++;
                found=true;
                break;
            }
        }
        if(!found) {
            freq.push_back(make_pair(c, 1));
        }
    }
    for(int i=0; i<freq.size(); i++){
        cout << freq[i].first << " " << freq[i].second << endl;
    }
    system("pause");
    return 0;
}