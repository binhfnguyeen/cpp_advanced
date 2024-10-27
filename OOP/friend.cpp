#include <iostream>
#include <string>

using namespace std;

class SinhVien{
    private: 
        string name;
        double gpa;
    public: 
        SinhVien(string name, double gpa) {
            this->name=name;
            this->gpa=gpa;
        }
        friend void in(SinhVien x);
};

void in(SinhVien x){
    cout << x.name << endl;
    cout << x.gpa << endl;
}

int main(){
    SinhVien a("Chau Binh Nguyen", 3.2);
    in(a);
    system("pause");
    return 0;
}