#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int maxn = 1001;

struct Canh
{
    int x, y, w;
};

int n, m;
vector <pair<int,int>> adj[maxn];
bool used[maxn];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u){
    vector <Canh> MST; //Cay khung
    int d=0; //Chieu dai cay khung
    used[u]=true; //Dua dinh u vao tap V(MST)
    while(MST.size()<n-1){
        //e = (x, y): Canh ngan nhat co x thuoc V va y thuoc V(MST)
        int min_w = INT_MAX;
        int X, Y; //Luu hai dinh canh e
        for(int i=1; i<=n; i++){
            //Neu dinh i thuoc tap V(MST)
            if(used[i]){
                //Duyet danh sach ke cua dinh i
                for(pair<int,int> it: adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!used[j] && trongso < min_w){
                        min_w = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d+=min_w; //Cap nhat do dai
        used[X] = true; //Cho dinh X vao V(MST), loai X khoi tap V
    }
    cout << d << endl;
    for(Canh e: MST){
        cout << e.x << " " << e.y << " " << e.w << endl;
    }
}

int main(){
    nhap();
    prim(1);
    system("pause");
    return 0;
}