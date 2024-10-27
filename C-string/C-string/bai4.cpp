#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

bool isPalinChar(const char *p){
    int len = strlen(p);
    for(int i=0; i<len/2; i++){
        if(p[i] != p[len-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    char *a;
    a=new char[100];
    cout << "Nhap chuoi a: ";
    cin.getline(a, 100);
    if(isPalinChar(a) == true){
        cout << a << " is Palindrome" << endl;
    } else {
        cout << a << " is not Palindrome" << endl;
    }
    system("pause");
    return 0;
}