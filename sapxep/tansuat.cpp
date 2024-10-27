#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    unordered_map <int, int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int max_fre=-1e9, max_ele=1e9;
    for(auto i: mp) {
        if(i.second>max_fre) {
            max_fre=i.second;
            max_ele=i.first;
        }
        if(i.second==max_fre && i.first < max_ele) {
            max_ele=i.first;
        }
    } 
    cout << max_ele << " " << max_fre << endl;
    system("pause");
    return 0;
}