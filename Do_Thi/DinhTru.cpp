#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, timer=0;
vector <int> ke[100005];
int disc[100005], low[100005];
bool used[100005], AP[100005];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(used, false, sizeof(used));
    memset(AP, false, sizeof(used));
}

void DFS(int u, int par){
    used[u]=true;
    disc[u]=low[u]=++timer;
    int child=0;
    for(int v: ke[u]){
        if(v==par) continue;
        if(!used[v]){
            ++child;
            DFS(v, u);
            low[u]=min(low[u], low[v]);
            if(par!=-1 && disc[u]<=low[v]){
                AP[u]=true;
            }
        } else {
            low[u]=min(low[u], disc[v]);
        }
    } 
    if(par==-1 && child>1) AP[u]=true;
}

int main(){
    nhap();
    for(int i=1; i<=n; i++){
        if(!used[i]){
            DFS(i, -1);
        }
    }
    for(int i=1; i<=n; i++){
        if(AP[i]) cout << i << " ";
    }
    system("pause");
    return 0;
}