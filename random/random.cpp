#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string randomStrGen(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    result.resize(length);

    srand(time(NULL));
    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}

int main(){
    int n;
    cout << "Nhap n: " << endl;
    cin >> n;
    string tmp = randomStrGen(n);
    cout << tmp << endl;
    system("pause");
    return 0;
}