#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int x, y, w;
};
int n, m, max_size=1;
int parent[100005], sz[100005];
vector <edge> dsCanh;
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
            max_size = max(max_size, sz[x]);
        } else {
            parent[x]=y;
            sz[y]+=sz[x];
            max_size = max(max_size, sz[y]);
        }
        return true;
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void kruskal(){
    //B1: Sort danh sach canh theo trong so tang dan
    sort(dsCanh.begin(), dsCanh.end(), cmp);
    //B2: Lua
    long long d=0; //Cay khung cuc tieu
    vector <edge> mst; //Luu cay khung
    for(int i=0;i<m;i++){
        if(mst.size()==n-1){
            break;
        }
        if(Union(dsCanh[i].x, dsCanh[i].y)){
            mst.push_back(dsCanh[i]);
            d += dsCanh[i].w;
        }
    }
    cout << d << endl;
}
int main() {
    cin >> n >> m;
    ktao();
    for(int i=0; i<m;i++){
        int x, y, w; cin >> x >> y >> w;
        dsCanh.push_back({x, y, w});
    }
    kruskal();
    system("pause");
    return 0;
}

