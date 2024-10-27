#include <iostream>
using namespace std; 

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int &x: a) {
        cin >> x;
    }
    int first_idx = -1, last_idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            if (first_idx == -1) {
                first_idx = i;
            }
            last_idx = i;
        }
    }
    if (first_idx == -1 && last_idx==-1) {
        cout << "-1" << endl;
    } else {
        cout << first_idx << " " << last_idx << endl;
    }
    system("pause");
    return 0;
}