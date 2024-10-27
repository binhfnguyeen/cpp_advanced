#include<iostream>
using namespace std;
const int MAX=100;
struct Stack{
    int a[MAX];
    int top;
};

void init(Stack &s){
    s.top = -1;
}

void push(Stack &s, int x){
    s.top++;
    s.a[s.top]=x;
}

int pop(Stack &s){
    return s.a[s.top--];
}

bool isEmpty(Stack s){
    return s.top<0;
}

bool isFull(Stack s){
    return s.top == MAX-1;
}

void output(Stack s){
    for(int i=s.top; i>=0; i--){
        cout << s.a[i] << " ";
    }
    cout << endl;
}
void decToBin(Stack &s, int x){
    while(x){
        push(s, x%2);
        x/=2;
    }
    output(s);
}
void menu(){
    cout << "===========MENU==========\n";
    cout << "1. Them phan tu\n";
    cout << "2. Xoa phan tu\n";
    cout << "3. Kiem tra stack day\n";
    cout << "4. Kiem tra stack rong\n";
    cout << "5. Duyet stack\n";
    cout << "6. Chuyen thap phan sang nhi phan\n";
    cout << "0. Thoat\n";
    cout << "=========================\n";
}

void decToBin(Stack &s){

}
int main(){
    Stack s;
    init(s);
    int choice; 
    do{
    menu();
    cin >> choice;
    switch (choice)
    {
    case 1: 
        cout << "Them phan tu: \n";
        if(!isFull(s)){
            int x; 
            cout << "Nhap phan tu can them: \n";
            cin >> x;
            push(s, x);
        } else {
            cout << "Stack day khong the them\n";
        }
        break;
    case 2:
        cout << "Xoa phan tu: \n";
        if(!isEmpty(s)){
            cout << "Da xoa phan tu " << pop(s) << endl;
        } else {
            cout << "Stack rong khong the xoa\n";
        }
        break;
    case 3:
        cout << "Kiem tra stack day: \n";
        if(isFull(s)){
            cout << "Stack day\n";
        } else {
            cout << "Stack rong\n";
        }
        break;
    case 4: 
        cout << "Kiem tra stack rong: \n";
        if(isEmpty(s)){
            cout << "Stack rong\n";
        } else {
            cout << "Stack khong rong\n";
        }
        break;
    case 5:
        cout << "Duyet stack: \n";
        output(s);
        break;
    case 6:
        cout << "Chuyen thap phan sang nhi phan\n";
        int x;
        cout << "Nhap so can chuyen: \n";
        cin >> x;
        decToBin(s, x);
        break;
    case 0:
        cout << "Cam on da su dung chuong trinh\n";
        break;
    }
    } while(choice!=0);
    system("pause");
    return 0;
}