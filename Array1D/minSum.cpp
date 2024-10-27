#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    sort(a, a+n);
    string num1="0", num2="0";
    for(int i=0; i<n; i++){
        if(i%2==0){
            num1+=to_string(a[i]);
        } else {
            num2+=to_string(a[i]);
        }
    }
    cout << stoll(num1) + stoll(num2) << endl;
    system("pause");
    return 0;
}