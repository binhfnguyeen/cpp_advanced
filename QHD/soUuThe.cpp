#include <iostream>
using namespace std;
long long a[1000005];
int main()
{
    int check[2]={0};
    int count = 0;
    while(cin >> a[count]) {
        check[a[count]%2]++;
        count++;
    }
    if(count%2==0 && check[0]>check[1]) {
        cout << "YES\n";
    } else if(count%2==1 && check[0] < check[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    system("pause");
    return 0;
}
