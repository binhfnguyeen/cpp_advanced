#include <iostream>
#include <algorithm>
using namespace std;
//Chia mang con kich thuoc co k va n-k;
//Hieu hai mang con lon nhat
int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x: a){
        cin >> x;
    }
    k=min(k, n-k);
    long long sum1=0, sum2=0;
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if(i<k) sum1+=a[i];
        else sum2+=a[i];
    }
    cout << sum2-sum1 << endl;
    system("pause");
    return 0;
}