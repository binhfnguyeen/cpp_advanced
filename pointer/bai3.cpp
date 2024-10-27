//Tìm tổng hoặc trung bình cộng của các phần tử trong mảng.
#include <iostream>
using namespace std;

int main(){
    int *p, n;
    cin >> n;
    p = new int [n];
    int cnt=0;
    int tong=0;
    for(int i=0; i<n; i++){
        cin >> *(p+i);
        cnt++;
    }
    for(int i=0; i<n; i++){
        tong+=*(p+i);
    }
    cout << "Tong: " << tong << endl;
    cout << "TBC: " << (double)tong/cnt << endl;
    delete[] p;
    p= nullptr;
    system("pause");
    return 0;
}