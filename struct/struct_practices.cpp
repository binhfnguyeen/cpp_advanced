#include <iostream>
#include <string>
using namespace std;

struct SinhVien{
    string ten;
    string lop;
    double gpa;
    bool operator > (SinhVien khac){
        return gpa > khac.gpa;
    }
};
int main(){
    SinhVien x{"Nguyen","IT03",3.2};
    SinhVien y{"Vy","IT03",3.1};
    if(x>y) {
        cout << "x co gpa lon hon y";
    };
    system("pause");
    return 0;
}