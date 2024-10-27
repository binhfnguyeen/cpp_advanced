#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream outFile;
    outFile.open("bai1.txt",ios::out);
    string name;
    getline(cin, name);
    int nam;
    cin >> nam;
    outFile << "Name: " << name << endl << "Year: " << nam << endl;
    outFile.close();
    ifstream outFile;
    outFile.open("bai1.txt",ios::in);
    if(outFile.is_open()) {
        
    }
    outFile.close();
    system("pause");
    return 0;
}