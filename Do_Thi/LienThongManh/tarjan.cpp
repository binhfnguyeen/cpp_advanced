#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, timer=0;
vector <int> ke[100005];
int disc[100005], low[100005];
int used[100005];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

void DFS(int u){
    used[u]=true;
    disc[u]=low[u]=++timer;
    for(int v: ke[u]){
        if(!used[v]){
            DFS(v);
            low[u]=min(low[u], low[v]);
        } else {
            low[u]=min(low[u], disc[v]);
        }
    }
}

int main(){
    nhap();
    for(int i=1; i<=n; i++){
        if(!used[i]){
            DFS(i);
        }
    }
    for(int i=1; i<=n; i++){
        cout << disc[i] << " " << low[i] << endl;
    }
    system("pause");
    return 0;
}