#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v1(n), v2(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }
    for(int i=0; i<n; i++){
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    vector<int> merge(v1.size()+v2.size());
    int i=0, j=0;
    for(int k=0; k< merge.size(); k++){
        if(k%2==0) {
            merge[k]=v1[i++];
        } 
        else {
            merge[k]=v2[j++];
        }
    }
    for(auto it=merge.begin(); it!=merge.end(); ++it) {
        cout << *it << " ";
    }
    system("pause");
    return 0;
}