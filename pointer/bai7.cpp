//Thêm một phần tử vào mảng.
#include <iostream>
using namespace std; 
int main() {
    int *p, n;
    cin >> n;
    p = new int [n+1];
    for(int i=0; i<n; i++){
        cin >> *(p+i);
    }
    int k, x;
    cout << "Nhap phan tu va vi tri muon them: " << endl;
    cin >> x >> k;
    for(int i=n; i>k; i--){
        *(p+i)=*(p+i-1);
    }
    *(p+k)=x;
    n++;
    for(int i=0; i<n; i++){
        cout << *(p+i) << " ";
    }
    delete[] p;
    p = nullptr;
    system("pause");
     return 0;
}