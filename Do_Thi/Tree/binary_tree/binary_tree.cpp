#include <iostream>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
};

void init(Node *&root){
    root = NULL;
}

Node *createNode(int x){
    Node *p = new Node;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Node *&root, int x) {
    if (root == NULL) {
        root = createNode(x);
    } else {
        // Tìm vị trí chèn
        Node *p = root;
        Node *parent = NULL;
        while (p != NULL && p->key != x) {
            parent = p;
            if (x < p->key) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        // Thực hiện chèn
        if (p == NULL) {
            p = createNode(x);
            if (x < parent->key) { // Nút cha lớn hơn nút cần chèn
                parent->left = p; // Gán bên trái nút cha
            } else {
                parent->right = p; // Gán bên phải nút cha
            }
        }
    }
}
void lnr(Node *root){
    if(root != NULL){
        lnr(root->left);
        cout << root->key <<"\t";
        lnr(root->right);
    }
}
void nlr(Node *root){
    if(root != NULL){
        cout << root->key << "\t";
        nlr(root->left);
        nlr(root->right);
    }
}

Node *search(Node *root, int x){
    Node *p = root;
    while(p!=NULL && p->key !=x){
        if(p->key > x){
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
}

void deleteNode(Node *&root, int x){
    Node *p = root;
    Node *parent = NULL;
    while(p!=NULL && p->key != x){
        parent = p;
        if(p->key < x){
            p = p->right;
        } else {
            p = p->left;
        }
    }
    //Truong hop canh 2 con
    if(p!=NULL){
        if(p->left!=NULL && p->right !=NULL){
            //Ben phai nut trai nhat
            parent = p;
            Node *t = p->right;
            while(t->left != NULL){
                parent = t;
                t = t->left;
            }
            p->key = t->key;
            p = t;
        }
    }

    Node *r = NULL;
    if(p->left == NULL){
        r = p->right;
    } else {
        r = p->left;
    }

    if(parent == NULL){ //Nut xoa la nut goc
        root = r;
    } else {
        if(parent->key > p->key){
            parent->left = r;
        } else {
            parent->right = r;
        }
    }
    delete p;
}
int main(){
    Node *root;
    init(root);
    insertNode(root, 15);
    insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 40);
    insertNode(root, 12);
    insertNode(root, 90);
    lnr(root);
    cout << endl;
    deleteNode(root, 90);
    nlr(root);
    system("pause");
    return 0;
}