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
//head=head->next;
//head->next: Dia chi cua Node ke tiep;
void duyet(Node *head){ //Truyen tham tri de khong thay doi head;
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}

int count(Node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
void pushFrontC(Node **head, int x){
    Node *newNode = makeNode(x);
    newNode->next=*head; //*head dia chi cua head trong dslk;
    //B2: Cap nhat newNode bang node head;
    *head=newNode;
}
void pushFrontCpp(Node *&head, int x){
    Node *newNode = makeNode(x);
    newNode->next=head;
    head=newNode;
}
int main(int argc, char const *argv[])
{
    Node *head=NULL;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        pushFrontCpp(head, x);
    }
    cout << endl;
    for(int i=0; i<n; i++){
        int d=count(head);
    }
    duyet(head);
    system("pause");
    return 0;
}
