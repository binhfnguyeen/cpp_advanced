#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;
char x[1005];
string val[10];
void xuly(){
    val[2]="abc";
    val[3]="def";
    val[4]="ghi";
    val[5]="jkl";
    val[6]="mno";
    val[7]="pqrs";
    val[8]="tuv";
    val[9]="wxyz";
}
void ql(int i){
    for(char c: val[s[i]-'0']){
        x[i]=c;
        if(i==s.size()-1){
            for(int u=0; u<=s.size()-1; u++){
                cout << x[u];
            }
            cout << " ";
        } else {
            ql(i+1);
        }
    }
}
int main(){
    xuly();
    cin >> s;
    sort(s.begin(), s.end());
    ql(0);
    system("pause");
    return 0;
}