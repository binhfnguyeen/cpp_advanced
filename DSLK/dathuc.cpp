#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int heso, somu;
    node *next;
};

node* makeNode(int heso, int somu){
    node *newNode = new node;
    newNode->heso = heso;
    newNode->somu = somu;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        cout << head->heso << "x^" << head->somu;
        head = head->next;
        if(head != NULL) cout << " + ";
    }
    cout << endl;
}

void them(node *&head, int hs, int sm){
    node *temp = head;
    node *prev = head;
    while(temp != NULL){
        if(temp->somu == sm){
            temp->heso += hs;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    node *newNode = makeNode(hs, sm);
    if(prev==NULL){
        head = newNode; return;
    }
    prev->next = newNode;
}

void sx(node *&head){
    for(node *i = head; i!= NULL; i=i->next){
        node *min=i;
        for(node *j=i->next; j!=NULL; j=j->next){
            if(min->somu < j->somu) {
                min = j;
            }
        }
        swap(min->somu, i->somu);
        swap(min->heso, i->heso);
    }
}

int main(){
    node *head = NULL;
    string s;
    while(cin >> s){
        if(s!="+"){
            int hs=0, sm=0;
            int i=0;
            while(s[i]!='x'){
                hs = hs*10+(s[i]-'0');
                i++;
            }
            i+=2;
            while(i<s.size()){
                sm = sm*10 + (s[i]-'0');
                ++i;
            }
            them(head, hs, sm);
        }
    }
    sx(head);
    duyet(head);
    system("pause");
    return 0;
}