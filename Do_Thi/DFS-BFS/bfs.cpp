#include <iostream>
using namespace std;
const int MAX=1000;
int graph[MAX][MAX];
bool visited[MAX];
struct Queue
{
    int a[MAX];
    int front, rear;

    void init(){
        front = rear = -1;
    }

    bool isEmpty(){
        return rear == -1 && front == -1;
    }
    
    void Push(int x) {
	    if (rear - front == MAX - 1) { //Queue day khong them
		    cout << "Queue day!\n";
		    return;
	    }
	    if (front == -1) { //Queue rong
		    front = 0; //Them gia tri moi
	    }
	    if (rear == MAX - 1) { //Queue bi tran
		    for (int i = front; i <= rear; i++) { //Doi nguyen khoi tu front den rear xuong duoi
			    a[i - front] = a[i]; //Tinh tien cac phan tu trong Queue
		    }
		    rear = MAX - 1 - front; //Rear nhan gia tri moi sau khi tinh tien
		    front = 0; //Front nhan gia tri moi sau khi tinh tien
	    }
	    a[++rear] = x; //Tang rear roi gan x
    }

    int Pop() {
	    if (front == -1) { //Queue rong khong xoa nua
		    cout << "Queue rong!\n";
		    return 0;
	    }
	    else {
		   int x = a[front]; 
		    //Lay tung phan tu
		    if (rear == front) {
			    front = -1;
			    rear = -1;
		    }
		    else {
			    front = (front + 1) % MAX;
		    }
		    return x;
	    }
    }
};

void BFS(int start, int n){
    Queue q;
    q.init();
    q.Push(start);
    visited[start]=true;
    while(!q.isEmpty()){
        int u = q.Pop();
        cout << u << " ";
        for(int v=1; v<=n; v++){
            if(graph[u][v] && !visited[v]){
                q.Push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v]=graph[v][u]=1;
    }
    int start; cin >> start;
    BFS(start, n);
    system("pause");
    return 0;
}