#include <iostream>
#include <algorithm>
using namespace std;
// Cho hai dãy số nguyên dương A và B. 
// Hãy trộn hai dãy với nhau sao cho dãy A 
// được đưa vào các vị trí có chỉ số chẵn, 
// dãy B được đưa vào các vị trí có chỉ số lẻ. 
//Đồng thời, dãy A được sắp xếp tăng dần, 
// còn dãy B được sắp xếp giảm dần.
int main(){
    int n; cin >> n;
    int a[n], b[n];
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    for(int i=0; i<n; i++){
        cout << a[i] << " " << b[i] << " ";
    }
    system("pause");
    return 0;
}