#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char *formatChuoi(const char *p){
    char *p1 = new char[strlen(p)+1];
    strcpy(p1, p);
    for(int i=0; i<strlen(p1); i++){
        if(p1[i] == ',' || p1[i] == '.'){
            p1[i] = ' ';
        }
    } 
    char *token = strtok(p1, " ");
    char *tmp = new char[strlen(p)+1];
    strcpy(tmp, "");
    while(token != nullptr){
        strcat(tmp, token);
        strcat(tmp, " ");
        token = strtok(nullptr, " ");
    }
    return tmp;
}
int main(){
    char *a;
    a = new char[100];
    cout << "Nhap chuoi: ";
    cin.getline(a, 100);
    char *result = formatChuoi(a);
    cout << "Chuoi sau khi format: " << result << endl;
    delete[] result;
    delete[] a;
    system("pause");
    return 0;
}