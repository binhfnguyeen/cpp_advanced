//Viết chương trình tìm phần tử có giá trị nhỏ nhất trong mỗi hàng của mảng hai chiều.
#include <iostream>
using namespace std;
const int r = 3;
const int c = 4;
void find_min(int a[][c], int minArr[]) {
    int *p= NULL;
    for(int i=0; i<r; i++){
        p = a[i];
        int min=*p;
        for(int j=0; j<c; j++){
            if(*(p+j) < min) {
                min=*(p+j);
            }
        }
        minArr[i]=min;
    }
}
int main(){
    int a[r][c];
    int minArr[r];
     for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    find_min(a, minArr);
    for(int i=0; i<r; i++){
        cout << "Gia tri nho nhat cua hang " << i+1 << " la " << minArr[i] << endl;
    }
    system("pause");
    return 0;
}