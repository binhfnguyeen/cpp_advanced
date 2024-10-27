#include <iostream>
using namespace std;

const int MAX = 1000;
int graph[MAX][MAX];
bool visited[MAX];

struct Stack {
    int a[MAX];
    int top;

    void init() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        a[++top] = x;
    }

    int pop() {
        return a[top--];
    }
};

void DFS(int start, int n) {
    Stack s;
    s.init();
    s.push(start);
    visited[start] = true;

    while (!s.isEmpty()) {
        int u = s.pop();
        cout << u << " "; // Xuất đỉnh ra khi duyệt
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n, m; // Dinh va canh
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    int start;
    cin >> start;
    DFS(start, n);

    // Đặt lại trạng thái visited cho lần duyệt tiếp theo
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    cout << endl; // Xuống dòng sau khi hoàn thành duyệt
    system("pause");
    return 0;
}
