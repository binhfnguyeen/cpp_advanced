#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    } 
    map <long long, int> mp;
    long long sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        if(sum==0) {
            cout << "1" << endl;
            return 0;
        }
        if(mp.find(sum)!=mp.end()){
            cout << "1" << endl;
            return 0;
        }
        mp[sum]=1;
    }
    cout << "-1" << endl;
    system("pause");
    return 0;
}