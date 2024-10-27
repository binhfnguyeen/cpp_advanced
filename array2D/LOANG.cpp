//Quan trong va kho !
#include <iostream>
using namespace std;

int n, m, a[505][505];
int used[505][505];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void loang(int i, int j){
    cout << i << " " << j << endl;
    used[i][j]=true;
    for(int k=0; k<4; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1&&i<=n&&j1>=1&&j1<=m&&a[i1][j1]==1&&used[i1][j1]==false){
            loang(i1,j1);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]==1 && used[i][j]==false) {
                cout << "Bat dau loang " << i << ", " << j << endl;
                loang(i, j);
            }
        }
    }
    system("pause");
    return 0;
}