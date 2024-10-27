#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    vector<pair<int, int>> freq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        bool found=false;
        for(int j=0; j<freq.size(); j++){
            if(freq[j].first==a[i]) {
                freq[j].second++;
                found=true;
                break;
            }
        }
        if(!found) {
            freq.push_back(make_pair(a[i], 1));
        }
    }
        for(int i=0; i<freq.size(); i++){
            cout << freq[i].first << " " << freq[i].second << endl;
        }
        system("pause");
        return 0;
}