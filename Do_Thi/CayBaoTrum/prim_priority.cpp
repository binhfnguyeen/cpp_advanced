#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <functional>
using namespace std;

const int maxn = 1001;

struct Canh
{
    int x, y, w;
};

int n, m;
vector <pair<int,int>> adj[maxn];
bool used[maxn];
int parent[maxn], d[maxn];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
    for(int i=1; i<=n; i++){
        d[i]=INT_MAX;
    }
}

void prim(int u){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    vector <Canh> MST;
    int res=0;
    Q.push({0, u});
    while(!Q.empty()){
        pair<int, int> top = Q.top(); Q.pop();
        int dinh = top.second, trongso = top.first;

        if(used[dinh]) continue;
        res+=trongso;
        used[dinh]=true;

        if(u!=dinh){
            MST.push_back({dinh, parent[dinh], trongso});
        }
        //Duyet tat ca cac dinh ke
        for(auto it: adj[dinh]){
            int y = it.first;
            int w = it.second;
            if(!used[y] && w < d[y]){ //Luu cay khung thi them w < d[y];
                Q.push({w, y});
                d[y]=w;
                parent[y]=dinh;
            }
        }
    }
    cout << res << endl;
    for(auto it: MST){
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

int main(){
    nhap();
    prim(1);
    system("pause");
    return 0;
}