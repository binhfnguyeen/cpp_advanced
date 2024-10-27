#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream fileOut;
    fileOut.open("luyentap.txt", ios::out | ios::in);
    int n;
    cin >> n;
    int tich=1;
    while(n--) {
        int x;
        cin >> x;
        fileOut << x << endl;
        tich = tich * x;
    }
    fileOut << "Tich cac truy van: " << tich << endl;
    fileOut.close();
    system("pause");
    return 0;
}