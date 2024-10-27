//Xóa một phần tử trong mảng.
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
            for(int j=i; j<n-1; j++){
                *(p+j)=*(p+j+1);
            }
            n--;
            break;
        }
    }
    if(ok) {
        cout << x << " co trong mang!" << endl;
        cout << "Mang sau khi xoa: " << endl;
        for(int i=0; i<n; i++) {
            cout << *(p+i) << " ";
        }
    } else cout << x << " khong co trong mang!" << endl;
    delete[] p;
    p = nullptr;
    system("pause");
    return 0;
}