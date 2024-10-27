#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
    private: 
        string ten, ns, dc;
    public: 
        Person(string ten, string ns, string dc){
            this->ten = ten;
            this->ns = ns;
            this->dc = dc;
        }
        void in(){
            cout << ten << ' ' << ns << ' ' << dc << ' ';
        }
        void chuanHoa(){
            if(ns[1]=='/') ns = "0"+ns;
            if(ns[4]=='/') ns.insert(3, "0");
            stringstream ss(ten);
            string tmp;
            string res="";
            while(ss >> tmp){
                res+=toupper(tmp[0]);
                for(int j=1; j<tmp.size(); j++){
                    res+=tolower(tmp[j]);
                }
                res+=" ";
            }
            res.pop_back();
            ten = res;
        }
        string getTen(){
            return ten;
        }
};

class Student : public Person{
    private: 
        string ma, lop;
        double gpa;
    public: 
        Student(string ma, string ten, string ns, string dc, string lop, double gpa) : Person(ten, ns, dc){
            this->ma = ma;
            this->lop = lop;
            this->gpa = gpa;
        }
        void in(){
            cout << this->ma << ' ';
            Person::in(); //In cua lop cha
            cout << this->lop << ' ' << fixed << setprecision(2) << gpa << endl;
        }
        string getMa(){
            return this->ma;
        }
};

class Lecture : public Person{
    private: 
        string ma, khoa;
        int luong;
    public: 
        Lecture(string ma, string ten, string ns, string dc, string khoa, int luong) : Person(ten, ns, dc){
            this->ma = ma;
            this->khoa = khoa;
            this->luong = luong;
        }
        void in(){
            cout << this->ma << ' ';
            Person::in();
            cout << this->khoa << ' ' << this->luong << endl;
        }
};       

int main(){
    int n; cin >> n;
    vector <Student> v1;
    vector <Lecture> v2;
    for(int i=0; i<n; i++){
        cin.ignore();
        string ma; getline(cin, ma);
        if(ma[0]=='S'){
            string ten; 
            getline(cin, ten);
            string dc, ns; 
            getline(cin, ns); 
            getline(cin, dc);
            string lop; 
            getline(cin, lop);
            double gpa; cin >> gpa;
            Student s1(ma, ten, ns, dc, lop, gpa);
            s1.chuanHoa();
            v1.push_back(s1);
        }
        else {
            string ten; 
            getline(cin, ten);
            string dc, ns; 
            getline(cin, ns); 
            getline(cin, dc);
            string khoa; 
            getline(cin, khoa);
            int luong; cin >> luong;
            Lecture l1(ma, ten, ns, dc, khoa, luong);
            l1.chuanHoa();
            v2.push_back(l1);
        }
    }
    cout << "DANH SACH GIAO VIEN :\n";
    for(Lecture x: v2){
        x.in();
    }
    cout << "DANH SACH SINH VIEN :\n";
    for(Student x: v1){
        x.in();
    }
    system("pause");
    return 0;
}

