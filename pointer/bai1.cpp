#include <iostream>
using namespace std;
const int r=3;
const int c=3;
int main() {
    int a[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int offset=i*c+j;
            cin >> *(&a[0][0]+offset);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int offset=i*c+j;
            cout << *(&a[0][0]+offset) << " ";
        }
        cout << endl;
    }
    system("pause");
        return 0;
}