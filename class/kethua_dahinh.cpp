#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

// 7
// Nguyen AnH MaNH
// 27/8/2004Nam Dinh
// CNTT2
// 2.70
// pham Phuong TuaN
// 21/9/2004Nam Dinh
// CNTT1
// 2.70
// Vu Ngoc NAM
// 7/9/2004Nam Dinh
// CNTT2
// 3.05
// Vu AnH LoNG
// 17/12/2004Ha Noi
// CNTT1
// 2.80
// Nguyen Phuong NAM
// 23/6/2004Ha Nam
// HTTT3
// 2.80
// Luong AnH NAM
// 16/1/2004Thai Binh
// DTVT1
// 2.80
// Nguyen Phuong HaI
// 14/1/2004Nam Dinh
// DTVT1
// 3.05

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
};

int main(){
    int n; cin >> n;
    vector <Student> v;
    for(int i=0; i<n; i++){
        cin.ignore();
        string ten; getline(cin, ten);
        string s, ns, dc; getline(cin, s); 
        int idx = 0;
        while(!isalpha(s[idx])){
            ns += s[idx];
            ++idx;
        }
        while(idx < s.size()){
            dc += s[idx]; 
            ++idx;
        }
        string lop; getline(cin, lop);
        double gpa; cin >> gpa;
        string ma = to_string(i+1);
        while(ma.size()<4) ma = "0"+ma;
        Student s1(ma, ten, ns, dc, lop, gpa);
        s1.chuanHoa();
        v.push_back(s1);
    }
    for(Student x: v){
        x.in();
    }
    system("pause");
    return 0;
}

