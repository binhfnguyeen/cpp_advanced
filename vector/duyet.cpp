#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Nhap so luong phan tu: " << endl;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int L, R;
    cout << "Nhap gia tri L: " << endl;
    cin >> L;
    cout << "Nhap gia tri R: " << endl;
    cin >> R;
    for(auto it=v.begin()+L; it <=v.begin()+R; it++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it=v.begin()+R; it >= v.begin()+L; it--) {
        cout << *it << " ";
    }
    system("pause");
    return 0;
}