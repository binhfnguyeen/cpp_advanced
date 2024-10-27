//Tìm phần tử lớn nhất hoặc nhỏ nhất trong mảng.
#include <iostream>
using namespace std;
void nhap(int *p, int n){
    for(int i=0; i<n; i++){
        cin >> *(p+i);
    }
}
int main(){
    int *p, n;
    cin >> n;
    p = new int [n];
    nhap(p, n);
    int max=*p;
    int min=*p;
    for(int i=0; i<n; i++){
        if(*(p+i)>max) {
            max=*(p+i);
        }
        if(*(p+i)<min){
            min=*(p+i);
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    delete[]p;
    p = nullptr;
    system("pause");
    return 0;
}