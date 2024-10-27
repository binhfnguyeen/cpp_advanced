#include <iostream>
#include <iomanip>
using namespace std;

struct node{
    char *id;
    char *name;
    double gpa;
    node *next;
};
double max_gpa=0;

node *makeNode(){
    node *newNode = new node;
    newNode->id = new char[100];
    newNode->name = new char[100];
    cin.ignore();
    gets(newNode->id);
    gets(newNode->name);
    cin >> newNode->gpa;
    max_gpa = max(max_gpa, newNode->gpa);
    newNode->next = NULL;
    return newNode;
}

void push(node *&head){
    node *newNode = makeNode();
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main(){
    node *head = NULL;
    int n; cin >> n;
    while(n--){
        push(head);
    }
    while(head!=NULL){
        if(head->gpa == max_gpa){
            cout << head->id << ' ' << head->name << ' ' << fixed << setprecision(2) << head->gpa << endl;
        }
        head=head->next;
    }
    system("pause");
    return 0;
}