#include <iostream>
using namespace std;
//Chung canh => 8 o xung quanh;
pair <int, int> d[8] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int dem=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bool check = true;
            for(int k=0; k<8; k++){
                int i1=i+d[k].first;
                int j1=j+d[k].second;
                if(i1>=0 && i1 < n && j1>=0 && j1<m ) {
                    if(a[i1][j1] >= a[i][j]) {
                        check = false;
                        break;
                    }
                }
            }
            if(check) ++dem;
        }
    }
    cout << dem << endl;
    system("pause");
    return 0;
}