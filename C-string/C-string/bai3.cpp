#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

char *deleteSpace(const char *p){
    char *p1 = new char[strlen(p)];
    strcpy(p1, p);
    for(int i=1; i < strlen(p1)-1; i++){
        if(p1[0] == ' ' && p1[strlen(p1)-1]==' '){
            p1[i-1] = p1[i]; 
        }
    }
    return p1;
}

int countSpace(const char *p){
    int count = 0;
    for(int i=0; i<strlen(p); i++){
        if(isspace(p[i])){
            count++;
        }
    }
    return count;
}
int main(){
    char *a;
    a = new char[100];
    cout << "Nhap chuoi: ";
    cin.getline(a, 100);
    char *rs = deleteSpace(a);
    cout << rs << endl;
    int dem;
    dem = countSpace(a);
    cout << "So khoang trang: " << dem << endl;
    system("pause");
    return 0;
}