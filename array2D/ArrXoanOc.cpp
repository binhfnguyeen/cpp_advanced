#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    int dem=1;
    int h1=0, h2=n-1, c1=0, c2=n-1;
    while(dem <= n*n){
        for(int cot=c1; cot<=c2; cot++){
            a[h1][cot]=dem; dem++;
        }
        h1++;
        for(int hang=h1; hang <= h2; hang++){
            a[hang][c2]=dem; dem++;
        }
        c2--;
        for(int cot=c2; cot>=c1; cot--){
            a[h2][cot]=dem; dem++;
        }
        h2--;
        for(int hang=h2;hang>=h1;hang--){
            a[hang][c1]=dem; dem++;
        }
        c1++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(5) << a[i][j] << " " << setw(5);
        }
        cout << endl;
    }
    system("pause");
    return 0;
}