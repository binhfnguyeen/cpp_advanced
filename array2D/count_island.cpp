#include <iostream>
using namespace std;
//Chung canh 4 o => nhu '+';

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[100][100];
int n, m;
void nhap(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
}
void Loang(int i, int j){
    a[i][j]=0;
    for(int k=0; k<4; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1 >= 0 && i1 < n && j1 >=0 && j1 < m && a[i1][j1]==1) {
            Loang(i1, j1);
        }
    }
}
int main(){
    nhap();
    int dem=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==1){
                ++dem;
                Loang(i, j);
            }
        }
    }
    cout << dem << endl;
    system("pause");
    return 0;
}