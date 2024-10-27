#include <iostream>
#include <vector>
using namespace std;
int check(vector<int> v){
    int c=0, l=0;
    for(int x: v){
        if(x%2==0) c++;
        else l++;
    }
    int n=v.size();
    return n%2==0 && c>l || n%2==1 && c<l;
}
int main(){
    int n;
    vector<int> v;
    while(cin >> n) {
        v.push_back(n);
    }
    if(check(v)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    system("pause");
    return 0;
}