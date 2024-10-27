#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int parent[100005], sz[100005];
void ktao(){
    for(int i=1; i<=n; i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int u){
    if(u==parent[u]){
        return u;
    }
    //return parent[u]=find(parent[u]);
    int x = find(parent[u]);
    parent[u]=x;
    return x;
}

bool Union(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x==y){
        return false;
    } else {
        if(sz[x]>sz[y]) {
            parent[y]=x;
            sz[x]+=sz[y];
        } else {
            parent[x]=y;
            sz[y]+=sz[x];
        }
        return true;
    }
}

void nhap(){
    cin >> n >> m;
    ktao();
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        Union(x, y);
    }
    int dem=0;
    for(int i=1; i<=n; i++){
        if(i == parent[i]){
            dem++;
        }
    }
    cout << dem << endl;
}
int main() {
    nhap();
    system("pause");
    return 0;
}
