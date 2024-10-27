#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string s; getline(cin, s);
        for(char &x: s) x=tolower(x);
        vector <string> v;
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) {
            v.push_back(tmp);
        }
        string email=v[v.size()-2];
        for(int i=0; i<v.size()-2; i++){
            email+=v[i][0];
        }
          cout << email << "@ou.edu.vn" << endl;
        string ns=v[v.size()-1];
        stringstream ss1(ns);
         while(getline(ss1, tmp, '/')) {
            cout << stoi(tmp);
        }
    }
    system("pause");
    return 0;
}