#include <iostream>
using namespace std;

int main() {
    int a[3][4];
    int i=0;
    while(i<3) {
        int j=0;
        while(j<4){
            cin >> a[i][j];
            j++;
        }
        i++;
    }
    i=0;
    while(i<3) {
        int j=0;
        while(j<4){
            cout << a[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << "Tong cac gia tri trong mang: " << endl;
      int tong=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            tong+=a[i][j];
        }
    }
    cout << tong << endl;
    cout << "Gia tri lon nhat: " << endl;
    int max_val= -1e9;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(a[i][j]>max_val) {
                max_val=a[i][j];
            }
        }
    }
    cout << max_val << endl;
    cout << "Gia tri nho nhat: " << endl;
    int min_val=1e9;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(a[i][j]<min_val) {
                min_val=a[i][j];
            }
        }
    }
    cout << min_val << endl;
    cout << "Nhap vi tri cot can tinh tong: " << endl;
    int col;
    cin >> col;
    int sum=0;
    for(int i=0; i<3; i++) {
        sum+=a[i][col];
    }
    cout << sum << endl;
    cout << "Nhap vi tri hang can tinh tong: " << endl;
    int row;
    cin >> row;
    int sum2=0;
    for(int j=0; j<4; j++) {
        sum+=a[row][j];
    }
    cout << sum2 << endl;
    cout << "Nhap x: " << endl;
    int x;
    cin >> x;
    int ok = 0;
    int cnt=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(a[i][j]==x) {
                ok=1;
                cnt++;
            }
        }
    }
    if(ok) {
        cout << x << " co trong mang!" << endl;
        cout << x << " xuat hien " << cnt << " lan!" << endl;
    }
    else cout << x << " khong co trong mang!" << endl;
    system("pause");
    return 0;
}