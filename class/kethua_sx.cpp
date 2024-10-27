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
//Nguyen Chi Vy => Vy Nguyen Chi
string getCmpName(string s){
    stringstream ss(s);
    string tmp, name="";
    string res = "";
    vector <string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    res = v[v.size()-1] +" ";
    for(int i=0; i<v.size()-1; i++) {
        res +=v[i] + " ";
    }
    return res;
}
bool cmp(Student a, Student b){
    string name1 = getCmpName(a.getTen());
    string name2 = getCmpName(b.getTen());
    if(name1 != name2) return name1 < name2;
    return a.getMa() < b.getMa();
}
int main(){
    int n; cin >> n;
    vector <Student> v;
    for(int i=0; i<n; i++){
        cin.ignore();
        string ten; 
        getline(cin, ten);
        string dc, ns; 
        getline(cin, ns); 
        getline(cin, dc);
        string lop; 
        getline(cin, lop);
        double gpa; cin >> gpa;
        string ma = to_string(i+1);
        while(ma.size()<4) ma = "0"+ma;
        Student s1(ma, ten, ns, dc, lop, gpa);
        s1.chuanHoa();
        v.push_back(s1);
    }
    sort(v.begin(), v.end(), cmp);
    for(Student x: v){
        x.in();
    }
    system("pause");
    return 0;
}

