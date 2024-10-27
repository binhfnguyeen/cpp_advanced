#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *makeNode(int x){
    Node *newNode = new Node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void themdau(Node *&head, int x){
    Node *newNode=makeNode(x);
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}

void themcuoi(Node *&head, int x){
    Node *newNode = makeNode(x);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newNode;
    newNode->prev=tmp;
}
void duyet(Node *head){
    while(head->next!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}
int sz(Node *head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void themgiua(Node *&head, int x, int k){
    int n = sz(head);
    if(k<1 || k>n+1){
        return;
    }
    if(k==1){
        themdau(head, x);
        return;
    }
    Node *tmp = head;
    for(int i=1; i<=k-1; i++){
        tmp=tmp->next;
    }
    Node *newNode = makeNode(x);
    newNode->next=tmp;
    tmp->prev->next=newNode;
    newNode->prev=tmp->prev;
    tmp->prev=newNode;
}
int main(){
    Node *head= NULL;
    while(true){
        int choice;
        cin >> choice;
        if(choice==1){
            int x; cin >> x;
            themdau(head, x);
        } else if(choice==2){
            int x; cin >> x;
            themcuoi(head, x);
        } else if(choice==3){
            int x, k;
            cin >> x >> k;
            themgiua(head, x, k);
        } else if(choice==4){
            duyet(head);
        }
        else {
            break;
        }
    }
    system("pause");
    return 0;
}