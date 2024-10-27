#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, m;
vector <ii> adj[1000005];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, w; cin >> x >> y>>w;
        adj[x].push_back({y, w});
    }
}

void dijktra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0,s});
    vector <long long> d(n+1, 1e9);
    d[s]=0;
    while(!Q.empty()){
        ii top = Q.top(); Q.pop();
        int kc = top.first, u = top.second;
        if(kc>d[u]) continue;
        //relaxation
        for(ii it: adj[u]){
            int v = it.first, w = it.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                Q.push({d[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << d[i] << " ";
    }
}

int main(){
    nhap();
    dijktra(1);
    system("pause");
    return 0;
}