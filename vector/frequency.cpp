#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu: " << endl;
    cin >> n;
    int a[n];
    unordered_map <int, int> freq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    vector <pair<int, int>> v;
    for(auto i: freq) {
        v.push_back(make_pair(i.first, i.second));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    system("pause");
    return 0;
}