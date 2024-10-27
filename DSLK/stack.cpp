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
//Thêm vào đầu
void push(Node *&stack, int x){
    Node *newNode = makeNode(x);
    if(stack == NULL){
        stack = newNode;
        return;
    }
    newNode->next=stack;
    stack=newNode;
}
//Xóa một phần tử khỏi đỉnh
void pop(Node *&stack){
    if(stack == NULL) return;
    Node *tmp = stack;
    stack = stack->next;
    delete tmp;
}
//*stack.data
void show(Node *stack){
    if(stack == NULL){
        cout << "EMPTY\n";
    } else {
        while(stack!=NULL){
            cout << stack->data << " ";
            stack=stack->next;
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    Node *stack=NULL;
    while(n--){
        string s; cin >> s;
        if(s=="pop"){
            cout << "-Da day mot phan tu-\n";
            pop(stack);
        } else if(s=="push"){
            int x; 
            cout << "-Them vao mot phan tu-\n";
            cout << "Nhap gia tri: \n";
            cin >> x;
            push(stack, x);
        } else {
            cout << "-Hien thi danh sach-\n";
            show(stack);
        }
    }
        system("pause");
    return 0;
}
