#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
//Tao 1 node moi co data x va tra ve node do
node *makeNode(int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    while(head!=NULL){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
int SZ(node *head){
    int dem=0;
    while(head!=NULL){
        ++dem;
        head=head->next;
    }
    return dem;
}
//Them 1 node co data la x vao dau dslk do head quan ly
void themdau(node *&head, int x){
    node *newNode = makeNode(x);
    //Buoc 1: cho newNode tro vao node head hien tai
    newNode->next = head;
    //Buoc 2: cap nhat cho head bang newNode
    head = newNode;
}
void themcuoi(node *&head, int x){
    node *newNode = makeNode(x);
    //di den node cuoi trong dslk
    if(head==NULL){
        head=newNode;
        return;
    }
    node *tmp=head; // dung de duyet
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next=newNode;
}
void themgiua(node *&head, int x ,int k) {
    int n= SZ(head);
    if(k<1 || k>n+1){
        return;
    }
    if(k==1){
        themdau(head, x); return;
    }
    node *newNode = makeNode(x);
    node *tmp = head;
    for(int i=0; i<=k-2; i++){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;
}
void xoadau(node *&head){
    if(head==NULL){
        return;
    }
    node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
void xoacuoi(node *&head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        node *delNode = head; head=NULL;
        delete delNode;
        return;
    }
    node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node *deleteNode = temp->next;
    temp->next=NULL;
    delete deleteNode;
}
void xoagiua(node *&head, int k){
    int n=SZ(head);
    if(k<1 || k> n) return;
    if(k==1) {
        xoadau(head);
    }
    node *tmp = head;
    for(int i=1; i<=k-2; i++){
        tmp = tmp->next;
    }
    //tmp: k-1;
    node *delNode = tmp->next;
    tmp->next = delNode->next; //gan dia chi cua node k-1=k+1
    delete delNode;
}
int main(){
    node *head = NULL;
    while(true){
        cout << "--------------------MENU--------------------\n";
        cout << "| 1. Them dau                              |\n";
        cout << "| 2. Them cuoi                             |\n";
        cout << "| 3. Them giua                             |\n";
        cout << "| 4. Xoa dau                               |\n";
        cout << "| 5. Xoa cuoi                              |\n";
        cout << "| 6. Xoa giua                              |\n";
        cout << "| 7. Duyet                                 |\n";
        cout << "| 0. Thoat!                                |\n";
        cout << "--------------------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        if(lc==1){
            int x; cout << "Nhap gia tri can them: \n";
            cin >> x;
            themdau(head, x);
        }
        else if(lc==2) {
            int x; cout << "Nhap gia tri can them: \n";
            cin >> x;
            themcuoi(head, x);
        } else if (lc==3){
            int k, x;
            cout << "Nhap gia tri can them: \n";
            cin >> x;
            cout << "Nhap vi tri can them: \n";
            cin >> k;
            themgiua(head, x, k);
        } else if(lc==4) {
            xoadau(head);
        } else if(lc==5) {
            xoacuoi(head);
        } else if(lc==6) {
            int k;
            cout << "Nhap vi tri xoa: \n";
            cin >> k;
            xoagiua(head, k);
        }else if(lc==7) {
            duyet(head);
        } else if(lc==0) {
            break;
        }
    }
    system("pause");
    return 0;
}