#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    sort(a, a+n);
    int min_diff=1e9;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int diff=abs(a[i]-a[j]);
            if(diff<min_diff) min_diff=diff;
        }
    }
    cout << min_diff << endl;
    system("pause");
    return 0;
}