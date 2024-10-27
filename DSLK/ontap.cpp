#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
    int id;
    char fullname[100];
    float gpa;
    Student *pLink;
};

Student *sFirst = NULL;

void insertLast()
{
    Student *p = new Student;
    cin >> p->id;
    cin.ignore();
    cin.getline(p->fullname, 100);
    cin >> p->gpa;
    p->pLink = NULL;

    if (sFirst == NULL)
        sFirst = p;
    else
    {
        Student *cur = sFirst;
        while (cur->pLink != NULL){
            cur = cur->pLink;
        }
        cur->pLink = p;
    }
}

void output(){
    Student *p = sFirst;
    while(p!=NULL){
        if(p->gpa>5.0) {
            cout << p->id <<" "<<p->fullname << " " << p->gpa << endl;
        }
        p=p->pLink;
    }
}

void free(){
    Student *p = sFirst;
    while(p!=NULL){
        Student *tmp = p;
        p=p->pLink;
        delete tmp;
    }
    sFirst = NULL;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        insertLast();
    }
    output();
    free();
    output();
    system("pause");
    return 0;
}