#include <iostream>
using namespace std;

const int MAX = 100;
int a[MAX][MAX]; // Đồ thị
int C[MAX];      // Mảng đánh dấu đỉnh đã duyệt
int dfs[MAX];    // Mảng lưu kết quả duyệt DFS
int ndfs = 0;
int n, start;    // Số lượng đỉnh và đỉnh bắt đầu

struct Stack {
    int data[MAX];
    int top;

    void init() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        data[++top] = x;
    }

    int pop() {
        return data[top--];
    }

    void remove(int x) {
        int position = -1;
        for (int i = 0; i <= top; i++) {
            if (data[i] == x) {
                position = i;
                break;
            }
        }

        if (position == -1) {
            // Không tìm thấy phần tử cần xóa
            return;
        }

        for (int i = position; i < top; i++) {
            data[i] = data[i + 1];
        }
        top--;
    }
};

Stack sta;

void output() {
    for (int i = 0; i < ndfs; i++) {
        cout << dfs[i] << " ";
    }
    cout << endl;
}

void chuaxet() {
    for (int i = 0; i < n; i++) {
        C[i] = 1;
    }
}

void nhap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i  << "][" << j <<"]=";
            cin >> a[i][j];
        }
    }
}

void DFS(int start) {
    sta.init();
    sta.push(start);
    dfs[ndfs++] = start;
    C[start] = 0;
    int u = start;
    while (!sta.isEmpty()) {
        int v = -1;
        for (v = 0; v < n; v++) {
            if (a[u][v] != 0 && C[v] == 1) {
                sta.push(v);
                dfs[ndfs++] = v;
                C[v] = 0;
                u = v;
                break;
            }
        }
        if (v == n) {
            sta.pop();
            if (!sta.isEmpty()) {
                u = sta.data[sta.top];
            }
        }
    }
}

int main() {
    cin >> n >> start;
    chuaxet();
    nhap();
    DFS(start);
    output();
    system("pause");
    return 0;
}
