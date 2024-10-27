#include <iostream>
#include <algorithm>
using namespace std;
//Chua cau hinh cuoi: true;
//Cau hinh cuoi: false;
int n, a[100];
void ktao(){
    for(int i=1; i<=n; i++){
        a[i]=i;
    }
}
int main(){
    cin >> n;
    ktao();
    do{
        for(int i=1; i<=n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    } while(next_permutation(a+1, a+n+1));
    system("pause");
    return 0;
}