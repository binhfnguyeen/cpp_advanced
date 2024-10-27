#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    int n;
    cout << "Nhap so luong phan tu: " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int q;
    cout << "Nhap so truy van: " << endl;
    cin >> q;
    while(q--){
        int tt; 
        cout << "Nhap thao tac: " << endl;
        cin >> tt;
        if(tt==1) {
            int pos, val;
            cout << "Nhap vi tri: " << endl;
            cin >> pos;
            cout << "Nhap gia tri can them: " << endl;
            cin >> val;
            if(pos>=0 && pos <= v.size()-1) {
                v.insert(v.begin()+pos, val);
            } 
        }
        else {
            int pos; 
            cout << "Nhap vi tri can xoa: " << endl;
            cin >> pos;
            if(pos >=0 && pos <= v.size()-1) {
                v.erase(v.begin()+pos);
            }
        }
    }
    if(v.size()==0) {
        cout << "EMPTY\n";
    } else {
        for(int x: v) {
            cout << x << " ";
        }
    }
    system("pause");
    return 0;
}