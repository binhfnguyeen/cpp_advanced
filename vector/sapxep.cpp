#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Nhap so luong phan tu: " << endl;
    cin >> n;
    vector <int> v;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for(auto x: v){
        cout << x << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}