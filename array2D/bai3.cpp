#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap kich thuoc cua ma tran vuong: ";
    cin >> n;

    int a[n][n];
    int top = 0, bottom = n-1, left = 0, right = n-1;
    int value = 1;

    while (top <= bottom && left <= right) {
        // Gan cac phan tu tren canh trai
        for (int i = top; i <= bottom; i++) {
            a[i][left] = value;
            value++;
        }
        left++;

        // Gan cac phan tu tren canh duoi
        for (int j = left; j <= right; j++) {
            a[bottom][j] = value;
            value++;
        }
        bottom--;

        // Gan cac phan tu tren canh phai
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                a[i][right] = value;
                value++;
            }
            right--;
        }

        // Gan cac phan tu tren canh tren
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                a[top][j] = value;
                value++;
            }
            top++;
        }
    }

    // In ma tran
    cout << "Ma tran vuong vua nhap:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}