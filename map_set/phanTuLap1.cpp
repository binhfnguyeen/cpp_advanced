#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find(vector <int> v) {
    unordered_set<int> seen;
    for(auto x: v){
        if(seen.find(x) != seen.end()) {
            return x;
        } else {
            seen.insert(x);
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector <int> v;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int result = find(v);
    if(result == -1) {
        cout << "-1" << endl;
    } else {
        cout << result << endl;
    }
    system("pause");
    return 0;
}