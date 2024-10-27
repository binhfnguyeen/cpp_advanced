#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int n, m, timer=0, scc=0;
vector <int> ke[100005];
int disc[100005], low[100005];
int used[100005], in_stack[100005];
stack <int> st;

void nhap(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(used, false, sizeof(used));
    memset(in_stack, false, sizeof(used));
}

void DFS(int u){
    used[u]=true;
    in_stack[u]=true;
    disc[u]=low[u]=++timer;
    st.push(u);
    for(int v: ke[u]){
        if(!used[v]){
            DFS(v);
            low[u]=min(low[u], low[v]);
        } else if(in_stack[v]) {
            low[u]=min(low[u], disc[v]);
        }
    }
    if(low[u]==disc[u]){
        ++scc;
        while(st.top()!=u){
            cout << st.top() << " ";
            in_stack[st.top()]=false;
            st.pop();
        }
        cout << st.top() << endl;
        in_stack[st.top()]=false;
        st.pop();
    }
}

int main(){
    nhap();
    for(int i=1; i<=n; i++){
        if(!used[i]){
            DFS(i);
        }
    }
    cout << scc << endl;
    system("pause");
    return 0;
}