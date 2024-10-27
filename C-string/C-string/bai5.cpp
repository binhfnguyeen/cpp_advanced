#include <iostream>
#include <cstring>
#include <cctype>
#include <conio.h>
using namespace std;

int main() {
    char *correctPass = "SinhVienCQ";
    int length = strlen(correctPass);
    char *inPass = new char[length+1];
    int i=0; 
    char ch;
    do{
        cout << "Nhap mat khau: ";
        for(int i=0; i<strlen(inPass); i++){
            ch = _getch();
            if(ch == '\r'){
                break;
            }
            inPass[i] = ch;
            cout << "x ";
        }
        inPass[length] = '\0';
        cout << endl;
        if(strcmp(correctPass, inPass) == 0){
            cout << "Mat khau dung!" << endl;
            break;
        } else {
            cout << "Nhap sai! Nhap lai!" << endl;
            i++;
        }
    } while(i<3);
    delete[] correctPass;
    delete[] inPass;
    system("pause");
    return 0;
}
