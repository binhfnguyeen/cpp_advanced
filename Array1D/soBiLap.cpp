#include <iostream>
using namespace std;
//1 2 2 3 1 => 2 la so bi lap dau tien
// d[1]=1, d[2]=1, *d[2]=2
int d[1000005];
int main(){
    int n; cin >> n;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    for(int x: a){
        d[x]++;
        if(d[x]==2){
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    system("pause");
    return 0;
}