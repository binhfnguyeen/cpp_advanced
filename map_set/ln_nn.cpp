#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        mp[x]=1;
    }
    int q; cin >> q;
    while(q--) {
        int tt;
        cout << "Nhap thao thac: " << endl;
        cin >> tt;
        if(tt==1) {
            cout << "Nhap gia tri can them: " << endl;
            int x; cin >> x;
            mp[x]=1;
        } else if(tt==2) {
            cout << "Nhap gia tri can xoa: " << endl;
            int x; cin >> x;
            auto it = mp.find(x);
            if(it != mp.end()){
                mp.erase(it);
            }
        } else if (tt==3) {
            cout << "Gia tri nho nhat: " << endl;
            auto it = mp.begin();
            cout << (*it).first << endl;
        } else if(tt==4) {
            cout << "Gia tri lon nhat: " << endl;
            auto it = mp.end();
            it--;
            cout << (*it).first << endl;
        }
    }
    system("pause");
    return 0;
}