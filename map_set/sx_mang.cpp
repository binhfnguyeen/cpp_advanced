#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void tach(int n, set<int> digits) {
    while(n) {
        int digit=n%10;
        digits.insert(digit);
        n/=10;
    }
}
void sortA(int a[], int n, int sortDigit[]){
    set <int> digits;
    for(int i=0; i<10; i++){
        tach(a[i], digits);
    }
    int idx=0;
    for(int digit: digits){
        sortDigit[idx++]=digit;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    int sortDigit[n];
    sortA(a, n, sortDigit);
    for(int &x: a) cin >> x;
    for(int i=0; i<10; i++){
        if(sortDigit[i]!=0){
            cout << sortDigit[i] << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}