//Tìm kiếm một phần tử trong mảng.
#include <iostream>
using namespace std;

int main(){
    int *p, n;
    cin >> n;
    p = new int [n];
    for(int i=0; i<n; i++){
        cin >> *(p+i);
    }
    int x;
    cin >> x;
    int ok=0;
    for(int i=0; i<n; i++){
        if(*(p+i)==x) {
            ok=1;
        } 
    }
    if(ok) {
        cout << x << " co trong mang!" << endl;
    } else cout << x << " khong co trong mang!" << endl;
    delete[] p;
    p = nullptr;
    system("pause");
    return 0;
}