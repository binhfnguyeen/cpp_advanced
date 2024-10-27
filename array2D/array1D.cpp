#include <iostream>
using namespace std;
int dem[1000001];
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        dem[a[i]]++;
    }
    int max_val=-1e9;
    int x=0;
    for(int i=0; i<n; i++){
        max_val=max(max_val,dem[a[i]]);
        if(dem[a[i]]>dem[x] || (dem[a[i]]==dem[x] && a[i] < x)){
            x=a[i];
        }
    }
    cout << x << " " << max_val << endl;
    system("pause");
    return 0;
}