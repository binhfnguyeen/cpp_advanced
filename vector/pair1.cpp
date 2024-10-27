#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
double kc(pair<int, int> p) {
    double s= p.first*p.first + p.second * p.second;
    return sqrt(s);
}
int main() {
    vector <pair<int, int>> v;
    int n;
    cout << "Nhap so luong phan tu: " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cout << "Nhap x: " << endl;
        cin >> x;
        cout << "Nhap y: " << endl;
        cin >> y;
        v.push_back({x,y});
    }
    for(auto p: v) {
        cout << fixed << setprecision(2) << kc(p) << " ";
    }
    system("pause");
    return 0;
}