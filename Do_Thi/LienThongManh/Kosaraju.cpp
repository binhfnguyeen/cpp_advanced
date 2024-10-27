#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
vector <int> ke[100005], t_ke[100005];
int used[100005];
stack <int> st;

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
    memset(used, false, sizeof(used));
}

void DFS1(int u){
    used[u]=true;
    for(int v: ke[u]){
        if(!used[v]){
            DFS1(v);
        }
    }
    st.push(u);
}

void DFS2(int u){
    used[u]=true;
    cout << u << " ";
    for(int v: t_ke[u]){
        if(!used[v]){
            DFS2(v);
        }
    }
}
//SCC: strongly connected component: Lien thong manh
void kosaraju(){
    for(int i=1; i<=n; i++){
        if(!used[i]){
            DFS1(i);
        }
    }
    memset(used, false, sizeof(used));
    int dem=0;
    while(!st.empty()){
        int start = st.top(); st.pop();
        if(!used[start]){
            ++dem;
            DFS2(start);
            cout << endl;
        }
    }
    if(dem==1){
        cout << "Lien thong manh!\n";
    }
}

int main(){
    nhap();
    kosaraju();
    system("pause");
    return 0;
}