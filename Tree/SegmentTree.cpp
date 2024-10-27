#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *makeNode(int x){
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node *insert(Node *root, int key){
    if(root == NULL){
        return makeNode(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    } else if(root->data < key){
        root->right = insert(root->right, key);
    }
    return root;
}

Node *minNode(Node *root){
    Node *tmp = root;
    while(tmp!=NULL && tmp->left!=NULL){
        tmp = tmp->left;
    }
    return tmp;
}
Node *deleteNode(Node *root, int key){
    if(root == NULL) return root;
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    } else if(root->data < key){
        root->right = deleteNode(root->right, key);
    } 
    else {
        if(root->left == NULL){
            Node *tmp = root->right;
            delete root;
            return tmp;
        } else if(root->right==NULL){
            Node *tmp = root->left;
            delete root;
            return tmp;
        } else {
            Node *tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}
int main(){

}