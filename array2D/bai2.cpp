#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap kich thuoc cua ma tran vuong: ";
    cin >> n;

    int a[n][n];
    int value = 1;

    // Gán giá trị từ 1 đến n^2 cho các phần tử của ma trận theo thứ tự zigzag cột
    for (int j = 0; j < n; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                a[i][j] = value;
                value++;
            }
        } else {
            for (int i = n-1; i >= 0; i--) {
                a[i][j] = value;
                value++;
            }
        }
    }

    // Xuất ma trận vừa nhập
    cout << "Ma tran vuong vua nhap la:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
