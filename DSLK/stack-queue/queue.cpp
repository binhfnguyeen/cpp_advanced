#include <iostream>
using namespace std;
const int MAX=100;
struct Queue{
    int a[MAX];
    int front;
    int rear;
};

void init(Queue &q){
    q.front = -1;
    q.rear = -1;
}

int push(Queue &q, int x){
    if(q.rear-q.front == MAX-1){
        return 0;
    }
    else {
        if(q.front == -1){
            q.front = 0;
        } 
        if(q.rear==MAX-1){
            for(int i=q.front; i<=q.rear; i++){
                q.a[i-q.front] = q.a[i];
            }
            q.rear = MAX-1-q.front;
            q.front = 0;
        }
        q.a[++q.rear]=x;
        return 1;
    }
}

int pop(Queue &q){
    if(q.front==-1){
        return 0;
    } else {
        int x=q.a[q.front++];
        if(q.front > q.rear){
            q.front = -1;
            q.rear = -1;
        }
        return 1;
    }
}
int main(){
    Queue q;
    init(q);
    int choice;
    do{
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Them mot phan tu: \n";
            int x; cout << "Nhap phan tu: \n";
            cin >> x;
            cout << "Da them: " << push(q, x) << endl;
            break;
        case 2:
            cout << "Xoa phan tu: \n";
            cout << "Da xoa: " << pop(q) << endl;
        case 0:
            break;
        }
    } while(choice!=0);
    system("pause");
    return 0;
}