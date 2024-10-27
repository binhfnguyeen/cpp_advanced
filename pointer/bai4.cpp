//Sắp xếp các phần tử trong mảng theo thứ tự tăng dần hoặc giảm dần.
#include <iostream>
using namespace std;

int main(){
    int *p, n;
    cin >> n;
    p = new int [n];
    for(int i=0; i<n; i++){
        cin >> *(p+i);
    }
    int temp;
    cout << "Mang tang dan: " << endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(*(p+i)>*(p+j)) {
                temp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }
        }
    }
     for(int i=0; i<n; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
    cout << "Mang giam dan: " << endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(*(p+i)<*(p+j)) {
                temp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }
        }
    }
     for(int i=0; i<n; i++){
        cout << *(p+i) << " ";
    }
    delete[] p;
    p = nullptr;
    system("pause");
    return 0;
}