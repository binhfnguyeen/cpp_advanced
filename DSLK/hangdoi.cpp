#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *makeNode(int x){
    Node *newNode = new Node;
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
//Thêm vào cuối hàng đợi
void push(Node *&queue, int x){
    Node *newNode = makeNode(x);
    if(queue == NULL){
        queue=newNode;
        return;
    }
    Node *tmp = queue;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newNode;
}
//Xóa phần tử khỏi đỉnh
void pop(Node *&queue){
    if(queue == NULL) return;
    Node *tmp = queue;
    queue=queue->next;
    delete tmp;
}

void front(Node *queue){
    if(queue == NULL){
        cout << "EMPTY\n";
    } else {
        cout << queue->data << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    Node *queue = NULL;
    while(n--){
        string x; cin >> x;
        if(x=="pop"){
            cout << "-Xoa phan tu khoi danh sach-\n";
            pop(queue);
        }
        else if(x=="push"){
            cout << "-Them phan tu vao cuoi-\n";
            int y; 
            cout << "Nhap phan tu: \n";
            cin >> y;
            push(queue, y); 
        } else {
            front(queue);
        }
    }
    system("pause");
    return 0;
}
